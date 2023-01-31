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
    TextFile mFile;
    bool mModified;
};

#endif // EDITOR_H
