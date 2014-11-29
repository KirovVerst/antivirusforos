#ifndef FILESYSTEM_H
#define FILESYSTEM_H

#include <QFileInfo>
#include <QDir>

typedef void (*fileFunction)(const QString&);

// each navigating functions accept:
// 1) directory (directories) that will be browsed recursively
// 2) function that will be called on each file with directory
// 3) filters that determine which files will be browsed; by default: only executables
// 4) browsing order; by default: directories first, then files

void browseFileSystem(const QFileInfoList& directories, fileFunction checkFunction, QDir::Filters filters =
        QDir::NoDotAndDotDot | QDir::Files | QDir::Dirs | QDir::Executable,
                    QDir::SortFlags sort = QDir::DirsFirst);

// special function for many directories to check
// typically it will be called when it is necessary to check all the file system:
// checkDirectories(QDir::drives(), checkFunction) (should work on all operating systems)

void browseFileSystem(const QString& directoryName, fileFunction checkFunction, QDir::Filters filters =
        QDir::NoDotAndDotDot | QDir::Files | QDir::Dirs | QDir::Executable,
                    QDir::SortFlags sort = QDir::DirsFirst);


#endif // FILESYSTEM_H
