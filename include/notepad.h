#ifndef NOTEPAD_H
#define NOTEPAD_H

#include <vector>
#include <QMetaObject>
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
    void closeEvent(QCloseEvent *event);
    void openFile(QString path);

private slots:
    void onCurrentEditorTabChanged(int index);
    void setTitle(QString title);
    void actionNew();
    void actionOpen();

private:
    Ui::Notepad *ui;
    std::vector<QMetaObject::Connection> currentEditorConnections;
};
#endif // NOTEPAD_H
