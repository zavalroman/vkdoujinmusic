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
    void wallGet(QString& cycles, QString& offset, QString& count);

signals:

    void vkPostReceived(Vkpost*);
    //void replyParsed();

public slots:

private slots:

private:
    struct Audio { // for comment's attachment audios
        QString id, owner_id, artist, title;
        int duration;
    } audio;

    bool scanStop, replyParsed;
    bool commentAudioComplete;

    QString ownerId, domain, token;
    //QNetworkReply* response;
    JsonObject jsonResponse;
    JsonArray jsonTracks; // ?
    int gottenCount;

    QList<Audio> audios;

    void jsonToVkpost(const JsonObject &result);
    void jsonToComment(const JsonObject &result);
    void getComments(QString& postId, QString offset, QString count);
    void execute(QString parameters);
};

#endif // VKAPI_H
