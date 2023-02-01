#ifndef ITEMMODELDEFINITIONS_H
#define ITEMMODELDEFINITIONS_H

#include <QObject>

enum class ItemTypes : int
{
    String,
    Integer,
    Double,
    Boolean,
    MultiChoise
};

Q_DECLARE_METATYPE(ItemTypes);

enum ItemDataRole
{
    MetaDataRole = Qt::ItemDataRole::UserRole + 1000,
    EditorPropetyRole = Qt::ItemDataRole::UserRole + 2000,
    EditorType,
    EditorItems
};

enum class EditorType : int
{
    LineEdit,
    PlainTextEditor,
    CheckBox,
    RadioButtonGroup,
    ComboBox,
    DateEditor,
    TimeEditor,
    DateTimeEditor,
    Slider,
    SpinBox,
    DoubleSpinBox
};

#endif // ITEMMODELDEFINITIONS_H
