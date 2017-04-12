Experiment Platform Architecture
===

Raspberry pi 2: test enviroment for linux programes


---
Hardware List for this experiment environment
* [ST-YH(f429)] x 1
* [ST-IMS(f429)] x 1
* [Raspberry pi 2] x 2
* [IMX6-NXP] x 1
* [IMX6-S2] x 1
* [335x] x 1

# Cross Connection Diagram:
||RPI-1|RPI-2|ST-YH|**ST-IMS**|i.MX6-NXP|i.MX6-S2|335x|PC|
|-|-|-|-|-|-|-|-|-|
|rs485|√|√|√|√|√|√|√|√|
|can|||√||√|√|√||
|spi|√|√|√|√|||||
|lcd-rgb888|||||√||||
|inet|√|√|√||√|√|√|√|√|
|wifi|√|√|√||√|√|√|√|√|
|ble|√|√|√||√|√|√|√|√|

# rs485 bus Test Plan
Only one master with serveral slave 

# can bus Test Plan

# network Test Plan
  all data can be map to *tcp/ip socket* network interface.
  
  this can use c/c++, python, or web technoligy.

* [ST-YH(f429)] x 1

