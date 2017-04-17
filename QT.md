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

### QT Container classes
    These container classes are designed to be lighter, safer, and easier to use than the STL containers.   
    Features:  
    * The container classes are **implicitly shared**, they are **reentrant**, and they are optimized for speed, low memory consumption, and minimal inline code expansion, resulting in smaller executables. 
    * In addition, they are **thread-safe** in situations where they are used as read-only containers by all threads used to access them.
    * For **traversing** the items stored in a container, you can use one of two types of iterators: 
        * Java-style iterators: easier to use and provide high-level functionality.
        * STL-style iterators: more efficient and can be used together with Qt's and STL's generic algorithms.
            
    Categorys:  
    * sequential containers: QList, QLinkedList, QVector, QStack, and QQueue. 
    * associative containers: QMap, QMultiMap, QHash, QMultiHash, and QSet. 
    * special cases, the QCache and QContiguousCache.
    Container Comparatives Summary:
    
    Algorithm Complexity:  
    * Constant time: O(1). 
    * Logarithmic time: O(log n). 
    * Linear time: O(n).
    * Linear-logarithmic time: O(n log n). 
    * Quadratic time: O(n²).
    
    Growth Strategies: 

### Input/Output and Networking
    Handle input and output to and from **external devices, processes, files** etc. as well as manipulating *files and directories*.   
    * Qt file system: QDir, QFile, QFileDevice, QFileInfo.
    * IO Stream: QBuffer, QDataStream
    * Abstract: QIODevice
    * Resource files. QResource
    * Images: QImageReader, QImageWriter
    * Text: QTextDocumentWriter
    
    common file types: text and binary and resources.  
    common file operations:
        * remove a file using remove().
        * The file is opened with open(), closed with close(), and flushed with flush().
        * read and written using QDataStream or QTextStream
        * read and written with QIODevice-inherited functions read(), readline(), readAll(), write().
        * read and written one character at a time with getChar(), putChar(), and ungetChar().
    More advanced **file system related operations** are provided by QFileInfo and QDir.
    
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

The Core functionality of QPainter is drawing. 
    * QPainter is the class used to perform drawing operations.  
    * QPaintDevice represents a device that can be painted on using a QPainter.
    * QPaintEngine provides the interface that the painter uses to draw onto different types of devices.

Architecture:  
    Together with the QPaintDevice and QPaintEngine classes. (thought)
    
Settings: 
    the font used for drawing text,   
    the color or pattern that is used for filling shapes  
    the color or stipple that is used for drawing lines or boundaries.
    make up the painter's coordinate transformation system. viewport(), window(), worldTransform().
Drawing:
    provides functions to draw most primitives: drawPoint(), drawPoints(), drawLine(), drawRect(), drawRoundedRect(), drawEllipse(), drawArc(), drawPie(), drawChord(), drawPolyline(), drawPolygon(), drawConvexPolygon() and drawCubicBezier().  
    convenience functions:  drawRects() and drawLines(), draw the given number of rectangles or lines in the given array of QRects or QLines using the current pen and brush.  
    fill area: fillRect(), eraseRect().  
    Paths: provides a container for painting operations, enabling graphical shapes to be constructed and reused.  
    Pixmaps and Images:  
    Rendering Quality:  
    Coordinate Transformations: The most commonly used transformations are scaling, rotation, translation and shearing.  
    Clipping:  
    Composition Modes:  
    
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
The QWidget class is the **base class** of all *user interface objects*.
* The widget is the atom of the user interface.
* It receives mouse, keyboard and other events from the window system.
* Paints a representation of itself on the screen.
* Every widget is **rectangular**, and they are sorted in a Z-order. 

### Widgets Categories   
* Top-Level Widgets: a widget without a parent widget is always an independent **window(top-level widget)**.
* Child Widgets: Non-window widgets are child widgets.
* Composite Widgets: used as a **container** to group a number of child widgets. the required visual properties - a QFrame.
    adding child widgets to it, usually managed by a **layout**.
* Custom Widgets and Painting:  can be used to display custom content that is composed using a series of painting operations with an instance of the QPainter class. Each widget performs all painting operations from within its paintEvent() function.       

### Widget Size Hints and Size Policies
The size policy lets you supply **good default behavior** for the **layout management system**, so that other widgets can contain and manage yours **easily**. The default size policy indicates that the size hint represents the preferred size of the widget, and this is often good enough for many widgets.

### Widget Style Sheets

## Plugins - QT Charts
