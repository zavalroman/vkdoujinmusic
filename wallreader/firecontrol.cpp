#include "firecontrol.h"

#include <QDebug>

Firecontrol::Firecontrol(QObject *parent) : QObject(parent)
{

}

void Firecontrol::textPrepare(QString &text)
{
    for ( int i = 0; i < text.size(); i++) {
        if (text[i] == 39) {
            text.insert(i, 39); //экранируем апостроф
            i++;
        }
        if (text[i] == 10)
            text.replace(i,1," "); //заменяем перенос строки пробелом
    }
}

void Firecontrol::vkpostToDb(Vkpost* vkpost)
{
    Firebird fb;
    QList<int> index;

    textPrepare(vkpost->text);
    qDebug() << "insert text" << vkpost->text;
    QString statement = "INSERT INTO vkpost(vk_id,vkgroup_id,unix_time,post_text,likes,reposts,comments,photo_count,audio_count) "
                        "VALUES ('"+vkpost->id+"',1,"+QString::number(vkpost->date)+",'"+vkpost->text+"',"+QString::number(vkpost->likes)+","+QString::number(vkpost->reposts)+
                                                  ","+QString::number(vkpost->comments)+","+QString::number(vkpost->photos.size())+","+QString::number(vkpost->tracks.size())+")";
    fb.query(statement);
    statement = "SELECT MAX(id) FROM vkpost";
    fb.query(statement,&index);

    if (vkpost->photos.size() > 0) {
        statement = "INSERT INTO vkphoto(vk_id,photo_75,photo_130,photo_604,photo_807,photo_1280,photo_2560,vkpost_id) VALUES('"
                + vkpost->photos[0].id + "','" + vkpost->photos[0].photo_75 + "','" + vkpost->photos[0].photo_130 + "','" + vkpost->photos[0].photo_604 +
                    "','" + vkpost->photos[0].photo_807 + "','" + vkpost->photos[0].photo_1280 + "','" + vkpost->photos[0].photo_2560 + "'," + QString::number(index.at(0)) + ")";
        fb.query(statement);
    } else {
        statement = "INSERT INTO vkphoto(vk_id,vkpost_id) VALUES('null',"+QString::number(index.at(0))+")";
        fb.query(statement);
    }

    for (int j = 0; j < vkpost->tracks.size(); j++) {
        textPrepare(vkpost->tracks[j].artist);
        textPrepare(vkpost->tracks[j].title);
        statement = "INSERT INTO vktrack(vk_id,to_id,artist,title,vkpost_id) VALUES('"+vkpost->tracks[j].id+"','"+vkpost->tracks[j].owner_id+"','"+vkpost->tracks[j].artist +
                                "','"+vkpost->tracks[j].title+"',"+QString::number(index.at(0))+")";
        fb.query(statement);
    }
    for (int j = 0; j < vkpost->commentators.size(); ++j) {
        statement = "INSERT INTO comments(vkpost_id,commentator) VALUES("+QString::number(index.at(0))+",'"+vkpost->commentators.at(j)+"')";
        fb.query(statement);
    }
    delete vkpost;
}
