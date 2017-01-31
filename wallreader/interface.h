#ifndef INTERFACE_H
#define INTERFACE_H

#include <QMainWindow>
#include <QtNetwork/QNetworkReply>

#include "vkpost.h"
#include "firebird.h"
#include "../qt-json/json.h"

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

    void on_requestButton_clicked();

private:
    Ui::Interface *ui;

    bool scanStop, replyParsed;
    QNetworkReply* vkReply;

    Vkpost* vkpost;
    Firebird* firebird;

    QList<Vkpost*> vkposts;

    void delay(int msec);
};

#endif // INTERFACE_H
