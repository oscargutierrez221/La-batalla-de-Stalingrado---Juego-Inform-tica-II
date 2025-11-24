#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "jugador.h"
#include "niveles.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QGraphicsScene *escena = new QGraphicsScene(this);
    ui->graphicsView->setScene(escena);
    this->setWindowTitle("La Batalla de Stalingrado");

    niveles *nivel = new niveles(escena);
    nivel->cargarNivel(1);
    
    posicion_jugador *principal = new posicion_jugador(ui->graphicsView);
    escena->addItem(principal);
    
    principal->setPos(100, 430);
    principal->setFocus();
}

MainWindow::~MainWindow()
{
    delete ui;
}
