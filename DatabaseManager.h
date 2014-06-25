#ifndef DATABASEMANAGER_H
#define DATABASEMANAGER_H

#include <QMessageBox>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QtDebug>
#include <QDir>

class DatabaseManager
{
private:
    static bool flag;
    static DatabaseManager *__me;
    DatabaseManager();
    QSqlDatabase db;
    bool initTables();

public:
    static const QString
        DB_NAME,
        DB_TABLE_APPS;
    ~DatabaseManager() { flag = false; }
    static DatabaseManager* getInstance();
    bool sql(QString sql);
    bool insert(QString table, QString sql);
};

#endif // DATABASEMANAGER_H
