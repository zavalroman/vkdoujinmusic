#include "interface.h"
#include "ui_interface.h"

#include <QtNetwork/QNetworkAccessManager>
#include <QEventLoop>
#include <QTimer>

#include "login.h"
#include "vkapi.h"
#include "firecontrol.h"
#include "vkpost.h"
#include "firecontrol.h"
#include "setpathdialog.h"

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


    processModel.setStringList(processList);
    ui->processView->setModel(&processModel);
}

Interface::~Interface()
{
    delete ui;
}

void Interface::delay(int msec)
{
    //qDebug() << "delay:" << msec;
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
    connect(&vk, SIGNAL(message(QString)), this, SLOT(receiveMessage(QString)));
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

void Interface::receiveMessage(QString m)
{
    processList.append(m);
    processModel.setStringList(processList);
    //qDebug() << m;
}

void Interface::on_downloadButton_clicked()
{
    QString line = ui->downloadEdit->text();
    QString rangeBegin, rangeEnd;
    Firecontrol fc;
    if (line.left(3)=="all") {
        fc.downloadAlbum("0", "all");
        return;
    }
    if (line.contains("..")) {
       rangeBegin = line.split("..").at(0);
       rangeEnd = line.split("..").at(1);
       fc.downloadAlbum(rangeBegin, rangeEnd);
       return;
    }
}

void Interface::on_actionSet_album_s_path_triggered()
{
    SetPathDialog setPath;
    setPath.exec();

    if (setPath.set) {
        albumPath = setPath.path;
    }

}

