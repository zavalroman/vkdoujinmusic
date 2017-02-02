#include "firecontrol.h"

Firecontrol::Firecontrol(QObject *parent) : QObject(parent)
{

}

void Firecontrol::textPrepare(QString &text)
{
    for ( int i = 0; i < text.size(); i++) {
        if (text == 39) {
            text.insert(i, 39); //экранируем апостроф
            i++;
        }
        if (text == 10)
            text.replace(i,1," "); //заменяем перенос строки пробелом
    }
}

void Firecontrol::vkpostToDb(Vkpost* vkpost)
{
    QList<int> index;

    textPrepare(vkposts->text);
    QString statement = "INSERT INTO VKPOST(VK_ID,VKGROUP_ID,UNIX_TIME,POST_TEXT,LIKES,REPOSTS,COMMENTS,PHOTO_COUNT,AUDIO_COUNT,POLL) "
                        "VALUES ('" + vkposts->id + "',1," + QString::number(vkposts->date) + ",'" + vkposts->text + "'," + QString::number(vkposts->likes) + "," + QString::number(vkposts->reposts) +
                                                    "," + QString::number(vkposts->comments) + "," + QString::number(vkposts->photos.size()) + "," + QString::number(vkposts->tracks.size()) + ",0)";
    fb->query(statement);
    //statement = "SELECT ID FROM vkpost WHERE id = (SELECT MAX(id) FROM vkpost)";
    statement = "SELECT MAX(id) FROM vkpost"; //недопустимо при одновременном подключении нескольких подобных этому клиентов к бд
    fb->query(statement,&index); //not need. will be delete // why?

    if (vkposts->photos.size() > 0) {
        statement = "INSERT INTO VKPHOTO(VK_ID,PHOTO_75,PHOTO_130,PHOTO_604,PHOTO_807,PHOTO_1280,PHOTO_2560,VKPOST_ID) VALUES('"
                + vkposts->photos[0].id + "','" + vkposts->photos[0].photo_75 + "','" + vkposts->photos[0].photo_130 + "','" + vkposts->photos[0].photo_604 +
                    "','" + vkposts->photos[0].photo_807 + "','" + vkposts->photos[0].photo_1280 + "','" + vkposts->photos[0].photo_2560 + "'," + QString::number(index.at(0)) + ")";
        fb->query(statement);
    } else { //необходимо что-то вставить в любом случае, чтобы айдишники в vkpost  и vkphoto совпадали
             //не очень хорошо получается
        statement = "INSERT INTO vkphoto(vk_id) VALUES('null')";
        fb->query(statement);
        qDebug() << "vkphoto inserted";
    }

    int vkpost_id = index.at(0);

/* заменить ссылкой на архив? :>
    for (int j = 0; j < vkposts->tracks.size(); j++)
    {
        textPrepare(vkposts->tracks[j].artist);
        textPrepare(vkposts->tracks[j].title);
        statement = "INSERT INTO VKTRACK(VK_ID,TO_ID,ARTIST,TITLE,DURATION) VALUES('" + vkposts->tracks[j].id + "','" + vkposts->tracks[j].owner_id + "','" + vkposts->tracks[j].artist +
                                "','" +vkposts->tracks[j].title + "'," + QString::number(vkposts->tracks[j].duration) + ")";
        fb->query(statement);

        statement = "SELECT ID FROM vktrack WHERE id = (SELECT MAX(id) FROM vktrack)";
        fb->query(statement,&index);
        statement = "INSERT INTO VKPOSTXVKTRACK(VKPOST_ID, VKTRACK_ID) VALUES(" + QString::number(vkpost_id) + "," + QString::number(index.at(0)) + ")";
        fb->query(statement);
    }
*/
}
