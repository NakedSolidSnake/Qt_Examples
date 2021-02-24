#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    bool plainText;

private slots:
    void onTimeout();
    void updateTextBrowser();
    void onComboBoxChanged(const QString& text);
};

#endif // MAINWINDOW_H
