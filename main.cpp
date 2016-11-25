#include <QApplication>
#include "mainwindow.h"
#include "authform.h"
#include "connect.h"
#include <QtSql>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Connect c;

    // создаем форму авторизации а она открывает основное окно
    AuthForm f;
    // показываем форму авторизации
    f.show();

    return a.exec();
}

