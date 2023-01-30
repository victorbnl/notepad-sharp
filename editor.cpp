#include "editor.h"

#include <QFont>

#include <QString>
#include <QFileDialog>
#include <QFile>
#include <QTextStream>

#include "closedialog.h"

Editor::Editor()
{
    setFont(QFont("monospace"));

    connect(this, &QPlainTextEdit::textChanged, this, &Editor::setModified);
}


void Editor::save(bool askForPath)
{
    QString content = toPlainText();

    if (askForPath || mPath == "")
    {
        mPath = QFileDialog::getSaveFileName(nullptr, QString(), mPath);
        if (mPath == "")
            return;
        emit pathChanged(mPath);
    }

    QFile file(mPath);
    file.open(QIODevice::WriteOnly);
    if (!file.isOpen())
        return;

    QTextStream ofstream(&file);
    ofstream << content;

    file.close();

    mModified = false;
}

void Editor::saveAs()
{
    save(true);
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
                    save();
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
