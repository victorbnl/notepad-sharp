#include "findform.h"
#include "ui_findform.h"

#include <QPushButton>

FindForm::FindForm(Editor* editor, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FindForm)
{
    ui->setupUi(this);
    mEditor = editor;
}

FindForm::~FindForm()
{
    delete ui;
}

void FindForm::showEvent(QShowEvent *event)
{
    ui->textEdit->setFocus();
    event->accept();
}

void FindForm::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Escape)
        emit close();
}


void FindForm::find()
{
    const QString text = ui->textEdit->text();
    mEditor->find(text);
}
