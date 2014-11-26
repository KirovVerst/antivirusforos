#include "GetHash.h"

QString GetHash(QString FileDir)
{
    QFile file(FileDir);
    QString hash;
    if(file.open(QIODevice::ReadOnly))
    {
        hash = QCryptographicHash::hash(file.readAll(), QCryptographicHash::Md5).toHex().constData();
        file.close();
        return hash;
    }
    return "";
}
