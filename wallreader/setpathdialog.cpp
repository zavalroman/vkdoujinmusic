#include "setpathdialog.h"
#include "ui_setpathdialog.h"

SetPathDialog::SetPathDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SetPathDialog)
{
    ui->setupUi(this);
    set = false;
}

SetPathDialog::~SetPathDialog()
{
    delete ui;
}

void SetPathDialog::on_buttonBox_accepted()
{
    path = ui->pathEdit->text();
    set = true;
}
