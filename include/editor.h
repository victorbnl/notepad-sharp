#ifndef EDITOR_H
#define EDITOR_H

#include <QPlainTextEdit>

#include <QString>

#include "textfile.h"

class Editor : public QPlainTextEdit
{
    Q_OBJECT

public:
    Editor(QString path = "");
    QString title();

signals:
    void titleChanged(QString title);
    void closed();

public slots:
    bool save(bool askForPath = false);
    bool saveAs();
    void close();

private slots:
    void setAsModified();

private:
    TextFile mFile;
    bool mModified;
    void setModified(bool modified);
};

#endif // EDITOR_H