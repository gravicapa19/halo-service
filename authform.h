#ifndef AUTHFORM_H
#define AUTHFORM_H

#include <QDialog>
#include <QMessageBox>
#include "mainwindow.h"
#include "connect.h"

namespace Ui {
class AuthForm;
}

class AuthForm : public QDialog
{
    Q_OBJECT
    
public:
    explicit AuthForm(QWidget *parent = 0);
    ~AuthForm();

private slots:
    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

    void on_lineEdit_2_editingFinished();

    void on_lineEdit_editingFinished();

    void on_checkBox_clicked();

private:
    Ui::AuthForm *ui;
};

#endif // AUTHFORM_H
