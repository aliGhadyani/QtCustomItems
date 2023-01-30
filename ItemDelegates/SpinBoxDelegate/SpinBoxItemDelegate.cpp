#include "SpinBoxItemDelegate.h"

#include <QSpinBox>
#include <QDoubleSpinBox>

SpinBoxItemDelegate::SpinBoxItemDelegate(SpinBoxInputType type, QObject *parent):
    QStyledItemDelegate(parent),
    p_inputType(type)
{
    p_inputRange.first = 0;
    p_inputRange.second = 100;
}

SpinBoxItemDelegate::~SpinBoxItemDelegate()
{

}

void SpinBoxItemDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    QStyledItemDelegate::paint(painter, option, index);
}

QWidget *SpinBoxItemDelegate::createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    switch(p_inputType)
    {
    case SpinBoxInputType::Integer:
    {
        QSpinBox *editor = new QSpinBox(parent);
        editor->setRange(p_inputRange.first.value<int>(), p_inputRange.second.value<int>());
        editor->setGeometry(option.rect);
        editor->setValue(index.data(Qt::ItemDataRole::EditRole).value<int>());
        return editor;
    }
    case SpinBoxInputType::Double:
    {
        QDoubleSpinBox *editor = new QDoubleSpinBox(parent);
        editor->setRange(p_inputRange.first.value<double>(), p_inputRange.second.value<double>());
        editor->setGeometry(option.rect);
        editor->setValue(index.data(Qt::ItemDataRole::EditRole).value<double>());
        return editor;
    }
    }
}

void SpinBoxItemDelegate::setEditorData(QWidget *editor, const QModelIndex &index) const
{
    switch(p_inputType)
    {
    case SpinBoxInputType::Integer:
    {
        QSpinBox *spinbox = qobject_cast<QSpinBox*>(editor);
        spinbox->setValue(index.data(Qt::ItemDataRole::EditRole).value<int>());
        break;
    }
    case SpinBoxInputType::Double:
    {
        QDoubleSpinBox *spinbox = qobject_cast<QDoubleSpinBox*>(editor);
        spinbox->setValue(index.data(Qt::ItemDataRole::EditRole).value<double>());
        break;
    }
    }
}

void SpinBoxItemDelegate::setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const
{
    switch(p_inputType)
    {
    case SpinBoxInputType::Integer:
    {
        QSpinBox *spinbox = qobject_cast<QSpinBox*>(editor);
        model->setData(index, spinbox->value());
        break;
    }
    case SpinBoxInputType::Double:
    {
        QDoubleSpinBox *spinbox = qobject_cast<QDoubleSpinBox*>(editor);
        model->setData(index, spinbox->value());
        break;
    }
    }
}

void SpinBoxItemDelegate::updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    switch(p_inputType)
    {
    case SpinBoxInputType::Integer:
    {
        QSpinBox *spinbox = qobject_cast<QSpinBox*>(editor);
        spinbox->setGeometry(option.rect);
        break;
    }
    case SpinBoxInputType::Double:
    {
        QDoubleSpinBox *spinbox = qobject_cast<QDoubleSpinBox*>(editor);
        spinbox->setGeometry(option.rect);
        break;
    }
    }
}

SpinBoxItemDelegate::SpinBoxInputType SpinBoxItemDelegate::inputType() const
{
    return p_inputType;
}

void SpinBoxItemDelegate::setInputType(SpinBoxInputType type)
{
    p_inputType = type;
}

QPair<QVariant, QVariant> SpinBoxItemDelegate::inputRange() const
{
    return p_inputRange;
}

void SpinBoxItemDelegate::setInputRange(QVariant min, QVariant max)
{
    if(max.value<int>() < min.value<int>())
        max = min;
    if(max.value<double>() < min.value<double>())
        max = min;
    p_inputRange = QPair<QVariant,QVariant>(min, max);
}
