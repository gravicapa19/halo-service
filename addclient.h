#ifndef ADDCLIENT_H
#define ADDCLIENT_H

#include <QDialog>
#include "connect.h"
//#include "mainwindow.h"

namespace Ui {
class AddClient;
}

class AddClient : public QDialog
{
    Q_OBJECT
    
public:
    explicit AddClient(QWidget *parent = 0);
    ~AddClient();

signals:
    void UpdateAllTbl();

private slots:
    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

private:
    Ui::AddClient *ui;

    QString firma;
    QString addr;
    QString boss_name;
    QString boss_phon;
    QString fin_name;
    QString fin_phon;
    QString deliv_name;
    QString deliv_phon;
    QString deliv_addr;
    int deposit;
};

#endif // ADDCLIENT_H
