#include "mainwindow.h"
#include "ui_mainwindow.h"
//#include <QPixmap>
//#include <QTimer>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
//    const QString textSrc("Hello World. this is some demo text"
//                          ". This doesn't mean much, but we will test the "
//                          "label widget and the text browser widget.");

//    ui->label->setText(textSrc);
//    ui->textBrowser->setText(textSrc);

//    QPixmap pic;
//    pic.load("/home/solid/Qt Projects/pool.jpg");
//    ui->label->setPixmap(pic);

//    QTimer *timer = new QTimer(this);
//    timer->setInterval(500);

//    connect(timer, &QTimer::timeout, this, &MainWindow::onTimeout);

//    timer->start();

    plainText = true;

    connect(ui->comboBox, &QComboBox::currentTextChanged, this, &MainWindow::onComboBoxChanged);
    connect(ui->textEdit, &QTextEdit::textChanged, this, &MainWindow::updateTextBrowser);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onTimeout()
{
//    int value = ui->progressBar->value();
//    if(value >= 100)
//        return ;

//    value += 1;
//    ui->progressBar->setValue(value);
}

void MainWindow::updateTextBrowser()
{
    QString text = ui->textEdit->document()->toPlainText();
    if(plainText)
        ui->textBrowser->setPlainText(text);
    else
        ui->textBrowser->setHtml(text);
}

void MainWindow::onComboBoxChanged(const QString &text)
{
    plainText = (text == "Plain");
    updateTextBrowser();
}
