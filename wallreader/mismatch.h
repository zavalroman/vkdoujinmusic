#ifndef MISMATCH_H
#define MISMATCH_H

#include <QNetworkAccessManager>
#include <QDialog>

class Firebird;

namespace Ui {
class Mismatch;
}

class Mismatch : public QDialog
{
    Q_OBJECT

public:
    explicit Mismatch(QWidget *parent = 0, Firebird *firebird = 0, const QString &post_text = 0, int id = -1);
    ~Mismatch();

    QString correctEvent;
    QString correctCircle;
    QString correctAlbum;
    QString correctDisc;
    QString correctPart;

private slots:
    void on_buttonBox_accepted();
    void photoDownloadFinished(QNetworkReply*);

private:
    Ui::Mismatch *ui;

    QNetworkAccessManager *manager;
};

#endif // MISMATCH_H
