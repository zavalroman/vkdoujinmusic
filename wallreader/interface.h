#ifndef INTERFACE_H
#define INTERFACE_H

#include <QMainWindow>
#include <QtNetwork/QNetworkReply>
#include <QStringListModel>

namespace Ui {
class Interface;
}

class Interface : public QMainWindow
{
    Q_OBJECT

public:
    explicit Interface(QWidget *parent = 0);
    ~Interface();

private slots:
    void catchExeption(QString);

    void on_requestButton_clicked();
    void on_actionLogin_triggered();

private:
    Ui::Interface *ui;

    bool authorized;
    QString user_id, token;

    bool scanStop, replyParsed;
    QNetworkReply* vkReply;

    QStringList alarmList;
    QStringListModel alarmModel;

    void delay(int msec);
};

#endif // INTERFACE_H
