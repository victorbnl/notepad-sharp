#ifndef NOTEPAD_H
#define NOTEPAD_H

#include <QMainWindow>

#include "editor.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Notepad; }
QT_END_NAMESPACE

class Notepad : public QMainWindow
{
    Q_OBJECT

public:
    Notepad(QWidget *parent = nullptr);
    ~Notepad();
    void openFile(QString path);

private slots:
    void onCurrentEditorTabChanged(int index);

    void actionNew();
    void actionOpen();
    void actionSave();
    void actionSaveAs();
    void actionClose();

    void actionCut();
    void actionCopy();
    void actionPaste();

    void actionUndo();
    void actionRedo();

    void actionSetLineWrap(bool enabled);

private:
    Ui::Notepad *ui;
    Editor* getCurrentEditor();
};
#endif // NOTEPAD_H
