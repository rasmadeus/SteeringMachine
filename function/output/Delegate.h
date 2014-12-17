#ifndef DELEGATE_H
#define DELEGATE_H

#include <QItemDelegate>

class Delegate : public QItemDelegate
{
    Q_OBJECT
public:
    explicit Delegate(QObject *parent = 0);
    QWidget* createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const;
    void setEditorData(QWidget *editor, const QModelIndex &index) const;
};

#endif // DELEGATE_H
