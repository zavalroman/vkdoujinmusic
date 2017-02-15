#include <QNetworkRequest>
#include <QNetworkReply>
#include "mismatch.h"
#include "ui_mismatch.h"
#include "../ibpp/tests/C++/qt-firebird.h"

Mismatch::  Mismatch(QWidget *parent, Firebird *firebird, const QString &post_text, int id) :
    QDialog(parent),
    ui(new Ui::Mismatch)
{
    ui->setupUi(this);
    QStringList urlList;
    QString statement = "SELECT photo_604 FROM vkphoto WHERE vkpost_id =" + QString::number(id);
    if (firebird->query(statement, &urlList) && urlList[0].size() > 0) {
        qDebug() << "url:" << urlList[0];
        QUrl url(urlList[0]);
        QNetworkRequest request(url);
        manager = new QNetworkAccessManager(this);
        manager->get(request);
        connect(manager, SIGNAL(finished(QNetworkReply*)), this, SLOT(photoDownloadFinished(QNetworkReply*)));
    } else { qDebug() << "sql query error"; }

    ui->originalText->setPlainText(post_text);
}

Mismatch::~Mismatch()
{
    delete ui;
}

void Mismatch::on_buttonBox_accepted()
{
    correctEvent = ui->corEvent->text();
    correctCircle = ui->corCircle->text();
    correctAlbum = ui->corAlbum->text();
    correctDisc = ui->corDisc->text();
    correctPart = ui->corPart->text();
}

void Mismatch::photoDownloadFinished(QNetworkReply *reply)
{
    if (reply->error() != QNetworkReply::NoError) {
        qDebug() << reply->errorString();
        return;
    }
    QVariant attribute = reply->attribute(QNetworkRequest::RedirectionTargetAttribute);
    if (attribute.isValid()) {
        QUrl url = attribute.toUrl();
        qDebug() << "must go to:" << url;
        return;
    }
    qDebug() << "Content type:" << reply->header(QNetworkRequest::ContentTypeHeader).toString();
    QByteArray jpegData = reply->readAll();
    QPixmap pixmap;
    pixmap.loadFromData(jpegData);
    ui->canvas->setPixmap(pixmap);
}
