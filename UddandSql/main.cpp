#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include "name.h"
#include<QQmlContext>
static const QString path="uddand.db";

int main(int argc, char *argv[])
{

    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);


//    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    name db(path);
    if(db.isOpen())
    {
        db.createTable();

//        db.removeAllPersons();
        db.printAllPersons();
    }

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    name sqldb;
    engine.rootContext()->setContextProperty("testing",&sqldb);
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
