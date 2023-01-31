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

private slots:
    void actionNew();
    void actionOpen();
    void actionSave();
    void actionSaveAs();
    void actionClose();

private:
    Ui::Notepad *ui;
    Editor* getCurrentEditor();
};
#endif // NOTEPAD_H
