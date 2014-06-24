#include "listmodel.h"
#include <QDebug>

void ListModel::applyRoles()
{
    roles.clear();
    qDebug()<<"\n"<<this->tableName();
    for (int i = 0; i < this->columnCount(); i++) {
            QString role=this->headerData(i, Qt::Horizontal).toString();
            roles[Qt::UserRole + i + 1] = QVariant(role).toByteArray();
            qDebug()<<this->headerData(i, Qt::Horizontal);
    }
#ifndef HAVE_QT5
    setRoleNames(roles);
#endif
}

QVariant ListModel::data(const QModelIndex &index, int role) const{

    QVariant value;
    if(role < Qt::UserRole)
    {
        value = QSqlQueryModel::data(index, role);
    }
    else {
        int columnIdx = role - Qt::UserRole - 1;
        QModelIndex modelIndex = this->index(index.row(), columnIdx);
        value = QSqlQueryModel::data(modelIndex, Qt::DisplayRole);
    }
    return value;
}
