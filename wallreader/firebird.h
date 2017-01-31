#ifndef FIREBIRD_H
#define FIREBIRD_H

#include <QString>
#include "ibpp/ibpp.h"

class Firebird
{
public:
    Firebird();
    ~Firebird();

    bool query(QString &);
    bool query(QString &, QList<int>*);
    bool query(QString &, QStringList*);
    bool query(QString &, QList<QStringList>*);

private:
    std::string host;
    std::string dbfile;
    std::string login;
    std::string password;

    IBPP::Database db;
    IBPP::Transaction tr;
    IBPP::Statement st;

    void showError(QString);
    void showIbppException(IBPP::Exception&);

};

#endif // FIREBIRD_H
