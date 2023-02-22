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


void Notepad::openFile(QString path)
{
    EditorTabs* editorTabs = (EditorTabs*)(ui->editorTabs);
    Editor* editor = new Editor(path);
    editorTabs->addEditor(editor);
}


Editor* Notepad::getCurrentEditor()
{
    return ui->editorTabs->currentEditor();
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

    openFile(path);
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

void Notepad::actionCut()
{
    Editor* currentEditor = getCurrentEditor();
    if (currentEditor)
        currentEditor->cut();
}

void Notepad::actionCopy()
{
    Editor* currentEditor = getCurrentEditor();
    if (currentEditor)
        currentEditor->copy();
}

void Notepad::actionPaste()
{
    Editor* currentEditor = getCurrentEditor();
    if (currentEditor)
        currentEditor->paste();
}

void Notepad::actionUndo()
{
    Editor* currentEditor = getCurrentEditor();
    if (currentEditor)
        currentEditor->undo();
}

void Notepad::actionRedo()
{
    Editor* currentEditor = getCurrentEditor();
    if (currentEditor)
        currentEditor->redo();
}

void Notepad::actionSetLineWrap(bool enabled)
{
    Editor* currentEditor = getCurrentEditor();
    if (currentEditor)
    {
        QPlainTextEdit::LineWrapMode currentMode = currentEditor->lineWrapMode();
        if (currentMode == QPlainTextEdit::LineWrapMode::WidgetWidth)
            currentEditor->setLineWrapMode(QPlainTextEdit::LineWrapMode::NoWrap);
        else
            currentEditor->setLineWrapMode(QPlainTextEdit::LineWrapMode::WidgetWidth);
    }
}
