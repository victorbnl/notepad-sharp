#ifndef FINDFORM_H
#define FINDFORM_H

#include <QWidget>

#include "editor.h"

namespace Ui {
class FindForm;
}

class FindForm : public QWidget
{
    Q_OBJECT

public:
    explicit FindForm(Editor* editor, QWidget *parent = nullptr);
    ~FindForm();

signals:
    void close();

private slots:
    void find();

private:
    void showEvent(QShowEvent * event);
    void keyPressEvent(QKeyEvent *event);
    Ui::FindForm *ui;
    Editor* mEditor;
};

#endif // FINDFORM_H
