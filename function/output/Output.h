#ifndef OUTPUT_H
#define OUTPUT_H

#include <QAbstractTableModel>
#include <QVector>
#include <QPair>
#include "../Function.h"

class Output : public QAbstractTableModel, public Function
{
    Q_OBJECT
public:
    explicit Output(const QVector<QPair<QString, double> >& defaultArgs, QObject *parent = 0);
    int rowCount(const QModelIndex &parent) const;
    int columnCount(const QModelIndex &parent) const;
    QVariant data(const QModelIndex &index, int role) const;
    bool setData(const QModelIndex &index, const QVariant &value, int role);
    QVariant headerData(int section, Qt::Orientation orientation, int role) const;
    Qt::ItemFlags flags(const QModelIndex &index) const;
    virtual void reset() = 0;
protected:
    QVector<QPair<QString, double> > args;
};

#endif // OUTPUT_H
