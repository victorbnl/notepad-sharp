#include "editor.h"

#include <QFont>

#include <QString>
#include <QFileDialog>
#include <QFile>
#include <QTextStream>

#include "closedialog.h"

Editor::Editor(QString path, QString content)
{
    setFont(QFont("monospace"));

    mPath = path;
    setPlainText(content);

    connect(this, &QPlainTextEdit::textChanged, this, &Editor::setModified);
}


bool Editor::save(bool askForPath)
{
    QString content = toPlainText();

    if (askForPath || mPath == "")
    {
        mPath = QFileDialog::getSaveFileName(nullptr, QString(), mPath);
        if (mPath == "")
            return false;
        emit pathChanged(mPath);
    }

    QFile file(mPath);
    file.open(QIODevice::WriteOnly);
    if (!file.isOpen())
        return false;

    QTextStream ofstream(&file);
    ofstream << content;

    file.close();

    mModified = false;

    return true;
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

void Editor::setModified()
{
    mModified = true;
}
