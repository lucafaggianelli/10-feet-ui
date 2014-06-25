#ifndef PACKAGEMANAGER_H
#define PACKAGEMANAGER_H

#include "DatabaseManager.h"
#include "Application.h"

class PackageManager
{
private:
    DatabaseManager* dbManager;

public:
    PackageManager();
    bool install(Application *app);
};

#endif // PACKAGEMANAGER_H
