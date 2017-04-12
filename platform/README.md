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
||SN-PI1|SN-PI2|SN-YH|**SN-IMS**|SN-NXP|SN-S2|SN-335x|SN-PC|
|rs485|√|√|√|√|√|√|√||
|can|||√||√|√|√||
|inet|√|√|||√|√|√|√|√|

# rs485 bus Test Plan
Only one master with serveral slave 

||RPI-1|RPI-2|ST-YH|**ST-IMS**|i.MX6-NXP|i.MX6-S2|335x|PC|
|-|-|-|-|-|-|-|-|-|
||SN-PI1|SN-PI2|SN-YH|**SN-IMS**|SN-NXP|SN-S2|SN-335x|SN-PC|
|rs485|√(Master)|√|√|√|√|√|√||
|inet|√(Proxy)|||||||√(Center)|

# can bus Test Plan

||RPI-1|RPI-2|ST-YH|**ST-IMS**|i.MX6-NXP|i.MX6-S2|335x|PC|
|-|-|-|-|-|-|-|-|-|
||SN-PI1|SN-PI2|SN-YH|**SN-IMS**|SN-NXP|SN-S2|SN-335x|SN-PC|
|can|||√||√|√|√||
|inet||||||√(Proxy)||√(Center)|

# network Test Plan
  all data can be map to *tcp/ip socket* network interface.
  
  this can use c/c++, python, or web technoligy.
  
||RPI-1|RPI-2|ST-YH|**ST-IMS**|i.MX6-NXP|i.MX6-S2|335x|PC|
|-|-|-|-|-|-|-|-|-|
||SN-PI1|SN-PI2|SN-YH|**SN-IMS**|SN-NXP|SN-S2|SN-335x|SN-PC|
|inet-python|√|√||||||√(Center)|
|inet-c/c++|√|√||||√||√(Center)|

* [ST-YH(f429)] x 1

