#include "authform.h"
#include "ui_authform.h"


AuthForm::AuthForm(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AuthForm)
{
    ui->setupUi(this);
    ui->lineEdit->setEchoMode(QLineEdit::Password);
}

// обработчик кнопки ок
void AuthForm::on_buttonBox_accepted()
{
    // создаем главное окно и разворачиваем его на весь экран
    MainWindow* w = new MainWindow;
    w->showMaximized();
}

// кнопка отмены закрывает соединение с базой и закрывает окно
void AuthForm::on_buttonBox_rejected()
{
    // закріваем базу данніх
    //Connect->getDB().close();
    // удаляем соединение
    //QSqlDatabase::removeDatabase();
}

// если нажали ввод на поле пользователя
void AuthForm::on_lineEdit_2_editingFinished()
{
    emit accepted();
}

// если нажали ввод на поле пароля
void AuthForm::on_lineEdit_editingFinished()
{
    emit accepted();
}

// флажок показать пароль
void AuthForm::on_checkBox_clicked()
{
    if( ui->checkBox->isChecked() )
    {
        ui->lineEdit->setEchoMode(QLineEdit::Normal);
    }
    else{
        ui->lineEdit->setEchoMode(QLineEdit::Password);
    }
}

AuthForm::~AuthForm()
{
    delete ui;
}
