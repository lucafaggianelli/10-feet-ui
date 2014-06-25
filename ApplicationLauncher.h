#ifndef APPLICATION_LAUNCHER_H
#define APPLICATION_LAUNCHER_H

#include <QObject>
#include <QProcess>

class ApplicationLauncher : public QObject
{

    Q_OBJECT

public:
    explicit ApplicationLauncher(QObject *parent = 0);
    Q_INVOKABLE void launch(QString app);

private:
    void processError(QProcess::ProcessError err);
    QProcess *process;
};

#endif // APPLICATION_LAUNCHER_H
