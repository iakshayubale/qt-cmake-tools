#include "mainwindow.h"
#include <QVBoxLayout>
#include <QLabel>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setupUI();
    setWindowTitle("Qt CMake Tools - Widget Application");
    resize(400, 300);
}

MainWindow::~MainWindow()
{
}

void MainWindow::setupUI()
{
    QWidget *centralWidget = new QWidget(this);
    QVBoxLayout *layout = new QVBoxLayout(centralWidget);
    
    QLabel *titleLabel = new QLabel("Qt CMake Tools Widget Example", this);
    titleLabel->setStyleSheet("font-size: 16px; font-weight: bold;");
    layout->addWidget(titleLabel);
    
    QLabel *infoLabel = new QLabel(
        "This is a demonstration of building a Qt Widget application\n"
        "using the qt-cmake-tools CMake utilities.\n\n"
        "Click the button below to see it in action.",
        this
    );
    layout->addWidget(infoLabel);
    
    m_clickButton = new QPushButton("Click Me!", this);
    connect(m_clickButton, &QPushButton::clicked, this, &MainWindow::onButtonClicked);
    layout->addWidget(m_clickButton);
    
    layout->addStretch();
    
    setCentralWidget(centralWidget);
}

void MainWindow::onButtonClicked()
{
    qInfo() << "Button clicked! Qt CMake Tools widget example is working.";
}
