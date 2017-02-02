#ifndef VKAPI_H
#define VKAPI_H

#include <QObject>
#include <QNetworkReply>

#include "vkpost.h"
#include "../qt-json/json.h"

using QtJson::JsonObject;
using QtJson::JsonArray;

class VkApi : public QObject
{
    Q_OBJECT
public:
    explicit VkApi(QObject *parent = 0);

    void setSourceId(QString& owner_id, QString& domain_) {
        ownerId = owner_id;
        domain = domain_;
    }
    void setToken(QString& token_) {
        token = token_;
    }
    void delay(int msec) const;
    void wallGet(QString& cycles, QString& offset, QString& amount, QString& filter);

signals:
    void vkPostReceived(Vkpost*);

public slots:

private slots:
    void vkReplyParse();

private:
    bool scanStop, replyParsed;

    QString ownerId, domain, token;
    QNetworkReply* vkReply;
    JsonArray jsonTracks;
    int gottenCount;

    void jsonToVkpost(const JsonObject &result);
};

#endif // VKAPI_H
