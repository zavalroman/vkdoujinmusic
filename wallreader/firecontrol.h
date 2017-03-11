#ifndef FIRECONTROL_H
#define FIRECONTROL_H

#include <QObject>

#include "../ibpp/tests/C++/qt-firebird.h"
#include "vkpost.h"

class Firecontrol : public QObject
{
    Q_OBJECT
public:
    explicit Firecontrol(QObject *parent = 0);

    void getDocId(QString rangeBegin, QString rangeEnd, QList<QStringList> *docId);

signals:

public slots:
    void vkpostToDb(Vkpost*);

private:
    void textPrepare(QString& text);
};

#endif // FIRECONTROL_H
