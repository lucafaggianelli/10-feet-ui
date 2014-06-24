#ifndef APPLICATIONMODEL_H
#define APPLICATIONMODEL_H
#include <QSqlRelationalTableModel>

class ListModel : public QSqlRelationalTableModel
{

    Q_OBJECT
    Q_PROPERTY( int count READ rowCount() NOTIFY countChanged())

signals:
    void countChanged();

public:
    Q_INVOKABLE QVariant data(const QModelIndex &index, int role) const;
    //ListModel(QObject *parent, QSqlDatabase _db):QSqlRelationalTableModel(parent,_db){this->setEditStrategy(QSqlRelationalTableModel::OnManualSubmit);}
    void applyRoles();
#ifdef HAVE_QT5

virtual QHash<int, QByteArray> roleNames() const{return roles;}

#endif

private:
    int count;
    QHash<int, QByteArray> roles;
};
#endif
