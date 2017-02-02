#ifndef FIRECONTROL_H
#define FIRECONTROL_H

#include <QObject>

#include "../ibpp/tests/C++/firebird.h"

class Firecontrol : public QObject
{
    Q_OBJECT
public:
    explicit Firecontrol(QObject *parent = 0);

    void setFirebird(Firebird* firebird) {
        fb = firebird;
    }

signals:

public slots:

private:
    Firebird* fb;
};

#endif // FIRECONTROL_H
