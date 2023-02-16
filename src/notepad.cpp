#include "notepad.h"
#include "ui_notepad.h"

#include <QAction>

#include <QFileDialog>
#include <QTextStream>

#include "editortabs.h"
#include "editor.h"
#include "statusbar.h"

Notepad::Notepad(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Notepad)
{
    ui->setupUi(this);

    EditorTabs* editorTabs = ui->editorTabs;
    connect(editorTabs, &EditorTabs::currentChanged, this, &Notepad::onCurrentEditorTabChanged);
}

Notepad::~Notepad()
{
    delete ui;
}

void Notepad::onCurrentEditorTabChanged(int /* index */)
{
    Editor* currentEditor = ui->editorTabs->currentEditor();
    StatusBar* statusBar = ui->statusbar;
    statusBar->setEditor(currentEditor);
}

void Notepad::actionNew()
{
    EditorTabs* editorTabs = (EditorTabs*)(ui->editorTabs);
    Editor* editor = new Editor();
    editorTabs->addEditor(editor);
}

void Notepad::actionOpen()
{
    QString path = QFileDialog::getOpenFileName();
    if (path == "")
        return;

    EditorTabs* editorTabs = (EditorTabs*)(ui->editorTabs);
    Editor* editor = new Editor(path);
    editorTabs->addEditor(editor);
}

void Notepad::actionSave()
{
    Editor* currentEditor = getCurrentEditor();
    if (currentEditor)
        currentEditor->save();
}

void Notepad::actionSaveAs()
{
    Editor* currentEditor = getCurrentEditor();
    if (currentEditor)
        currentEditor->saveAs();
}

void Notepad::actionClose()
{
    Editor* currentEditor = getCurrentEditor();
    if (currentEditor)
        currentEditor->close();
}

Editor* Notepad::getCurrentEditor()
{
    return ui->editorTabs->currentEditor();
}
