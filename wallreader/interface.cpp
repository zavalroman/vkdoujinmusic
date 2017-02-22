#include "interface.h"
#include "ui_interface.h"

#include <QtNetwork/QNetworkAccessManager>
#include <QEventLoop>
#include <QTimer>

#include "login.h"
#include "vkapi.h"
#include "firecontrol.h"
#include "vkpost.h"

Interface::Interface(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Interface)
{
    ui->setupUi(this);

    QFile cache;
    cache.setFileName("cache");
    if (cache.exists()) {
        if(cache.open(QIODevice::ReadOnly)) {
            token = cache.readLine();
            authorized = true;
            cache.close();
            //qDebug() << "token from file:" << token;
        }
    }


    alarmModel.setStringList(alarmList);
    ui->alarmView->setModel(&alarmModel);
}

Interface::~Interface()
{
    delete ui;
}

void Interface::delay(int msec)
{
    qDebug() << "delay:" << msec;
    QEventLoop loop;
    QTimer::singleShot(msec, &loop, SLOT(quit()));
    loop.exec();
}

void Interface::on_requestButton_clicked()
{
    QString cycles = ui->lineCycle->text();
    QString offset = ui->lineOffset->text();
    QString count = ui->lineCount->text();
    QString ownerId = ui->lineOwnerId->text();
    QString domain = ui->lineDomain->text();

    Firecontrol fc;
    VkApi vk;
    connect(&vk, SIGNAL(exeption(QString)), this, SLOT(catchExeption(QString)));
    connect(&vk, SIGNAL(vkPostReceived(Vkpost*)), &fc, SLOT(vkpostToDb(Vkpost*)));
    vk.setToken(token);
    vk.setSourceId(ownerId, domain);
    vk.wallGet(cycles, offset, count);
}

void Interface::on_actionLogin_triggered()
{
    Login loginDialog;
    //if (!authorized)
    loginDialog.exec();

    if (loginDialog.authorized) {
        authorized = loginDialog.authorized;
        user_id = loginDialog.user_id;
        token = loginDialog.token;
        QFile cache("cache");
        if(cache.open(QIODevice::WriteOnly)) {
            QTextStream writeStream(&cache);
            writeStream << token;
            cache.close();
        }
        qDebug() << "login ok";
    } else {
        qDebug() << "login ne ok";
    }

}

void Interface::catchExeption(QString e)
{
    alarmList.append(e);
    alarmModel.setStringList(alarmList);
}
