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


void Notepad::onCurrentEditorTabChanged(int /* index */)
{
    Editor* currentEditor = ui->editorTabs->currentEditor();

    StatusBar* statusBar = ui->statusbar;
    statusBar->setEditor(currentEditor);

    for (QMetaObject::Connection connection : currentEditorConnections)
        disconnect(connection);
    currentEditorConnections.push_back(connect(ui->actionSave, &QAction::triggered, currentEditor, &Editor::save));
    currentEditorConnections.push_back(connect(ui->actionSaveAs, &QAction::triggered, currentEditor, &Editor::saveAs));
    currentEditorConnections.push_back(connect(ui->actionClose, &QAction::triggered, currentEditor, &Editor::close));
    currentEditorConnections.push_back(connect(ui->actionCut, &QAction::triggered, currentEditor, &Editor::cut));
    currentEditorConnections.push_back(connect(ui->actionCopy, &QAction::triggered, currentEditor, &Editor::copy));
    currentEditorConnections.push_back(connect(ui->actionPaste, &QAction::triggered, currentEditor, &Editor::paste));
    currentEditorConnections.push_back(connect(ui->actionUndo, &QAction::triggered, currentEditor, &Editor::undo));
    currentEditorConnections.push_back(connect(ui->actionRedo, &QAction::triggered, currentEditor, &Editor::redo));
    currentEditorConnections.push_back(connect(ui->actionToggleLineWrap, &QAction::triggered, currentEditor, &Editor::setLineWrap));
    currentEditorConnections.push_back(connect(ui->actionZoomIn, &QAction::triggered, currentEditor, [currentEditor]{ currentEditor->zoomIn(2); }));
    currentEditorConnections.push_back(connect(ui->actionZoomOut, &QAction::triggered, currentEditor, [currentEditor]{ currentEditor->zoomOut(2); }));

    bool currentEditorLineWrapEnabled;
    if (currentEditor->lineWrapMode() == QPlainTextEdit::LineWrapMode::WidgetWidth)
        currentEditorLineWrapEnabled = true;
    else
        currentEditorLineWrapEnabled = false;
    ui->actionToggleLineWrap->setChecked(currentEditorLineWrapEnabled);
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
