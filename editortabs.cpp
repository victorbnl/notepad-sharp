#include "editortabs.h"

#include <QFileInfo>

#include "editor.h"

EditorTabs::EditorTabs(QWidget *parent)
{

}

int EditorTabs::addEditor(Editor* editor)
{
    int index = addTab(editor, "Untitled");
    setCurrentIndex(index);

    connect(editor, &Editor::titleChanged, this, &EditorTabs::setTabTitle);
    connect(editor, &Editor::closed, this, &EditorTabs::removeEditor);

    return index;
}

Editor* EditorTabs::currentEditor()
{
    return (Editor*)currentWidget();
}


void EditorTabs::setTabTitle(QString title)
{
    int editorIndex = indexOf((QWidget*)sender());
    setTabText(editorIndex, title);
}

void EditorTabs::closeEditorAt(int index)
{
    ((Editor*)widget(index))->close();
}

void EditorTabs::removeEditor()
{
    int editorIndex = indexOf((QWidget*)sender());
    removeTab(editorIndex);
}
