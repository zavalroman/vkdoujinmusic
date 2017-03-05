#ifndef SETPATHDIALOG_H
#define SETPATHDIALOG_H

#include <QDialog>

namespace Ui {
class SetPathDialog;
}

class SetPathDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SetPathDialog(QWidget *parent = 0);
    ~SetPathDialog();
    QString path;
    bool set;

private slots:
    void on_buttonBox_accepted();

private:
    Ui::SetPathDialog *ui;
};

#endif // SETPATHDIALOG_H
