#include "ApplicationLauncher.h"
#include <QMessageBox>

ApplicationLauncher::ApplicationLauncher(QObject *parent) :
    QObject(parent),
    process(new QProcess(this))
{
    //QObject::connect( &process, SIGNAL(error(QProcess::ProcessError)),
    //                      this, SLOT(processError(QProcess::ProcessError)));
}

void ApplicationLauncher::launch(QString app)
{
    process->start(app);
}

void ApplicationLauncher::processError(QProcess::ProcessError err)
{
    switch(err)
    {
    case QProcess::FailedToStart:
        QMessageBox::information(0,"FailedToStart","FailedToStart");
        break;
    case QProcess::Crashed:
        QMessageBox::information(0,"Crashed","Crashed");
        break;
    case QProcess::Timedout:
        QMessageBox::information(0,"FailedToStart","FailedToStart");
        break;
    case QProcess::WriteError:
        QMessageBox::information(0,"Timedout","Timedout");
        break;
    case QProcess::ReadError:
        QMessageBox::information(0,"ReadError","ReadError");
        break;
    case QProcess::UnknownError:
        QMessageBox::information(0,"UnknownError","UnknownError");
        break;
    default:
        QMessageBox::information(0,"default","default");
        break;
    }
}
