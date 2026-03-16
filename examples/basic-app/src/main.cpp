#include <QCoreApplication>
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);
    
    qInfo() << "Qt CMake Tools - Basic Console Application";
    qInfo() << "============================================";
    qInfo() << "Qt Version:" << QT_VERSION_STR;
    qInfo() << "This is a simple console application demonstrating";
    qInfo() << "the qt-cmake-tools project structure.";
    
    return 0;
}
