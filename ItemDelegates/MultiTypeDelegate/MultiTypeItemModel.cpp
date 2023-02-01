#include "MultiTypeItemModel.h"

MultiTypeItemModel::MultiTypeItemModel(QObject *parent)
    : QAbstractItemModel(parent)
{
}

QVariant MultiTypeItemModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if(orientation == Qt::Orientation::Vertical)
        return QVariant();
    if(role == Qt::ItemDataRole::DisplayRole)
    {
        switch(section)
        {
        case 0:
            return QObject::tr("Item Type");
        case 1:
            return QObject::tr("Item Value");
        }
    }
    return QVariant();
}

//bool MultiTypeItemModel::setHeaderData(int section, Qt::Orientation orientation, const QVariant &value, int role)
//{
//    if (value != headerData(section, orientation, role)) {
//        // FIXME: Implement me!
//        emit headerDataChanged(orientation, section, section);
//        return true;
//    }
//    return false;
//}

QModelIndex MultiTypeItemModel::index(int row, int column, const QModelIndex &parent) const
{
    return createIndex(row, column);
}

QModelIndex MultiTypeItemModel::parent(const QModelIndex &index) const
{
    return QModelIndex();
}

int MultiTypeItemModel::rowCount(const QModelIndex &parent) const
{
//    if (!parent.isValid())
//        return 0;

    return m_data.size();
}

int MultiTypeItemModel::columnCount(const QModelIndex &parent) const
{
//    if (!parent.isValid())
//        return 0;

    return 2;
}

QVariant MultiTypeItemModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

    if(role == Qt::ItemDataRole::DisplayRole)
    {
        switch(index.column())
        {
        case 0:
            return ItemTypesString[m_data[index.row()].first];
        case 1:
        {
            if(data(index, ItemDataRole::EditorType).toInt() == static_cast<int>(EditorType::ComboBox))
            {
                QStringList lst;
                lst << "Item 1" << "Item 2" << "Item 3" << "Item 4";
                return lst[m_data[index.row()].second.toInt()%4];
            }
            return m_data[index.row()].second;
        }
        }
    }
    else if(role == Qt::ItemDataRole::EditRole)
    {
        switch(index.column())
        {
        case 0:
            return static_cast<int>(m_data[index.row()].first);
        case 1:
            return m_data[index.row()].second;
        }
    }
    else if(role == ItemDataRole::EditorType)
    {
        switch(index.column())
        {
        case 0:
            return static_cast<int>(EditorType::ComboBox);
        case 1:
            return static_cast<int>(ItemTypesDefaultEditor[m_data[index.row()].first]);
        }
    }
    else if(role == ItemDataRole::EditorPropetyRole)
    {
        switch(static_cast<enum EditorType>(data(index, ItemDataRole::EditorType).toInt()))
        {
        case EditorType::LineEdit:
            return QObject::tr("Please Enter Text...");
            break;

        case EditorType::SpinBox:
        {
            QVariantList lst;
            lst << 0 << 100 << 2 << 0;
            return lst;
            break;
        }
        case EditorType::DoubleSpinBox:
        {
            QVariantList lst;
            lst << 0.0 << 100.0 << 0.2 << 0;
            return lst;
            break;
        }

        case EditorType::CheckBox:
            return QVariant();
            break;

        case EditorType::ComboBox:
            return QVariant();
            break;
        }
    }
    else if(role == ItemDataRole::EditorItems)
    {
        switch(index.column())
        {
        case 0:
        {
            QStringList lst;
            for(auto beg = ItemTypesString.begin(); beg != ItemTypesString.end(); beg++)
                lst << beg.value();
            return lst;
        }
        case 1:
        {
            QStringList lst;
            lst << "Item 1" << "Item 2" << "Item 3" << "Item 4";
            return lst;
        }
        }
    }
    return QVariant();
}

bool MultiTypeItemModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if (data(index, role) != value) {
        if(index.column() == 0)
        {
            m_data[index.row()].first = value.value<ItemTypes>();
        }
        else if(index.column() == 1)
        {
            m_data[index.row()].second = value;
        }
        emit dataChanged(index, this->index(index.row(), index.column()));
        return true;
    }
    return false;
}

Qt::ItemFlags MultiTypeItemModel::flags(const QModelIndex &index) const
{
    if (!index.isValid())
        return Qt::NoItemFlags;

    return QAbstractItemModel::flags(index) | Qt::ItemIsEditable;
}

bool MultiTypeItemModel::insertRows(int row, int count, const QModelIndex &parent)
{
    beginInsertRows(parent, row, row + count - 1);
    for(int i=0; i<count; i++)
        m_data.insert(row, QPair<ItemTypes, QVariant>(ItemTypes::MultiChoise, QObject::tr("Srting Value")));
    endInsertRows();
    return true;
}

//bool MultiTypeItemModel::insertColumns(int column, int count, const QModelIndex &parent)
//{
//    beginInsertColumns(parent, column, column + count - 1);
//    // FIXME: Implement me!
//    endInsertColumns();
//    return true;
//}

bool MultiTypeItemModel::removeRows(int row, int count, const QModelIndex &parent)
{
    beginRemoveRows(parent, row, row + count - 1);
    for(int i=0; i<count; i++)
        m_data.removeAt(row);
    endRemoveRows();
    return true;
}

//bool MultiTypeItemModel::removeColumns(int column, int count, const QModelIndex &parent)
//{
//    beginRemoveColumns(parent, column, column + count - 1);
//    // FIXME: Implement me!
//    endRemoveColumns();
//    return true;
//}
