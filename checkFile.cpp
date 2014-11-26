#include "checkFile.h"
#include <QFile>
#include <QIODevice>
#include <QMessageBox>
#include <QByteArray>
void checkFile(QFile & file){

    if (!file.open(QIODevice::ReadOnly)){
        QMessageBox msgBox;
        msgBox.setText("File is not opened");
        msgBox.exec();
        return;
    }

    QByteArray dataFile = file.readAll();
    QFile base("../../../data/virusbase");

    if (!base.open(QIODevice::ReadOnly)){
        QMessageBox msgBox;
        msgBox.setText("Base of signatures not found");
        msgBox.exec();
    }

    QVector<QByteArray> foundViruses;

    while(!base.atEnd()){
        QByteArray signature = base.readLine();

        if (signature[signature.size() - 1] == '\n'){
            signature.remove(signature.size() - 1, 1);
        }

        if (foundViruses.indexOf(signature) != -1){
            continue;
        }

        if (dataFile.indexOf(signature) != -1){
            foundViruses.push_back(signature);
        }
    }

    QString result;
    QMessageBox msgBox;
    if (!foundViruses.empty()){
        result = "File is infected by : \n";
        foreach (QByteArray var,foundViruses ) {
            result += (var + "\n");
        }
    }else{
        result = "File is not infected";
    }
    msgBox.setText(result);
    msgBox.exec();

}
