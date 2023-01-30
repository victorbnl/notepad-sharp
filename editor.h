#ifndef EDITOR_H
#define EDITOR_H

#include <QPlainTextEdit>

#include <QString>

class Editor : public QPlainTextEdit
{
    Q_OBJECT

public:
    Editor();

signals:
    void pathChanged(QString newPath);

public slots:
    void save();

private:
    QString mPath;
};

#endif // EDITOR_H
