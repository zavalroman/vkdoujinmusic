#ifndef FILES_H
#define FILES_H

#include <QObject>

class Files : public QObject
{
    Q_OBJECT
public:
    explicit Files(QObject *parent = 0);

    setWorkFolder(QString path) {
        folder = path;
    }
    void download(QString url);

signals:

public slots:

private:
    QString folder;
};

#endif // FILES_H
