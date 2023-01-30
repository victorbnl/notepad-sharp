#ifndef EDITOR_H
#define EDITOR_H

#include <QPlainTextEdit>

#include <QString>

class Editor : public QPlainTextEdit
{
    Q_OBJECT

public:
    Editor(QString path = "", QString content = "");

signals:
    void pathChanged(QString newPath);
    void closed();

public slots:
    bool save(bool askForPath = false);
    bool saveAs();
    void close();

private slots:
    void setModified();

private:
    QString mPath;
    bool mModified;
};

#endif // EDITOR_H
