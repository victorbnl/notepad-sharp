#ifndef TEXTFILE_H
#define TEXTFILE_H

#include <QFile>

#include <QString>
#include <QTextStream>

class TextFile : public QFile
{
    Q_OBJECT

public:
    explicit TextFile(const QString &name = "", QObject *parent = nullptr);
    QString content();
    bool write(QString content);
};

#endif // TEXTFILE_H
