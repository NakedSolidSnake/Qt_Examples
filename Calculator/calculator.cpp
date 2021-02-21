#include "calculator.h"
#include "ui_calculator.h"

double calcVal = 0.0;
bool divTrigger = false;
bool multTrigger = false;
bool addTrigger = false;
bool subTrigger = false;

Calculator::Calculator(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Calculator)
{
    ui->setupUi(this);

    ui->Display->setText(QString::number(calcVal));
    QPushButton *numButtons[10];

    for(int i = 0; i < 10; ++i)
    {
        QString butName = "Button_" + QString::number(i);
        numButtons[i] = Calculator::findChild<QPushButton *>(butName);
        connect(numButtons[i], SIGNAL(released()), this, SLOT(NumPressed()));
    }

    connect(ui->Add, SIGNAL(pressed()), this, SLOT(MathButtonPressed()));
    connect(ui->Subtract, SIGNAL(pressed()), this, SLOT(MathButtonPressed()));
    connect(ui->Multiply, SIGNAL(pressed()), this, SLOT(MathButtonPressed()));
    connect(ui->Divide, SIGNAL(pressed()), this, SLOT(MathButtonPressed()));


    connect(ui->Change_Sign, SIGNAL(pressed()), this, SLOT(ChangeNumberSign()));
    connect(ui->Equals, SIGNAL(pressed()), this, SLOT(EqualButton()));

    connect(ui->Clear, SIGNAL(pressed()), this, SLOT(ClearCalculator()));



}

Calculator::~Calculator()
{
    delete ui;
}

//  Slots

void Calculator::NumPressed()
{
    QPushButton *button = (QPushButton *)sender();
    QString butval = button->text();
    QString displayVal = ui->Display->text();

    if((displayVal.toDouble() == 0) || (displayVal.toDouble() == 0.0)){
        ui->Display->setText(butval);
    }
    else{
        QString newVal = displayVal + butval;
        double dbNewVal = newVal.toDouble();

        ui->Display->setText(QString::number(dbNewVal, 'g', 16));
    }

}

void Calculator::MathButtonPressed()
{
    divTrigger = false;
    multTrigger = false;
    addTrigger = false;
    subTrigger = false;

    QString displayVal = ui->Display->text();
    calcVal = displayVal.toDouble();

    QPushButton *button = (QPushButton *)sender();

    QString butVal = button->text();

    if(QString::compare(butVal, "/", Qt::CaseInsensitive) == 0)
    {
        divTrigger = true;
    }
    else if(QString::compare(butVal, "*", Qt::CaseInsensitive) == 0)
    {
        multTrigger = true;
    }

    else if(QString::compare(butVal, "+", Qt::CaseInsensitive) == 0)
    {
        addTrigger = true;
    }

    else if(QString::compare(butVal, "-", Qt::CaseInsensitive) == 0)
    {
        subTrigger = true;
    }

    ui->Display->setText("");
}

void Calculator::EqualButton()
{
    double solution = 0.0;
    QString displayVal = ui->Display->text();
    double dbDisplayVal = displayVal.toDouble();

    if(addTrigger || subTrigger || multTrigger || divTrigger)
    {
        if(addTrigger)
        {
            solution = calcVal + dbDisplayVal;
        }

        else if(subTrigger)
        {
            solution = calcVal - dbDisplayVal;
        }

        else if(multTrigger)
        {
            solution = calcVal * dbDisplayVal;
        }

        else
        {
            solution = calcVal / dbDisplayVal;
        }
    }
    ui->Display->setText(QString::number(solution));
}

void Calculator::ChangeNumberSign()
{
    QString displayVal = ui->Display->text();
    double dbDisplayValue = displayVal.toDouble();
    dbDisplayValue = dbDisplayValue * (-1.0);
    ui->Display->setText(QString::number(dbDisplayValue));
}

void Calculator::ClearCalculator()
{
    ui->Display->setText("");
    calcVal = 0.0;
    addTrigger = false;
    subTrigger = false;
    multTrigger = false;
    divTrigger = false;

}
