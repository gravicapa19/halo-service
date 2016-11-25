#include "connect.h"


Connect::Connect(QObject *parent) :
    QObject(parent)
{

    // получаем путь к исполняемому файлу
    strdb = QCoreApplication::applicationDirPath();
    // добавляем название файла БД
    strdb.append("/service.sqlite");

    // проверяем наличие файла бд
    bool file;
    if ( ! QFile::exists(strdb) ) {
        file = 0;
    }else{
        file = 1;
    };

    // создаем подключение
    db = QSqlDatabase::addDatabase("QSQLITE");
    //db.setHostName("/service.db");
    db.setDatabaseName(strdb);
    //db.setUserName("admin");
    //db.setPassword("admin");
    bool ok = db.open();

    // если есть ошибки віводим
    if (!ok) {
          qDebug() << db.lastError().text();
          QMessageBox a;
          QString str = db.lastError().text();
          str.append(strdb);
          a.setText(str);
          a.exec();
    }
    else
    {
        qDebug() << "db connect OK!" << endl;
    }

    // если файла раньше небыло
    if(!file)
    {
        Connect::CreateAllTable();
    }
}

// create all table first connec
void Connect::CreateAllTable()
{
    QSqlQuery *query = new QSqlQuery(db);

    // создаем таблицу юзеров
    QString str = "CREATE TABLE users ("
                  "pk INTEGER PRIMARY KEY NOT NULL, "
                  "user TEXT, "
                  "password TEXT, "
                  "locked INTEGER"
                  ");";
    bool b = query->exec(str);
    if (!b) {
        qDebug() << "Not create table users" << endl;
        qDebug() << query->lastError().text();
    }
    else
    {
        qDebug() << "Create table users OK!" << endl;
    }

    // заполняем одним юзером
    QString str_insert = "INSERT INTO users(pk, user, password, locked) "
                         "VALUES (1, 'admin', 'admin', 0);";

    b = query->exec(str_insert);
    if (!b) {
        qDebug() << "Not INSERT data";
        qDebug() << query->lastError().text();
    }
    else
    {
        qDebug() << "Insert table users OK!" << endl;
    }
//----------------------------------------------------------------------------------------
    // создаем таблицу клиентов
    str = "CREATE TABLE clients ("
            "pk INTEGER PRIMARY KEY NOT NULL, "
            "firma TEXT, "
            "addr TEXT, "
            "boss_name TEXT, "
            "boss_phon TEXT, "
            "fin_name TEXT, "
            "fin_phon TEXT, "
            "deliv_name TEXT, "
            "deliv_phon TEXT, "
            "deliv_addr TEXT, "
            "deposit INTEGER"
            ");";
    b = query->exec(str);
    if(!b)
    {
        qDebug() << "Not create table clients!";
        qDebug() << query->lastError().text();
    }
    else
    {
        qDebug() << "Create table clients OK!" << endl;
    }
//----------------------------------------------------------------------------------------------------
    // создаем таблицу приборов
    str = "CREATE TABLE devices ("
            "pk INTEGER PRIMARY KEY NOT NULL, "
            "brand TEXT, "
            "model TEXT, "
            "sn TEXT, "
            "date_sale TEXT, "
            "date_warran TEXT"
            ");";
    b = query->exec(str);
    if(!b)
    {
        qDebug() << "Not create table devices!";
        qDebug() << query->lastError().text();
    }
    else
    {
        qDebug() << "Create table devices OK!" << endl;
    }

}

// getter
QSqlDatabase Connect::getDB()
{
    return db;
}

Connect::~Connect()
{
    //db.close();
    //db.removeDatabase();
}
