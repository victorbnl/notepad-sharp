#include "textfile.h"

#include <QIODevice>

TextFile::TextFile(const QString &name, QObject *parent)
    : QFile{name, parent}
{

}

QString TextFile::content()
{
    open(QIODevice::ReadOnly);
    QTextStream ifstream(this);
    QString content = ifstream.readAll();
    close();
    return content;
}

bool TextFile::write(QString content)
{
    open(QIODevice::WriteOnly);
    if (!isOpen())
        return false;
    QTextStream ofstream(this);
    ofstream << content;
    close();
    return true;
}
