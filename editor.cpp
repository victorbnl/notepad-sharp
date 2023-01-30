#include "editor.h"

#include <QString>
#include <QFileDialog>
#include <QFile>
#include <QTextStream>

Editor::Editor()
{

}


void Editor::save()
{
    QString content = toPlainText();

    if (mPath == "")
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
}