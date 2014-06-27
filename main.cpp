#include <QtGui/QApplication>
#include <QDeclarativeContext>
#include <QProcess>

#include "qmlapplicationviewer.h"
#include "listmodel.h"
#include "DatabaseManager.h"
#include "ApplicationLauncher.h"
#include "Application.h"

Q_DECL_EXPORT int main(int argc, char *argv[])
{
    QScopedPointer<QApplication> app(createApplication(argc, argv));

    DatabaseManager* dbManager = DatabaseManager::getInstance();

    QmlApplicationViewer viewer;

    ListModel *model = new ListModel();
    //ListModel *modelLista = new QLSqlTableModel;
    model->setTable("applications");
    model->applyRoles();
    model->select();
    /*modelList->setTable("lists");
    modelList->setRelation(2, QSqlRelation("items", "id", "name"));
    modelList->select();
    modelList->applyRoles();*/
    QDeclarativeContext *ctxt = viewer.rootContext();
    ctxt->setContextProperty("modelApp", model);
    //ctxt->setContextProperty("modelList", modelLista);

    ApplicationLauncher launcher;
    QDeclarativeContext *context = viewer.rootContext();
    context->setContextProperty("applicationLauncher", &launcher);

    viewer.setOrientation(QmlApplicationViewer::ScreenOrientationAuto);
    viewer.setMainQmlFile(QLatin1String("qml/10feet/main.qml"));
    viewer.showExpanded();

    //QProcess process;
    //process.start("/usr/bin/nautilus");

    Application::fromDesktopFile("luca");

    return app->exec();
}
