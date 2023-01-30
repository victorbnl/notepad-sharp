#include "editortabs.h"

EditorTabs::EditorTabs()
{

}

int EditorTabs::addEditor(Editor* editor)
{
    int index = addTab(editor, "New");
    setCurrentIndex(index);
    return index;
}
