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
    void closed();

public slots:
    void save(bool askForPath = false);
    void saveAs();
    void close();

private slots:
    void setModified();

private:
    QString mPath;
    bool mModified;
};

#endif // EDITOR_H
