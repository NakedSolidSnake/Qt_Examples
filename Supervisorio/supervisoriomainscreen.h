#ifndef SUPERVISORIOMAINSCREEN_H
#define SUPERVISORIOMAINSCREEN_H

#include <QMainWindow>
#include "filemanager.h"

namespace Ui {
class SupervisorioMainScreen;
}

class SupervisorioMainScreen : public QMainWindow
{
    Q_OBJECT

public:
    explicit SupervisorioMainScreen(QWidget *parent = 0);
    ~SupervisorioMainScreen();

private:
    Ui::SupervisorioMainScreen *ui;

    FileManager *file;
};

#endif // SUPERVISORIOMAINSCREEN_H
