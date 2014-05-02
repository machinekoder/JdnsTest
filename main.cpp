#include <QApplication>
#include <QQmlApplicationEngine>
#include <QtQml>
#include "dnstester.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    qmlRegisterType<DnsTester>("Test", 1, 0, "DnsTester");

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:///main.qml")));

    return app.exec();
}
