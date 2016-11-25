#ifndef CONNECT_H
#define CONNECT_H

#include <QObject>
#include <QtSql>
#include <QSqlDatabase>
#include <QMessageBox>
#include <QSqlQuery>
#include <QApplication>

class Connect : public QObject
{
    Q_OBJECT
public:
    explicit Connect(QObject *parent = 0);
    ~Connect();
    QSqlDatabase getDB();

private:

    QString strdb;
    QSqlDatabase db;

    void CreateAllTable();
};

#endif // CONNECT_H
