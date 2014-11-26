#include "mainwindow.h"
#include "ui_mainwindow.h"

/*by Punin Viktor*/
#include "GetHash.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_GetHashButton_clicked()
{
    QString FileDir = QFileDialog::getOpenFileName(this, tr("Open File"), "", tr("Files (*.*)"));

    QMessageBox msgBox;
    msgBox.setText(GetHash(FileDir));
    msgBox.setDefaultButton(QMessageBox::Ok);
    msgBox.exec();
}
