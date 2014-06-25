#include "PackageManager.h"
#include "DatabaseManager.h"
#include "Application.h"
#include <QString>

PackageManager::PackageManager()
{
    dbManager = DatabaseManager::getInstance();
}

bool PackageManager::install(Application *app) {
    char *query;
    sprintf(query, "(exec,name,description,icon,category)"
            " VALUES "
            "('%s','%s','%s','%s','%d')",
            app->exec, app->name, app->description, app->icon, app->category);

    dbManager->insert(DatabaseManager::DB_TABLE_APPS, query);
    return true;
}
