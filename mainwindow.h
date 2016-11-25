#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtSql>
#include <QTableView>
#include <QSqlTableModel>
#include "connect.h"
#include "addclient.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void DeliteClient(QTableView *current_tbt, QSqlTableModel *current_model);

public slots:
    void UpdateAllTbl();

private slots:
    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

private:
    Ui::MainWindow *ui;
    AddClient *ac;
    QSqlTableModel *model_rem;
    QSqlTableModel *model_cln;

};

#endif // MAINWINDOW_H
