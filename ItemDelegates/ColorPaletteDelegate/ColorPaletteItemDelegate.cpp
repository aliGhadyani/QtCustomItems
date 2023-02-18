#include "ColorPaletteItemDelegate.h"

#include "Definitions.h"
#include <QDebug>
#include <QPainter>

ColorPaletteItemDelegate::ColorPaletteItemDelegate(QObject *parent):
    QStyledItemDelegate(parent)
{

}

ColorPaletteItemDelegate::~ColorPaletteItemDelegate()
{

}

void ColorPaletteItemDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    painter->save();
    Qt::Alignment alignment = option.displayAlignment;
    QRect cellRect = option.rect;
    QRect paletteRect;
    paletteRect.setTopLeft(cellRect.topLeft());
    int paletteX = 0;
    int paletteY = 0;
    switch(alignment)
    {
    case Qt::AlignmentFlag::AlignRight:
        paletteX = cellRect.width() - 132 - 2;
        paletteY = (cellRect.height() / 2) - 10;
        break;
    default:
        paletteX = 2;
        paletteY = (cellRect.height() / 2) - 10;
        break;
    }
    paletteRect.setTopLeft(paletteRect.topLeft() + QPoint(paletteX, paletteY));
    paletteRect.setBottomRight(paletteRect.topLeft() + QPoint(130, 18));
    if(option.state & QStyle::StateFlag::State_MouseOver)
    {
        painter->fillRect(option.rect, ColorPaletteHoveredBackgroundColor);
    }
    if(option.state & QStyle::StateFlag::State_Sunken)
    {
        QPen pen = painter->pen();
        pen.setColor(ColorPalettePressedBorderColor);
        painter->setPen(pen);
        painter->drawRect(option.rect);
    }
    if(index.data(Qt::ItemDataRole::CheckStateRole).value<Qt::CheckState>() == Qt::CheckState::Checked)
    {
        painter->fillRect(paletteRect, ColorPaletteCheckedStateBackgroundColor);
        QPen pen = painter->pen();
        pen.setColor(ColorPaletteCheckedBorderColor);
        painter->setPen(pen);
        painter->drawRect(paletteRect);
    }
    // drawing colors
    {
        QRect colorRect;
        colorRect.setSize(QSize(19, 19));
        colorRect.setX(paletteRect.x() + 2);
        colorRect.setY(paletteRect.y() + 2);
        QPen pen = painter->pen();
        pen.setColor(ColorSquareBorderColor);
        painter->setPen(pen);
        for(int i=PaletteItemDataRole::TextBackground_Dark_02; i<PaletteItemDataRole::Hyperlink; i++)
        {
            painter->fillRect(colorRect, index.data(i).value<QColor>());
            painter->drawRect(colorRect);
            colorRect.setTopLeft(colorRect.topLeft() + QPoint(16, 0));
            colorRect.setBottomRight(colorRect.bottomRight() + QPoint(16, 0));
        }
    }
    painter->restore();
    //QStyledItemDelegate::paint(painter, option, index);
}

QSize ColorPaletteItemDelegate::sizeHint(const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    // color squares are  14*14 px
    // each color square has 1 px border
    // each palette cantains 8 color
    // palettes are chackable
    // 2 px margin from each side for focus rect
    // palatte preview will be
    // width = 8 * ( 14 + 2 ) + 4 + 4 = 136
    // height = 14 + 2 + 4 + 4 = 20
    // for display text I used same width and height
    QSize size(136 * 2, 24);
    return size;
}

QWidget *ColorPaletteItemDelegate::createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    // no edit support yet
    QWidget *widget = nullptr;
    return widget;
}

void ColorPaletteItemDelegate::setEditorData(QWidget *editor, const QModelIndex &index) const
{
    // no edit support yet
}

void ColorPaletteItemDelegate::setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const
{
    // no edit support yet
}

void ColorPaletteItemDelegate::updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    // no edit support yet
}

QString ColorPaletteItemDelegate::displayText(const QVariant &value, const QLocale &locale) const
{
    return QStyledItemDelegate::displayText(value, locale);
}
