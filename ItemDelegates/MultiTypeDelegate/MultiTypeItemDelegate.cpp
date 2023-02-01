#include "MultiTypeItemDelegate.h"

#include <QLineEdit>
#include <QPlainTextEdit>
#include <QComboBox>
#include <QCheckBox>
#include <QDateEdit>
#include <QTimeEdit>
#include <QDateTimeEdit>
#include <QRadioButton>
#include <QGroupBox>
#include <QSpinBox>
#include <QDoubleSpinBox>
#include <QSlider>
#include <QLayout>

MultiTypeItemDelegate::MultiTypeItemDelegate(QObject *parent):
    QStyledItemDelegate(parent)
{

}

MultiTypeItemDelegate::~MultiTypeItemDelegate()
{

}

void MultiTypeItemDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    QStyledItemDelegate::paint(painter, option, index);
}

QWidget *MultiTypeItemDelegate::createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    Q_UNUSED(option);
    enum EditorType editorType = static_cast<enum EditorType>(index.data(ItemDataRole::EditorType).toInt());
    switch(editorType)
    {
    case EditorType::LineEdit:
    {
        QLineEdit *editor = new QLineEdit(parent);
        editor->setPlaceholderText(index.data(ItemDataRole::EditorPropetyRole).toString());
        return editor;
        break;
    }
    case EditorType::PlainTextEditor:
    {
        QPlainTextEdit *editor = new QPlainTextEdit(parent);
        editor->setPlaceholderText(index.data(ItemDataRole::EditorPropetyRole).toString());
        return editor;
        break;
    }
    case EditorType::CheckBox:
    {
        QCheckBox *editor = new QCheckBox(parent);
        return editor;
        break;
    }
    case EditorType::ComboBox:
    {
        QComboBox *editor = new QComboBox(parent);
        QStringList lst = index.data(ItemDataRole::EditorItems).toStringList();
        editor->insertItems(0, lst);
        return editor;
        break;
    }
    case EditorType::SpinBox:
    {
        QSpinBox *editor = new QSpinBox(parent);
        QVariantList lst = index.data(ItemDataRole::EditorPropetyRole).toList();
        if(lst.size()<4)
            lst.reserve(4);
        editor->setRange(lst[0].toInt(), lst[1].toInt());
        editor->setSingleStep(lst[2].toInt());
        return editor;
        break;
    }
    case EditorType::DoubleSpinBox:
    {
        QDoubleSpinBox *editor = new QDoubleSpinBox(parent);
        QVariantList lst = index.data(ItemDataRole::EditorPropetyRole).toList();
        if(lst.size()<4)
            lst.reserve(4);
        editor->setRange(lst[0].toDouble(), lst[1].toDouble());
        editor->setSingleStep(lst[2].toDouble());
        return editor;
        break;
    }
    case EditorType::Slider:
    {
        QSlider *editor = new QSlider(parent);
        QVariantList lst = index.data(ItemDataRole::EditorPropetyRole).toList();
        if(lst.size()<2)
            lst.reserve(2);
        editor->setTickPosition(lst[0].value<QSlider::TickPosition>());
        editor->setTickInterval(lst[1].toInt());
        return editor;
        break;
    }
    case EditorType::DateEditor:
    {
        QDateEdit *editor = new QDateEdit(parent);
        QVariantList lst = index.data(ItemDataRole::EditorPropetyRole).toList();
        editor->setCalendarPopup(lst[0].toBool());
        editor->setCalendar(lst[1].value<QCalendar>());
        return editor;
        break;
    }
    case EditorType::TimeEditor:
    {
        QTimeEdit *editor = new QTimeEdit(parent);
        return editor;
        break;
    }
    case EditorType::DateTimeEditor:
    {
        QDateTimeEdit *editor = new QDateTimeEdit(parent);
        QVariantList lst = index.data(ItemDataRole::EditorPropetyRole).toList();
        editor->setCalendarPopup(lst[0].toBool());
        editor->setCalendar(lst[1].value<QCalendar>());
        return editor;
        break;
    }
    case EditorType::RadioButtonGroup:
    {
        QGroupBox *editor = new QGroupBox(parent);
        return editor;
        break;
    }
    }
    return new QWidget();
}

void MultiTypeItemDelegate::updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    enum EditorType editorType = static_cast<enum EditorType>(index.data(ItemDataRole::EditorType).toInt());
    switch(editorType)
    {
    case EditorType::LineEdit:
    {
        QLineEdit *editorWidget = qobject_cast<QLineEdit*>(editor);
        editorWidget->setGeometry(option.rect);
        break;
    }
    case EditorType::PlainTextEditor:
    {
        QPlainTextEdit *editorWidget = qobject_cast<QPlainTextEdit*>(editor);
        editorWidget->setGeometry(option.rect);
        break;
    }
    case EditorType::CheckBox:
    {
        QCheckBox *editorWidget = qobject_cast<QCheckBox*>(editor);
        editorWidget->setGeometry(option.rect);
        break;
    }
    case EditorType::ComboBox:
    {
        QComboBox *editorWidget = qobject_cast<QComboBox*>(editor);
        editorWidget->setGeometry(option.rect);
        break;
    }
    case EditorType::SpinBox:
    {
        QSpinBox *editorWidget = qobject_cast<QSpinBox*>(editor);
        editorWidget->setGeometry(option.rect);
        break;
    }
    case EditorType::DoubleSpinBox:
    {
        QDoubleSpinBox *editorWidget = qobject_cast<QDoubleSpinBox*>(editor);
        editorWidget->setGeometry(option.rect);
        break;
    }
    case EditorType::Slider:
    {
        QSlider *editorWidget = qobject_cast<QSlider*>(editor);
        editorWidget->setGeometry(option.rect);
        break;
    }
    case EditorType::DateEditor:
    {
        QDateEdit *editorWidget = qobject_cast<QDateEdit*>(editor);
        editorWidget->setGeometry(option.rect);
        break;
    }
    case EditorType::TimeEditor:
    {
        QTimeEdit *editorWidget = qobject_cast<QTimeEdit*>(editor);
        editorWidget->setGeometry(option.rect);
        break;
    }
    case EditorType::DateTimeEditor:
    {
        QDateTimeEdit *editorWidget = qobject_cast<QDateTimeEdit*>(editor);
        editorWidget->setGeometry(option.rect);
        break;
    }
    case EditorType::RadioButtonGroup:
    {
        QGroupBox *editorWidget = qobject_cast<QGroupBox*>(editor);
        editorWidget->setGeometry(option.rect);
        break;
    }
    }
}

void MultiTypeItemDelegate::setEditorData(QWidget *editor, const QModelIndex &index) const
{
    enum EditorType editorType = static_cast<enum EditorType>(index.data(ItemDataRole::EditorType).toInt());
    switch(editorType)
    {
    case EditorType::LineEdit:
    {
        QLineEdit *editorWidget = qobject_cast<QLineEdit*>(editor);
        editorWidget->setText(index.data(Qt::ItemDataRole::EditRole).value<QString>());
        break;
    }
    case EditorType::PlainTextEditor:
    {
        QPlainTextEdit *editorWidget = qobject_cast<QPlainTextEdit*>(editor);
        editorWidget->setPlainText(index.data(Qt::ItemDataRole::EditRole).value<QString>());
        break;
    }
    case EditorType::CheckBox:
    {
        QCheckBox *editorWidget = qobject_cast<QCheckBox*>(editor);
        editorWidget->setCheckState(index.data(Qt::ItemDataRole::EditRole).value<Qt::CheckState>());
        break;
    }
    case EditorType::ComboBox:
    {
        QComboBox *editorWidget = qobject_cast<QComboBox*>(editor);
        editorWidget->setCurrentIndex(index.data(Qt::ItemDataRole::EditRole).toInt());
        break;
    }
    case EditorType::SpinBox:
    {
        QSpinBox *editorWidget = qobject_cast<QSpinBox*>(editor);
        editorWidget->setValue(index.data(Qt::ItemDataRole::EditRole).toInt());
        break;
    }
    case EditorType::DoubleSpinBox:
    {
        QDoubleSpinBox *editorWidget = qobject_cast<QDoubleSpinBox*>(editor);
        editorWidget->setValue(index.data(Qt::ItemDataRole::EditRole).toDouble());
        break;
    }
    case EditorType::Slider:
    {
        QSlider *editorWidget = qobject_cast<QSlider*>(editor);
        editorWidget->setValue(index.data(Qt::ItemDataRole::EditRole).toInt());
        break;
    }
    case EditorType::DateEditor:
    {
        QDateEdit *editorWidget = qobject_cast<QDateEdit*>(editor);
        editorWidget->setDate(index.data(Qt::ItemDataRole::EditRole).toDate());
        break;
    }
    case EditorType::TimeEditor:
    {
        QTimeEdit *editorWidget = qobject_cast<QTimeEdit*>(editor);
        editorWidget->setTime(index.data(Qt::ItemDataRole::EditRole).toTime());
        break;
    }
    case EditorType::DateTimeEditor:
    {
        QDateTimeEdit *editorWidget = qobject_cast<QDateTimeEdit*>(editor);
        editorWidget->setDateTime(index.data(Qt::ItemDataRole::EditRole).toDateTime());
        break;
    }
    case EditorType::RadioButtonGroup:
    {
        QGroupBox *editorWidget = qobject_cast<QGroupBox*>(editor);
        for(int i=0; i<editorWidget->layout()->count(); i++)
            qobject_cast<QRadioButton*>(editorWidget->layout()->itemAt(i)->widget())->setDown(false);
        qobject_cast<QRadioButton*>(editorWidget->layout()->itemAt(index.data(Qt::ItemDataRole::EditRole).toInt())->widget())->setDown(true);
        break;
    }
    }
}

void MultiTypeItemDelegate::setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const
{
    enum EditorType editorType = static_cast<enum EditorType>(index.data(ItemDataRole::EditorType).toInt());
    switch(editorType)
    {
    case EditorType::LineEdit:
    {
        QLineEdit *editorWidget = qobject_cast<QLineEdit*>(editor);
        model->setData(index, editorWidget->text());
        break;
    }
    case EditorType::PlainTextEditor:
    {
        QPlainTextEdit *editorWidget = qobject_cast<QPlainTextEdit*>(editor);
        model->setData(index, editorWidget->toPlainText());
        break;
    }
    case EditorType::CheckBox:
    {
        QCheckBox *editorWidget = qobject_cast<QCheckBox*>(editor);
        model->setData(index, editorWidget->checkState());
        break;
    }
    case EditorType::ComboBox:
    {
        QComboBox *editorWidget = qobject_cast<QComboBox*>(editor);
        model->setData(index, editorWidget->currentIndex());
        break;
    }
    case EditorType::SpinBox:
    {
        QSpinBox *editorWidget = qobject_cast<QSpinBox*>(editor);
        model->setData(index, editorWidget->value());
        break;
    }
    case EditorType::DoubleSpinBox:
    {
        QDoubleSpinBox *editorWidget = qobject_cast<QDoubleSpinBox*>(editor);
        model->setData(index, editorWidget->value());
        break;
    }
    case EditorType::Slider:
    {
        QSlider *editorWidget = qobject_cast<QSlider*>(editor);
        model->setData(index, editorWidget->value());
        break;
    }
    case EditorType::DateEditor:
    {
        QDateEdit *editorWidget = qobject_cast<QDateEdit*>(editor);
        model->setData(index, editorWidget->date());
        break;
    }
    case EditorType::TimeEditor:
    {
        QTimeEdit *editorWidget = qobject_cast<QTimeEdit*>(editor);
        model->setData(index, editorWidget->time());
        break;
    }
    case EditorType::DateTimeEditor:
    {
        QDateTimeEdit *editorWidget = qobject_cast<QDateTimeEdit*>(editor);
        model->setData(index, editorWidget->dateTime());
        break;
    }
    case EditorType::RadioButtonGroup:
    {
        QGroupBox *editorWidget = qobject_cast<QGroupBox*>(editor);
        for(int i=0; i<editorWidget->layout()->count(); i++)
        {
            if(qobject_cast<QRadioButton*>(editorWidget->layout()->itemAt(i)->widget())->isDown())
            {
                model->setData(index, i);
                break;
            }
        }
        break;
    }
    }
}

bool MultiTypeItemDelegate::editorEvent(QEvent *event, QAbstractItemModel *model, const QStyleOptionViewItem &option, const QModelIndex &index)
{
    return true;
}
