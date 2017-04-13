QT Programming Language
===

## QT Core

```
#include <QtCore>
```
* Debug information Output
```
    #include <QDebug>
    qDebug() << "some output informations ..." << endl;
```    
* QT Threading
    
    Contains: platform-independent threading classes, a thread-safe way of posting events, and signal-slot connections across threads.
    
    For Use: a useful paradigm for **performing time-consuming operations** without *freezing the user interface* of an application.
    
* Input/Output, Resources, and Containers    
    Contains: 
    * a resource system for organizing application files and assets
    * a set of containers
    * classes for receiving input and printing output.
    
    Input/Output and Networking: handle input and output to and from **external devices, processes, files** etc. as well as manipulating *files and directories*.
    QBuffer:
        QFile: 
        QFileInfo:  
        QFileDevice:  
        QFileSystemWatcher:
    
* Qt's model/view framework.
    
    
## QT Paint
    Purpose: retain in Customize widget, draw basic graphic primitives. draw complex object systems.
    
## QT SQL
    For Use: support for SQL databases
    Contains: Driver layer, SQL API layer, SQL API layer
    Case study: query with conditions(or filter), display query result page by page.
    
|Driver Type|Description|
|-|-|
|QDB2|IBM DB2|
|QIBASE|Borland InterBase Driver|
|QMYSQL|MySQL Driver|
|QOCI|Oracle Call Interface Driver|
|QODBC|ODBC Driver (includes Microsoft SQL Server)|
|QPSQL|PostgreSQL Driver|
|QSQLITE|SQLite version 3 or above|
|QSQLITE2|SQLite version 2|
|QTDS|Sybase Adaptive Server|

```
#include <QtSql>
*.pro: QT += sql
```

## QT Widgets

## Plugins - QT Charts
