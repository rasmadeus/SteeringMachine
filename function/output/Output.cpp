#include "Output.h"

Output::Output(QObject *parent) :
    QAbstractTableModel(parent)
{
}

int Output::rowCount(const QModelIndex& parent) const
{
    Q_UNUSED(parent)
    return args.count();
}

int Output::columnCount(const QModelIndex& parent) const
{
    Q_UNUSED(parent)
    return 1;
}

QVariant Output::data(const QModelIndex& index, int role) const
{
    if(!index.isValid() || role != Qt::DisplayRole) return QVariant();
    return args[index.row()].second;
}

bool Output::setData(const QModelIndex& index, const QVariant& value, int role)
{
    Q_UNUSED(role)
    if(!index.isValid()) return false;
    args[index.row()].second = value.toDouble();
    return true;
}

QVariant Output::headerData(int section, Qt::Orientation orientation, int role) const
{
    if(role != Qt::DisplayRole) return QVariant();
    return orientation == Qt::Horizontal ? tr("Значение") : args[section].first;
}

Qt::ItemFlags Output::flags(const QModelIndex& index) const
{
    if(!index.isValid()) return Qt::NoItemFlags;
    return Qt::ItemIsEditable | Qt::ItemIsEnabled;
}
