#include "mainwindow.h"
#include "ui_mainwindow.h"

/*by Punin Viktor*/
#include <QMessageBox>
#include <QFile>
#include <QCryptographicHash>
#include <QFileDialog>

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


    QFile file(FileDir);
    QString hash;
    if(file.open(QIODevice::ReadOnly))
    {
        hash = QCryptographicHash::hash(file.readAll(), QCryptographicHash::Md5).toHex().constData();
        file.close();
    }

    QMessageBox msgBox;
    msgBox.setText(hash);
    msgBox.setDefaultButton(QMessageBox::Ok);
    msgBox.exec();
}
