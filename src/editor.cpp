#include "editor.h"

#include <QFont>

#include <QString>
#include <QFileDialog>
#include <QFile>
#include <QTextStream>

#include <QPrinter>
#include <QPrintDialog>

#include "closedialog.h"

Editor::Editor(QString path)
{
    setFrameStyle(QFrame::NoFrame);
    setFont(QFont("monospace"));

    mFile.setFileName(path);
    if (mFile.exists())
        setPlainText(mFile.content());
    mModified = false;

    connect(this, &QPlainTextEdit::textChanged, this, &Editor::setAsModified);
}

QString Editor::title()
{
    QFileInfo fileInfo(mFile.fileName());
    QString fileName = fileInfo.fileName();
    if (fileName == "")
        fileName = "Untitled";

    QString title = "";
    if (mModified)
        title += "* ";
    title += fileName;

    return title;
}

void Editor::find(QString text)
{
    QTextCursor cursor = textCursor();

    const QString string = toPlainText();
    int pos = string.indexOf(text, cursor.position());
    if (pos == -1)
    {
        pos = string.indexOf(text);
        if (pos == -1)
        {
            return;
        }
    }

    cursor.setPosition(pos, QTextCursor::MoveAnchor);
    cursor.setPosition(pos+text.length(), QTextCursor::KeepAnchor);

    setTextCursor(cursor);
}


void Editor::setModified(bool modified)
{
    mModified = modified;
    emit titleChanged(title());
}


bool Editor::save(bool askForPath)
{
    QString content = toPlainText();

    QString path = mFile.fileName();
    if (askForPath || path == "")
    {
        path = QFileDialog::getSaveFileName();
        if (path == "")
            return false;
        mFile.setFileName(path);
        emit titleChanged(title());
    }

    bool success = mFile.write(content);
    if (success)
        setModified(false);

    return success;
}

bool Editor::saveAs()
{
    return save(true);
}

void Editor::close()
{
    if (mModified)
    {
        CloseDialog dialog;
        dialog.setModal(true);
        if (dialog.exec() == QDialog::Accepted)
        {
            switch (dialog.getAction())
            {
                case CloseAction::SAVE:
                    if (save())
                        emit closed();
                    break;

                case CloseAction::DISCARD:
                    emit closed();
                    break;
            }
        }
    }
    else
    {
        emit closed();
    }
}

void Editor::print()
{
    QPrinter printer;
    QPrintDialog *dialog = new QPrintDialog(&printer, this);
    if (dialog->exec() != QDialog::Accepted)
        return;

    QPlainTextEdit::print(&printer);
}

void Editor::setLineWrap(bool enabled)
{
    if (enabled)
        setLineWrapMode(QPlainTextEdit::LineWrapMode::WidgetWidth);
    else
        setLineWrapMode(QPlainTextEdit::LineWrapMode::NoWrap);
}

void Editor::setAsModified()
{
    setModified(true);
    emit titleChanged(title());
}
