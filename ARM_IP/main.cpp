#include "login_password.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    srand(time(NULL));
    login_password w;
    w.show();
    return a.exec();
}
