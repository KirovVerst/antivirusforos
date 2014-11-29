#include "fileSystem.h"

void browseFileSystem(const QFileInfoList& directories, fileFunction checkFunction,
                      QDir::Filters filters, QDir::SortFlags sort)
{
    for(QFileInfoList::const_iterator it = directories.constBegin(); it != directories.constEnd(); ++it)\
        if(it -> isDir())
            browseFileSystem(it -> absoluteFilePath(), checkFunction, filters, sort);
        else
            checkFunction(it -> absoluteFilePath());
}

void browseFileSystem(const QString& directoryName, fileFunction checkFunction,
                    QDir::Filters filters, QDir::SortFlags sort)
{
    QDir directory(directoryName);
    QFileInfoList content = directory.entryInfoList(filters, sort);
    for(QFileInfoList::const_iterator it = content.constBegin(); it != content.constEnd(); ++it)
    {
        if(it -> isDir())
            browseFileSystem(it -> absoluteFilePath(), checkFunction, filters, sort);
        else
            checkFunction(it -> absoluteFilePath());
    }
}
