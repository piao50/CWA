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
* QObject's relationship, the signal - slot framework.
* QT Threading
    
    Contains: platform-independent threading classes, a thread-safe way of posting events, and signal-slot connections across threads.
    
    For Use: a useful paradigm for **performing time-consuming operations** without *freezing the user interface* of an application.
    
* Input/Output, Resources, and Containers    
    Contains: 
    * a resource system for organizing application files and assets.
    * a set of containers.
    * classes for receiving input and printing output.
    
    Input/Output and Networking: handle input and output to and from **external devices, processes, files** etc. as well as manipulating *files and directories*.
    
* Qt's model/view framework.
    
    
## QT Paint
    Purpose: low-level painting on widgets and other paint devices.
```
Header: #include <QPainter> 
qmake: QT += gui
```
for use: It can draw **everything** from simple lines to complex shapes like pies and chords. It can also draw aligned text and pixmaps. It can also do view and world transformation.
    Common use: The common use of QPainter is inside a widget's paint event: **Construct and customize** (e.g. set the pen or the brush) the painter. Then **draw**. 
```
 void SimpleExampleWidget::paintEvent(QPaintEvent *)
  {
      QPainter painter(this);
      painter.setPen(Qt::blue);
      painter.setFont(QFont("Arial", 30));
      painter.drawText(rect(), Qt::AlignCenter, "Qt");
  }
```
    
    
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
