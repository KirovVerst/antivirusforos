#include "mainwindow.h"
#include "ui_mainwindow.h"

/*by Punin Viktor*/
#include "GetHash.h"
#include "checkFile.h"

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
    //ToDo: test on big files
    QString FileDir = QFileDialog::getOpenFileName(this, tr("Open File"), "", tr("Files (*.*)"));
    QString hash = GetHash(FileDir);


    QMessageBox msgBox;
    if(hash.isEmpty())
        msgBox.setText("Can not get the hash of the file.");
    else
    {
        msgBox.setText("Checksum was calculated.");
        msgBox.setDetailedText(hash);
    }
    msgBox.exec();
}

void MainWindow::on_checkFileButton_clicked()
{
    QString FileDir = QFileDialog::getOpenFileName(this, tr("Open File"), "", tr("Files (*.*)"));
    checkFile(FileDir);
}
