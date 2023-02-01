#include "MainWindow.h"
#include "ui_MainWindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    MultiTypeItemModel* model = new MultiTypeItemModel(this);
    ui->tableView->setModel(model);
    ui->tableView->setItemDelegate(new MultiTypeItemDelegate);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    ui->tableView->model()->insertRows(0, 1);
}

void MainWindow::on_pushButton_2_clicked()
{
    QModelIndex idx = ui->tableView->currentIndex();
    if(idx.isValid())
    {
        ui->tableView->model()->removeRows(idx.row(), 1);
    }
}
