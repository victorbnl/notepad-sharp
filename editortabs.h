#ifndef EDITORTABS_H
#define EDITORTABS_H

#include <QTabWidget>

#include <QString>

#include "editor.h"

class EditorTabs : public QTabWidget
{
    Q_OBJECT

public:
    EditorTabs(QWidget *parent = nullptr);
    int addEditor(Editor* editor);
    Editor* currentEditor();

public slots:
    void setTabTitle(QString path);
};

#endif // EDITORTABS_H
