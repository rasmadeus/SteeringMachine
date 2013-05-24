#include "Delegate.h"

Delegate::Delegate(QObject *parent) :
    QItemDelegate(parent)
{
}

#include <QDoubleSpinBox>
QWidget* Delegate::createEditor(QWidget* parent, const QStyleOptionViewItem& option, const QModelIndex& index) const
{
    Q_UNUSED(option)
    Q_UNUSED(index)
    QDoubleSpinBox* editor = new QDoubleSpinBox(parent);
    editor->setMaximum(-1000000);
    editor->setMaximum(1000000);
    editor->setDecimals(5);
    return editor;
}

void Delegate::setEditorData(QWidget* editor, const QModelIndex& index) const
{
    QDoubleSpinBox* delegate = static_cast<QDoubleSpinBox*>(editor);
    delegate->setValue(index.data().toDouble());
    delegate->selectAll();
}
