#ifndef MULTITYPEITEMMODEL_H
#define MULTITYPEITEMMODEL_H

#include <QAbstractItemModel>
#include <QObject>

enum class ItemTypes : int
{
    String,
    Integer,
    Double,
    Boolean,
    MultiChoise
};

static QMap<ItemTypes, QString> ItemTypesString =
    {
        { ItemTypes::String, QObject::tr("String") },
        { ItemTypes::Integer, QObject::tr("Integer") },
        { ItemTypes::Double, QObject::tr("Double") },
        { ItemTypes::Boolean, QObject::tr("Boolean") },
        { ItemTypes::MultiChoise, QObject::tr("MultiChoise") }
    };

static QMap<ItemTypes, QVariant> ItemTypesDefaultValue =
    {
        { ItemTypes::String, QObject::tr("String Value") },
        { ItemTypes::Integer, QVariant(0) },
        { ItemTypes::Double, QVariant(0.0) },
        { ItemTypes::Boolean, QVariant(false) },
        { ItemTypes::MultiChoise, QVariant(0) }
    };

static QMap<ItemTypes, QVariant> ItemTypesDefaultEdit =
    {
        { ItemTypes::String, QObject::tr("String Value") },
        { ItemTypes::Integer, QVariant(0) },
        { ItemTypes::Double, QVariant(0.0) },
        { ItemTypes::Boolean, QVariant(false) },
        { ItemTypes::MultiChoise, QVariantList() }
    };

class MultiTypeItemModel : public QAbstractItemModel
{
    Q_OBJECT

public:
    explicit MultiTypeItemModel(QObject *parent = nullptr);

    // Header:
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;

//    bool setHeaderData(int section, Qt::Orientation orientation, const QVariant &value, int role = Qt::EditRole) override;

    // Basic functionality:
//    QModelIndex index(int row, int column,
//                      const QModelIndex &parent = QModelIndex()) const override;
//    QModelIndex parent(const QModelIndex &index) const override;

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

    // Editable:
    bool setData(const QModelIndex &index, const QVariant &value,
                 int role = Qt::EditRole) override;

    Qt::ItemFlags flags(const QModelIndex& index) const override;

    // Add data:
    bool insertRows(int row, int count, const QModelIndex &parent = QModelIndex()) override;
//    bool insertColumns(int column, int count, const QModelIndex &parent = QModelIndex()) override;

    // Remove data:
    bool removeRows(int row, int count, const QModelIndex &parent = QModelIndex()) override;
//    bool removeColumns(int column, int count, const QModelIndex &parent = QModelIndex()) override;

private:
    QList<QPair<ItemTypes, QVariant>> m_data;
};

#endif // MULTITYPEITEMMODEL_H
