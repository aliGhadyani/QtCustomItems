#ifndef MultiTypeItemDelegate_H
#define MultiTypeItemDelegate_H

#include <QStyledItemDelegate>
#include "ItemModelDefinitions.h"

class MultiTypeItemDelegate : public QStyledItemDelegate
{
    Q_OBJECT
public:
    explicit MultiTypeItemDelegate(QObject *parent = nullptr);
    ~MultiTypeItemDelegate();
public: // reimplemented
    void paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const override;
    QWidget *createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const override;
    void updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex &index) const override;
    void setEditorData(QWidget *editor, const QModelIndex &index) const override;
    void setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const override;
protected:
    bool editorEvent(QEvent *event, QAbstractItemModel *model, const QStyleOptionViewItem &option, const QModelIndex &index) override;
};

#endif // MultiTypeItemDelegate_H
