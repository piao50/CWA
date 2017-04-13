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
    
## QT SQL
    For Use: support for SQL databases
    Contains: Driver layer, SQL API layer, SQL API layer
```
#include <QtSql>
*.pro: QT += sql
```

## QT Widgets

## Plugins - QT Charts
