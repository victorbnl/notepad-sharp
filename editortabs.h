#ifndef EDITORTABS_H
#define EDITORTABS_H

#include <QTabWidget>

#include "editor.h"

class EditorTabs : public QTabWidget
{
    Q_OBJECT

public:
    EditorTabs();
    int addEditor(Editor* editor);
};

#endif // EDITORTABS_H
