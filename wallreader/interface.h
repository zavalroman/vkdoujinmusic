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

signals:
    void message(QString);

private slots:
    void receiveMessage(QString);
    void dlPauseBreak();
    void setDownloadProgress(int);

    void on_requestButton_clicked();
    void on_actionLogin_triggered();
    void on_downloadButton_clicked();
    void on_actionSet_album_s_path_triggered();


    void on_stopButton_clicked();

private:
    Ui::Interface *ui;

    bool authorized;
    QString user_id, token;

    bool scanStop, replyParsed;
    QNetworkReply* vkReply;

    QStringList processList;
    QStringListModel processModel;

    QString albumPath;
    bool downloadFinished, downloadStop;

    void delay(int msec);

};

#endif // INTERFACE_H
