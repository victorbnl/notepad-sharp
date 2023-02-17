#ifndef STATUSBAR_H
#define STATUSBAR_H

#include <QStatusBar>
#include <QObject>

#include <QLabel>

#include "editor.h"

class StatusBar : public QStatusBar
{
    Q_OBJECT

public:
    StatusBar(QWidget *parent = nullptr);
    void setEditor(Editor* editor);

public slots:
    void updateStats();
    void updateCursorPosition();

private:
    Editor* mEditor;

    QLabel* statsLabel;
    QLabel* positionLabel;
};

#endif // STATUSBAR_H
