#include "vkapi.h"

#include <QNetworkAccessManager>
#include <QEventLoop>
#include <QTimer>

VkApi::VkApi(QObject *parent) : QObject(parent)
{

}

void VkApi::delay(int msec) const
{
    qDebug() << "delay:" << msec;
    QEventLoop loop;
    QTimer::singleShot(msec, &loop, SLOT(quit()));
    loop.exec();
}


void VkApi::wallGet(QString& cycles, QString& offset, QString& amount, QString& filter)
{
    scanStop = false;
    replyParsed = true;
    for (int i = 0; i < cycles.toInt(); i++) {
        if (scanStop)
            return;

        while (!replyParsed)
            delay(100);

        replyParsed = false;

        QUrl vkRequest("https://api.vk.com/method/wall.get?owner_id="+ownerId+"&domain="+domain+"&offset="+offset+"&count="+amount+"&filter="+filter+"&extended=0&v=5.52&access_token="+token);
        QNetworkAccessManager* manager = new QNetworkAccessManager(this);
        vkReply = manager->get(QNetworkRequest(vkRequest));
        connect(vkReply, SIGNAL(finished()), this, SLOT(vkReplyParse()));

        delay(2000);

        offset = QString::number(offset.toInt() + count.toInt());
    }
}

void VkApi::vkReplyParse()
{/*
    if (error)
    {
        qDebug() << "error while get";
        return;
    }
*/
    qDebug() << "start parse";
    bool ok;
    //qDebug() << QString(vkReply->readAll());
    JsonObject result = QtJson::parse(QString(vkReply->readAll()),ok).toMap();
    if (!ok) {
        qDebug() << "An error occurred during parsing";
    } else {
        jsonToVkpost(result);
    }
    replyParsed = true;
}

void VkApi::jsonToVkpost(const JsonObject &result)
{
    Vkpost* vkpost;
    /*
        qDebug() << "head begin";
        QList<QString> keys = head.keys();
        for (int i = 0; i < keys.size(); i++ )
           qDebug() << keys[i];
        qDebug() << "items end";
    */

    QList<QString> resultkeys = result.keys();
    if (resultkeys[0] == "error") {
        qDebug() << "ERROR: access to vk is unsucsessful. return";
        return;
    }

    JsonObject jsonObject = result["response"].toMap();
    JsonArray items = jsonObject["items"].toList();

    if (items.size() == 0) {
        qDebug() << "ERROR: vk reply has no items. return";
        scanStop = true;
        return;
    }

    for (int i = 0; i < items.size(); i++) {
        JsonObject head = items[i].toMap();

        qDebug() << "pre copy";
        while (head["copy_history"].toList().size() > 0) {
            i++;
            head = items[i].toMap();
        }
        qDebug() << "post copy";

        vkpost = new Vkpost();

        vkpost->id = head["id"].toString();
        vkpost->from_id = head["from_id"].toString();
        vkpost->owner_id = head["owner_id"].toString();
        vkpost->post_source = head["post_source"].toString();
        vkpost->date = head["date"].toUInt();
        vkpost->post_type = head["post_type"].toString();
        vkpost->text = head["text"].toString();

        //playList.push_back(vkpost->text);

        vkpost->comments = head["comments"].toMap()["count"].toInt();
        vkpost->likes = head["likes"].toMap()["count"].toInt();
        vkpost->reposts = head["reposts"].toMap()["count"].toInt();

        JsonArray attachments = head["attachments"].toList();

        vkpost->audio_post = false;
        vkpost->photo_post = false;
        vkpost->poll_post = false;

        foreach (QVariant attachment, attachments) {
            if (attachment.toMap()["type"].toString() == "photo") {
                //qDebug() << "type: photo";
                JsonObject jsonPhoto = attachment.toMap()["photo"].toMap();
/*
            QList<QString> keys = jsonPhoto.keys();
            for (int i = 0; i < keys.size(); i++ )
                qDebug() << keys[i];
*/
                vkpost->addNewPhoto();
                vkpost->photos.back().id = jsonPhoto["id"].toString();
                vkpost->photos.back().owner_id = jsonPhoto["owner_id"].toString();

                vkpost->photos.back().photo_75 = jsonPhoto["photo_75"].toString();
                vkpost->photos.back().photo_130 = jsonPhoto["photo_130"].toString();
                vkpost->photos.back().photo_604 = jsonPhoto["photo_604"].toString();
                vkpost->photos.back().photo_807 = jsonPhoto["photo_807"].toString();
                vkpost->photos.back().photo_1280 = jsonPhoto["photo_1280"].toString();

                vkpost->photos.back().width = jsonPhoto["width"].toInt();
                vkpost->photos.back().height = jsonPhoto["height"].toInt();
                vkpost->photos.back().text = jsonPhoto["text"].toString();

                vkpost->photos.back().post_id = jsonPhoto["post_id"].toString();
                vkpost->photos.back().access_key = jsonPhoto["access_key"].toString();
                //user_id, album_id, date

                vkpost->photo_post = true;
            }
/*
            if (attachment.toMap()["type"].toString() == "poll") {
                qDebug() << "type: poll";
                JsonObject jsonPoll = attachment.toMap()["poll"].toMap();
                CREATE TABLE MELOMANYPOLL...
                vkpost->poll_post = true;
            }
*/
            if (attachment.toMap()["type"].toString() == "audio") {
                //qDebug() << "type: audio";
                JsonObject jsonAudio = attachment.toMap()["audio"].toMap();
                vkpost->addNewTrack();
                vkpost->tracks.back().id = jsonAudio["id"].toString();
                vkpost->tracks.back().owner_id = jsonAudio["owner_id"].toString();
                vkpost->tracks.back().artist = jsonAudio["artist"].toString();
                vkpost->tracks.back().title = jsonAudio["title"].toString();

//                playList.push_back(vkpost->tracks.back().title);

                vkpost->tracks.back().duration = jsonAudio["duration"].toInt();
                //date...
                //vkpost->tracks.back().url = jsonAudio["url"].toString();
                vkpost->audio_post = true;
            }
        }
        if (vkpost->poll_post && vkpost->audio_post)
            qDebug() << "WARNING: Post" << vkpost->id << "has poll and audio!(это норма!)";

         emit vkPostReceived(vkpost);
    }
    gottenCount = vkposts.size();
    //qDebug() << "gotten:" << gottenCount;
    //for (int i = 0; i < gottenCount; i++)
        //vkpostToDb(i);

    //for (int i = 0; i < vkposts.size(); i++)
        //delete vkposts.at(i);

    //vkposts.clear();
}
