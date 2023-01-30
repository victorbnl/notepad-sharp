#ifndef CLOSEDIALOG_H
#define CLOSEDIALOG_H

#include <QDialog>

namespace Ui {
class CloseDialog;
}

enum class CloseAction
{
    SAVE,
    DISCARD
};

class CloseDialog : public QDialog
{
    Q_OBJECT

public:
    explicit CloseDialog(QWidget *parent = nullptr);
    ~CloseDialog();
    CloseAction getAction();

private slots:
    void save();
    void discard();
    void cancel();

private:
    Ui::CloseDialog *ui;
    CloseAction mAction;
};

#endif // CLOSEDIALOG_H
