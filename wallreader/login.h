#ifndef LOGIN_H
#define LOGIN_H

#include <QDialog>

namespace Ui {
class Login;
}

class Login : public QDialog
{
    Q_OBJECT

public:
    explicit Login(QWidget *parent = 0);
    ~Login();

    bool authorized;
    QString user_id, token;

private slots:
    void on_webView_loadProgress(int progress);

    void on_webView_urlChanged(const QUrl &arg1);

private:
    Ui::Login *ui;

};

#endif // LOGIN_H
