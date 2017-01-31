#include "interface.h"
#include "ui_interface.h"

#include <QtNetwork/QNetworkAccessManager>
#include <QEventLoop>
#include <QTimer>

Interface::Interface(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Interface)
{
    ui->setupUi(this);
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

    scanStop = false;
    replyParsed = true;
    for (int i = 0; i < cycles.toInt(); i++) {
        if (scanStop)
            return;

        while (!replyParsed)
            delay(100);

        replyParsed = false;

        QUrl vkRequest("https://api.vk.com/method/wall.get?owner_id=" + ui->lineOwnerId->text() + "&domain=" + ui->lineDomain->text() + "&offset=" + offset + "&count=" +count + "&filter=" + ui->lineFilter->text() + "&extended=0&v=5.52&access_token=" + token);
        QNetworkAccessManager* manager = new QNetworkAccessManager(this);
        vkReply = manager->get(QNetworkRequest(vkRequest));
        connect(vkReply, SIGNAL(finished()), this, SLOT(vkReplyParse()));

        delay(2000);

        offset = QString::number(offset.toInt() + count.toInt());
    }
}
