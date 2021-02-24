#include "recorder.h"
#include "ui_recorder.h"

Recorder::Recorder(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Recorder)
{
    ui->setupUi(this);
}

Recorder::~Recorder()
{
    delete ui;
}
