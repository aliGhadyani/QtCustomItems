#ifndef SPINBOXITEMDELEGATE_H
#define SPINBOXITEMDELEGATE_H

#include <QStyledItemDelegate>

class SpinBoxItemDelegate : public QStyledItemDelegate
{
public:
    enum class SpinBoxInputType : int
    {
        Integer,
        Double
    };
    Q_PROPERTY(SpinBoxInputType inputType READ inputType WRITE setInputType NOTIFY inputTypeChanged)

public:
    explicit SpinBoxItemDelegate(SpinBoxInputType type = SpinBoxInputType::Integer, QObject *parent = nullptr);
    ~SpinBoxItemDelegate();

    // QAbstractItemDelegate interface
public:
    virtual void paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const override;
    virtual QWidget *createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const override;
    virtual void setEditorData(QWidget *editor, const QModelIndex &index) const override;
    virtual void setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const override;
    virtual void updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex &index) const override;

public:
    SpinBoxInputType inputType() const;
    void setInputType(SpinBoxInputType type);
    QPair<QVariant,QVariant> inputRange() const;
    void setInputRange(QVariant min = 0, QVariant max = INT_MAX);

private:
    SpinBoxInputType p_inputType;
    QPair<QVariant,QVariant> p_inputRange;

signals:
    void inputTypeChanged(SpinBoxItemDelegate::SpinBoxInputType type);
};

#endif // SPINBOXITEMDELEGATE_H
