#ifndef VKPOST_H
#define VKPOST_H

#include <QObject>
#include <QList>

class Vkpost
{
public:
    Vkpost();

    struct Photo {
        QString id, album_id, owner_id, user_id;
        QString photo_75, photo_130, photo_604, photo_807, photo_1280, photo_2560;
        int width, height;
        QString text;
        unsigned int date;
        QString post_id;
        QString access_key;
    } photo;
/*
    struct Poll {
        QString id, owner_id;
        QString question;
        int votes;
        QString answer_id;
        bool anonymous;
    };
*/
    struct Audio {
        QString id, owner_id;
        QString artist, title;
        int duration;
        unsigned int date;
        QString url;
    } track;

    struct Doc {
        QString id, owner_id;
        QString title;
        int size;
        QString ext, url, access_key;
    } doc;

    QString id, from_id, owner_id, post_source;
    unsigned int date;
    QString post_type;
    QString text;
    //bool copy_history;

    QList<Photo> photos;
    QList<Audio> tracks;
    QList<Doc> docs;

    int comments, likes, reposts;

    bool photo_post, poll_post, audio_post;

    QList<QString> commentators;
    QList<QString> whoLikes;
    QList<QString> whoShared;

    void addNewPhoto();
    void addNewTrack();
    void addNewDoc();

private:

};

#endif // VKPOST_H
