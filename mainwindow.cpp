#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    model_rem = new QSqlTableModel(NULL);   // создаем модель
    model_rem->setTable("users");  // устанавливаем таблицу из бд
    model_rem->setEditStrategy(QSqlTableModel::OnManualSubmit); // режим редактирования разрешен
    model_rem->select(); // делаем выборку
    model_rem->setHeaderData(0, Qt::Horizontal, tr("Name")); // устанавливаем имя колонки
    model_rem->setHeaderData(1, Qt::Horizontal, tr("Salary")); // устанавливаем имя колонки
    ui->tableRepairs->setModel(model_rem); // устанавливаем модель в таблицу
    //ui->tableView->hideColumn(0); // don't show the ID


    model_cln = new QSqlTableModel(NULL); // создаем модель
    model_cln->setTable("clients"); // устанавливаем таблицу из бд
    //model_cln->setEditStrategy(QSqlTableModel::OnManualSubmit);
    model_cln->setEditStrategy(QSqlTableModel::OnFieldChange); // редактирование заносится в бд !!!!
    model_cln->select();
    ui->tableView_clients->setModel(model_cln);
    ui->tableView_clients->hideColumn(0); // don't show the ID
    ui->tableView_clients->setAlternatingRowColors(true); // Подсветка строк разными цветами
    ui->tableView_clients->resizeColumnsToContents();
    ui->tableView_clients->setContextMenuPolicy(Qt::ActionsContextMenu);
    //ui->tableView_clients->resizeRowsToContents();
    model_cln->setHeaderData(1, Qt::Horizontal, trUtf8("Фирма"));
    model_cln->setHeaderData(2, Qt::Horizontal, trUtf8("Адресс"));
    model_cln->setHeaderData(3, Qt::Horizontal, trUtf8("Имя"));
    model_cln->setHeaderData(4, Qt::Horizontal, trUtf8("Телефон"));
    model_cln->setHeaderData(5, Qt::Horizontal, trUtf8("Бухгалтерия"));
    model_cln->setHeaderData(6, Qt::Horizontal, trUtf8("Телефон"));
    model_cln->setHeaderData(7, Qt::Horizontal, trUtf8("Доставка"));
    model_cln->setHeaderData(8, Qt::Horizontal, trUtf8("Телефон"));
    model_cln->setHeaderData(9, Qt::Horizontal, trUtf8("Адр. дост."));

    ac = new AddClient();
    connect(ac, SIGNAL(UpdateAllTbl()), this, SLOT(UpdateAllTbl()));

    ui->pushButton_6->text();
}


MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::UpdateAllTbl()
{
   model_rem->select(); // делаем выборку
   model_cln->select(); // делаем выборку
}

// кнопка добавить клиента
void MainWindow::on_pushButton_5_clicked()
{
    //ac = new AddClient();
    ac->show();
}

// кнопка удаления клиента
void MainWindow::DeliteClient(QTableView *current_tbt, QSqlTableModel *current_model)     // Функция удаления
{
    if(current_tbt->currentIndex().isValid())
    {
        int row = current_tbt->currentIndex().row();
        int column = current_tbt->currentIndex().column();

        //QSqlTableModel models;
        //models.setTable("tt1");
        current_model->select();

        qDebug()<<current_model->record(row).value(column)<<"X";

        current_model->removeRows(row,1);
        current_model->submitAll();

        current_model->select();      // обновляем модель

        return;
    }

    return;
}

void MainWindow::on_pushButton_6_clicked()
{
    DeliteClient(ui->tableView_clients, model_cln);
}
