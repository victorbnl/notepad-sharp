#include "editor.h"

#include <QFont>

#include <QString>
#include <QFileDialog>
#include <QFile>
#include <QTextStream>

#include "closedialog.h"

Editor::Editor(QString path)
{
    setFont(QFont("monospace"));

    mFile.setFileName(path);
    if (path != "")
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

void Editor::setAsModified()
{
    setModified(true);
    emit titleChanged(title());
}
