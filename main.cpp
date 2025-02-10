#include <QGuiApplication>
#include <QQmlApplicationEngine>

int main(int argc, char *argv[]) {
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;

    const QUrl url(QStringLiteral("qrc:/qml/Main.qml")); // Path to QML inside the resource file
    engine.load(url);

    if (engine.rootObjects().isEmpty()) {
        return -1;  // Ensure that the app exits if no root object is found
    }

    return app.exec();
}
