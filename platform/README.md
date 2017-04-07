Experiment Platform Architecture
===

Raspberry pi 2: test enviroment for linux programes


---
Hardware List for this experiment environment
[STM32-(f429)] x 1
[Raspberry pi 2] x 2
[IMX6-NXP]
[IMX6-forlinx] x 1

Cross Connection Diagram:

||RPI-1|RPI-2|ST-YH|**ST-IMS**|i.MX6-NXP|i.MX6-S2|335x|
|-|-|-|-|-|-|-|-|
|rs485|√(Master)|√(Master)|√(Slave)|√(Slave)|√(Master)|√(Master)|√(Master)|
|can|||√||√|√|√|
|spi|√|√|√|√||||
|lcd-rgb888|||||√|||
