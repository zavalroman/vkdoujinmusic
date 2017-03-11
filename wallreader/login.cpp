#include "login.h"
#include "ui_login.h"
#include <QDebug>

Login::Login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);
    ui->webView->load(QUrl("https://oauth.vk.com/authorize?client_id=5534287&scope=audio,docs&redirect_uri=https://oauth.vk.com/blank.html&display=popup&v=5.52&response_type=token"));

}

Login::~Login()
{
    delete ui;
}

void Login::on_webView_loadProgress(int progress)
{
    ui->progressBar->setValue(progress);
}


void Login::on_webView_urlChanged(const QUrl &arg1)
{
    QStringList urlSplitList = arg1.toString().split("#");

    if (urlSplitList.size()>1) {
        if (strcmp(&urlSplitList[1].toStdString().c_str()[0],"a")) {

           token = urlSplitList[1].split("&")[0].split("=")[1];
           user_id = urlSplitList[1].split("=")[3];
           authorized = true;
            qDebug() << token << user_id;
            this->close();
            return;
        }
    }

    authorized = false;
}
