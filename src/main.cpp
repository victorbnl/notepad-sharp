#include "notepad.h"

#include <QApplication>

#include <QLocale>
#include <QTranslator>

#include <QCommandLineParser>
#include <QStringList>
#include <QString>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QTranslator translator;
    const QStringList uiLanguages = QLocale::system().uiLanguages();
    for (const QString &locale : uiLanguages) {
        const QString baseName = QLocale(locale).name();
        if (translator.load(":i18n/languages/" + baseName)) {
            app.installTranslator(&translator);
            break;
        }
    }

    Notepad notepad;

    QCommandLineParser parser;
    parser.addPositionalArgument("file", "");
    parser.process(app);

    const QStringList args = parser.positionalArguments();
    if (args.count() > 0)
    {
        const QString file = args.at(0);
        notepad.openFile(file);
    }

    notepad.show();
    return app.exec();
}
