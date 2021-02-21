#include "supervisoriomainscreen.h"
#include "ui_supervisoriomainscreen.h"
#include <QDebug>

SupervisorioMainScreen::SupervisorioMainScreen(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SupervisorioMainScreen)
{
    ui->setupUi(this);
    file = new FileManager("a.txt");
    file->Write("Test");

    QString receive;
    file->Read(receive);
    qDebug() << receive;
}

SupervisorioMainScreen::~SupervisorioMainScreen()
{
    delete ui;
}
