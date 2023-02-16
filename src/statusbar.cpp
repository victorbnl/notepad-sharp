#include "statusbar.h"

#include "editor.h"

StatusBar::StatusBar(QWidget *parent)
{
    positionLabel = new QLabel(this);
    addWidget(positionLabel);
}


void StatusBar::setEditor(Editor* editor)
{
    mEditor = editor;
    if (mEditor != NULL)
        connect(mEditor, &QPlainTextEdit::cursorPositionChanged, this, &StatusBar::updateCursorPosition);
    updateCursorPosition();
}

void StatusBar::updateCursorPosition()
{
    if (mEditor == NULL)
    {
        positionLabel->setText("");
        return;
    }

    QTextCursor cursor = mEditor->textCursor();

    int line = cursor.blockNumber();
    int column = cursor.columnNumber();
    int position = cursor.position();

    positionLabel->setText(QString("Ln: %1  Col: %2  Pos: %3").arg(line).arg(column).arg(position));
}
