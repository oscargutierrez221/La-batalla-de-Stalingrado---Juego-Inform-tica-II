#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "jugador.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QGraphicsScene *escena = new QGraphicsScene(this);
    escena->setSceneRect(0,0,800,600);
    ui->graphicsView->setScene(escena);
    posicion_jugador *principal = new posicion_jugador(ui->graphicsView);
    escena->addItem(principal);
    principal->setPos(200,200);
}

MainWindow::~MainWindow()
{
    delete ui;
}
