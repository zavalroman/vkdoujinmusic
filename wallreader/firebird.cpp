#include <QMessageBox>
#include "firebird.h"
#include <QDebug>

Firebird::Firebird()
{
    host = "localhost";
    dbfile = "/var/db/firebird/mokou.fdb";
    login = "SYSDBA";
    password = "masterkey";

    try {
        db = IBPP::DatabaseFactory(host, dbfile, login, password);
        db->Connect();
    } catch (IBPP::Exception& e) { showIbppException(e); }

    //tr = IBPP::TransactionFactory(db);
}

Firebird::~Firebird()
{
    if (db->Connected())
        db->Disconnect();
}

void Firebird::showError(QString errorText)
{
    QMessageBox errorBox;
    errorBox.critical(0,"FireBird class error", errorText);
    errorBox.show();
}

void Firebird::showIbppException(IBPP::Exception& e)
{
    QMessageBox exBox;
    exBox.critical(0, "IBPP exception", QString::fromStdString(e.ErrorMessage()));
    exBox.show();
}

bool Firebird::query(QString &statement)
{
    if (!db->Connected()) {
        showError("db disconnected");
        return false;
    }

    tr = IBPP::TransactionFactory(db);
    tr->Start();

    st = IBPP::StatementFactory(db, tr);

    try {
        st->Execute(statement.toUtf8().constData());
        tr->Commit();
    } catch (IBPP::Exception& e) { showIbppException(e); return false; }

    return true;
}

bool Firebird::query(QString &statement, QList<int> *container)
{
    if (!db->Connected()) {
        showError("db disconnected");
        return false;
    }

    tr = IBPP::TransactionFactory(db);
    tr->Start();

    st = IBPP::StatementFactory(db, tr);

    try {
        container->clear();
        int cell;
        st->Execute(statement.toUtf8().constData());
        while (st->Fetch()) {
           st->Get(1, cell);
           container->append(cell);
        }
        tr->Commit();
    } catch (IBPP::Exception& e) { showIbppException (e); return false; }

    return true;
}

bool Firebird::query(QString &statement, QStringList *container)
{
    if (!db->Connected()) {
        showError("db disconnected");
        return false;
    }

    tr = IBPP::TransactionFactory(db);
    tr->Start();

    st = IBPP::StatementFactory(db, tr);

    try {
        std::string cell;
        container->clear();

        st->Execute(statement.toUtf8().constData());
        while (st->Fetch()) {
           st->Get(1, cell);
           container->append(QString::fromStdString(cell));
        }
        tr->Commit();
    } catch (IBPP::Exception& e) { showIbppException (e); return false; }

    return true;
}

bool Firebird::query(QString &statement, QList<QStringList> *container)
{
    if (!db->Connected()) {
        showError("db disconnected");
        return false;
    }

    tr= IBPP::TransactionFactory(db);
    tr->Start();

    st = IBPP::StatementFactory(db, tr);

    try
    {
        QStringList list;
        std::string cell;
        int n;

        st->Execute(statement.toUtf8().constData());

        n = st->Columns();
        container->clear();

        while (st->Fetch())
        {
            list.clear();
            for ( int i = 1; i<=n; i++) {
                st->Get(i, cell);
                list.append(QString::fromStdString(cell));
            }
            container->append(list);
        }
        tr->Commit();
    } catch (IBPP::Exception& e) { showIbppException(e); return false; }

    return true;
}
