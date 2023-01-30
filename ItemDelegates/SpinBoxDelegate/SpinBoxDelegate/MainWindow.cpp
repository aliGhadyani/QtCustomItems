#include "MainWindow.h"
#include "ui_MainWindow.h"

#include "SpinBoxItemDelegate.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    p_model = new QStandardItemModel(this);
    p_model->setColumnCount(2);
    p_model->insertRows(0, 3);
    p_model->setData(p_model->index(0, 0), tr("Value 1"));
    p_model->setData(p_model->index(0, 1), 20);
    p_model->setData(p_model->index(1, 0), tr("Value 2"));
    p_model->setData(p_model->index(1, 1), 30);
    p_model->setData(p_model->index(2, 0), tr("Value 3"));
    p_model->setData(p_model->index(2, 1), 50);
    ui->tableView->setModel(p_model);
    ui->tableView->setItemDelegateForColumn(1, new SpinBoxItemDelegate);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_2_clicked()
{
    p_model->insertRows(0, 1);
    p_model->setData(p_model->index(0, 0), tr("Value"));
    p_model->setData(p_model->index(0, 1), 0);
}

void MainWindow::on_pushButton_clicked()
{
    QModelIndex index = ui->tableView->currentIndex();
    if(index.isValid())
    {
        p_model->removeRow(index.row());
    }
}
