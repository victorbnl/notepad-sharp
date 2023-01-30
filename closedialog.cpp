#include "closedialog.h"
#include "ui_closedialog.h"

CloseDialog::CloseDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CloseDialog)
{
    ui->setupUi(this);
}

CloseDialog::~CloseDialog()
{
    delete ui;
}

CloseAction CloseDialog::getAction()
{
    return mAction;
}


void CloseDialog::save()
{
    mAction = CloseAction::SAVE;
    accept();
}

void CloseDialog::discard()
{
    mAction = CloseAction::DISCARD;
    accept();
}

void CloseDialog::cancel()
{
    reject();
}
