#include "editortabs.h"

#include <QFileInfo>

#include "editor.h"

EditorTabs::EditorTabs()
{

}

int EditorTabs::addEditor(Editor* editor)
{
    int index = addTab(editor, "Untitled");
    setCurrentIndex(index);

    connect(editor, &Editor::pathChanged, this, &EditorTabs::setTabTitle);

    return index;
}

Editor* EditorTabs::currentEditor()
{
    return (Editor*)currentWidget();
}


void EditorTabs::setTabTitle(QString path)
{
    QFileInfo fileInfo(path);
    QString filename = fileInfo.fileName();
    if (filename == "")
        filename = "Untitled";

    int editorIndex = indexOf((QWidget*)sender());
    setTabText(editorIndex, filename);
}
