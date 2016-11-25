#include "addclient.h"
#include "ui_addclient.h"

AddClient::AddClient(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddClient)
{
    ui->setupUi(this);
    ui->lineEdit_boss_phon->setInputMask("(999)-999-99-99");
    ui->lineEdit_fin_phon->setInputMask("(999)-999-99-99");
    ui->lineEdit_deliv_phon->setInputMask("(999)-999-99-99");

    ui->lineEdit_deposit->setInputMask("999999,99");

    firma = "";
    addr = "";
    boss_name = "";
    boss_phon = "";
    fin_name = "";
    fin_phon = "";
    deliv_name = "";
    deliv_phon = "";
    deliv_addr = "";
    deposit = 0;
}

AddClient::~AddClient()
{
    delete ui;
}

void AddClient::on_buttonBox_accepted()
{


    firma = ui->lineEdit_firma->text();
    addr = ui->lineEdit_addr->text();
    boss_name = ui->lineEdit_boss_name->text();
    boss_phon = ui->lineEdit_boss_phon->text();
    fin_name = ui->lineEdit_fin_name->text();
    fin_phon = ui->lineEdit_fin_phon->text();
    deliv_name = ui->lineEdit_deliv_name->text();
    deliv_phon = ui->lineEdit_deliv_phon->text();
    deliv_addr = ui->lineEdit_deliv_addr->text();
    deposit = ui->lineEdit_deposit->text().toInt();

    //
    if((firma=="") || (boss_name=="") || (boss_phon==""))
    {
        QMessageBox mes_empty;
        QString str_mes = trUtf8("Поля: Фирма, Дирректор, Тел.Дирр. не могут быть пустыми !!!");
        mes_empty.setText(str_mes);
        mes_empty.show();
        mes_empty.exec();
    }
    else
    {
        QSqlQuery *query = new QSqlQuery();
        // создаем таблицу клиентов
        query->prepare("INSERT INTO clients ( "
                "firma, addr, boss_name, boss_phon, fin_name, fin_phon, "
                "deliv_name, deliv_phon, deliv_addr, deposit) "
                "VALUES ("
                ":firma, :addr, :boss_name, :boss_phon, :fin_name, :fin_phon, "
                ":deliv_name, :deliv_phon, :deliv_addr, :deposit )");

        //query->prepare(str_insert);
        //query->bindValue(":pk", 12);
        query->bindValue(":firma", firma);
        query->bindValue(":addr", addr);
        query->bindValue(":boss_name", boss_name);
        query->bindValue(":boss_phon", boss_phon);
        query->bindValue(":fin_name", fin_name);
        query->bindValue(":fin_phon", fin_phon);
        query->bindValue(":deliv_name", deliv_name);
        query->bindValue(":deliv_phon", deliv_phon);
        query->bindValue(":deliv_addr", deliv_addr);
        query->bindValue(":deposit", deposit);

        bool b = query->exec();
        if (!b) {
            qDebug() << "Not INSERT data";
            qDebug() << query->lastError().text();
        };
    };
    // генерим сигнал
    emit UpdateAllTbl();
}



void AddClient::on_buttonBox_rejected()
{
    //exec();
}
