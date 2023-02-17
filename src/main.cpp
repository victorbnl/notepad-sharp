#include "notepad.h"

#include <QApplication>
#include <QCommandLineParser>
#include <QStringList>
#include <QString>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    Notepad notepad;
    notepad.show();

    QCommandLineParser parser;
    parser.addPositionalArgument("file", "");
    parser.process(app);

    const QStringList args = parser.positionalArguments();
    if (args.count() > 0)
    {
        const QString file = args.at(0);
        notepad.openFile(file);
    }

    return app.exec();
}
