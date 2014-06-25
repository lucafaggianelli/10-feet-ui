#include "DatabaseManager.h"
#include <QMessageBox>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QtDebug>
#include <QDir>

const QString
    DatabaseManager::DB_NAME = "10-feet.sqlite",
    DatabaseManager::DB_TABLE_APPS = "applications";

bool DatabaseManager::flag = false;
DatabaseManager* DatabaseManager::__me = NULL;

DatabaseManager::DatabaseManager()
{
    db = QSqlDatabase::addDatabase("QSQLITE");

    // Set DB name and path
    QString path(QDir::home().path());
    path.append(QDir::separator()).append(DB_NAME);
    path = QDir::toNativeSeparators(path);
    db.setDatabaseName(path);

    // Open DB
    if (!db.open()) {
        QMessageBox::critical(0, "Cannot open database",
                "Unable to establish a database connection.\n"
                     "This example needs SQLite support. Please read "
                     "the Qt SQL driver documentation for information how "
                     "to build it.\n\n"
                     "Click Cancel to exit.", QMessageBox::Cancel);
        return;
    }

    if (!db.tables().contains(DB_TABLE_APPS)) {
        initTables();
    }
}

DatabaseManager* DatabaseManager::getInstance()
{
    if (!flag) {
        __me = new DatabaseManager();
        flag = true;
    }

    return __me;
}

bool DatabaseManager::sql(QString sql)
{
    QSqlQuery query;
    return query.exec(sql);
}

bool DatabaseManager::insert(QString table, QString values) {
    QString q = "INSERT INTO ";
    q.append(table);
    q.append(" ");
    q.append(values);

    return sql(q);
}

bool DatabaseManager::initTables()
{
    QString createTable = "create table ";
    createTable.append(DB_TABLE_APPS);
    createTable.append(" (id int primary key, "
                         "exec varchar(255), "
                         "name varchar(255), "
                         "description varchar(255), "
                         "icon varchar(255), "
                         "category int, "
                         "type int"
                         ")");
    return sql(createTable);
}
