#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "mytoolbutton.h"
#include <QDebug>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    // ui->mainToolBar->setFixedHeight(100);

    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(timerUpdate()) );
    timer->start(5);

    MyToolButton *qbutton = new MyToolButton;
    qbutton->setLedColor(QColor(255,0,0,255));
    qbutton->setText("Demo Text");
    qbutton->setText2("Demo Text Below");
    ui->mainToolBar->addWidget(qbutton);

    MyToolButton *button = new MyToolButton;
    button->setLedColor(QColor(Qt::green));
    ui->mainToolBar->addWidget(button);

    MyToolButton *button2 = new MyToolButton;
    button2->setLedColor(QColor(Qt::yellow));
    ui->mainToolBar->addWidget(button2);

    MyToolButton *button3 = new MyToolButton;
    button3->setLedColor(QColor(Qt::gray));
    ui->mainToolBar->addWidget(button3);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::timerUpdate()
{
    ui->mainToolBar->repaint();
}


/*
bool MainWindow::eventFilter(QObject *object, QEvent *e)
{
    if (object == target && event->type() == QEvent::MouseButtonPress) {
             QKeyEvent *keyEvent = static_cast<QKeyEvent *>(event);
             if (keyEvent->key() == Qt::Key_Escape) {
                 // Special tab handling
                 return true;

                 QMouseEvent *mouseEvent = static_cast<QMouseEvent *>(event);
                 if (mouseEvent == Qt::Key_Escape) {
                     // Special tab handling
                     return true;
             } else
                 return false;
         }
         return false;
}
*/
