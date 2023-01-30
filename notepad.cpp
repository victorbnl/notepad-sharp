#include "notepad.h"
#include "ui_notepad.h"

#include <QAction>

#include "editortabs.h"
#include "editor.h"

Notepad::Notepad(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Notepad)
{
    ui->setupUi(this);

    EditorTabs* editorTabs = (EditorTabs*)(ui->editorTabs);
    connect(editorTabs, &EditorTabs::currentChanged, this, &Notepad::onCurrentEditorTabChanged);
}

Notepad::~Notepad()
{
    delete ui;
}


void Notepad::onCurrentEditorTabChanged()
{
    EditorTabs* editorTabs = (EditorTabs*)ui->editorTabs;
    Editor* currentEditor = editorTabs->currentEditor();
    connect(ui->actionSave, &QAction::triggered, currentEditor, &Editor::save);
    connect(ui->actionSaveAs, &QAction::triggered, currentEditor, &Editor::saveAs);
}


void Notepad::actionNew()
{
    EditorTabs* editorTabs = (EditorTabs*)(ui->editorTabs);
    Editor* editor = new Editor();
    editorTabs->addEditor(editor);
}
