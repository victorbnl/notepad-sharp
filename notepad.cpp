#include "notepad.h"
#include "ui_notepad.h"

#include <QAction>

#include <QFileDialog>
#include <QTextStream>

#include "editortabs.h"
#include "editor.h"

Notepad::Notepad(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Notepad)
{
    ui->setupUi(this);
}

Notepad::~Notepad()
{
    delete ui;
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

    QFile file(path);
    if (!file.open(QFile::ReadOnly | QFile::Text))
        return;

    QTextStream ifstream(&file);
    QString content = ifstream.readAll();

    EditorTabs* editorTabs = (EditorTabs*)(ui->editorTabs);
    Editor* editor = new Editor(path, content);
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
