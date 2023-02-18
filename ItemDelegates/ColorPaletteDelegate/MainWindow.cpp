#include "MainWindow.h"
#include "./ui_MainWindow.h"

#include "Definitions.h"
#include "ColorPaletteItemDelegate.h"
#include <QStandardItemModel>

class PaletteModel : public QStandardItemModel
{
public:
    explicit PaletteModel(QObject *parent=nullptr):QStandardItemModel(parent){}
    Qt::ItemFlags flags(const QModelIndex &index) { return QStandardItemModel::flags(index) | Qt::ItemFlag::ItemIsEditable | Qt::ItemFlag::ItemIsUserCheckable; }
};

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    FillMSOfficePalettes();
    PaletteModel *model = new PaletteModel(this);
    model->appendColumn(MSOfficePallets);
    ui->listView->setModel(model);
    ui->listView->setItemDelegate(new ColorPaletteItemDelegate);
}

MainWindow::~MainWindow()
{
    delete ui;
}

