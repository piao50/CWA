Communication Protocol
===
	v0.2 - 4/7/17 gushi, add detector diagnostics workflow.
	v0.1 - 3/21/17gushi, original
---
# Commands
||STM32|IMX.6|
|-|-|-|
|**Handshake Commands**|Hello|Hello|
|Sensor Data Commands|VALUE_xxx:----|VALUE_xxx|
||STRUCT_xxx:----,----|STRUCT_xxx|
|Acquire Data Commands| DATA_xxx:----,----|DATA_xxx|
|Device Status Commands| STATUS:----,----|STATUS|
|Operation Commands|SUCCESS|CMD_XXX|
|| FAIL||

+----------------------------------------------------------------------+
|                         |     STM32              |    IMX.6          |
+----------------------------------------------------------------------+
| Handshake Commands      | Hello                  | Hello             |
+----------------------------------------------------------------------+
| Sensor Data Commands    | VALUE_xxx:----         | VALUE_xxx         |
|                         | STRUCT_xxx:----,----   | STRUCT_xxx        |
+----------------------------------------------------------------------+
| Acquire Data Commands   | DATA_xxx:----,----     | DATA_xxx          |
+----------------------------------------------------------------------+
| Device Status Commands  | STATUS:----,----       | STATUS            |
+----------------------------------------------------------------------+
| Operation Commands      | SUCCESS                | CMD_XXX           |
|                         | FAIL                   |                   |
+----------------------------------------------------------------------+

Sensors Table :


---
|   ID              |  RANGE   | FREQUENCE | E-CODE | spi | rs485 | can | i2c | inet | ble |       Comments          |
|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|
| VALUE_Pressure    | 30-1000  |    10 ms  |  -1    |  √  |       |     |     |      |     | IMS Pressure            |
| VALUE_Temperature | 10-1000  |    any    |  -1    |  √  |       |     |     |      |     | Environment Temperature |
| VALUE_Pump        | 30-1000  |    1 sec  |  -1    |  √  |       |     |     |      |     |                         |
| VALUE_Battery     | 30-1000  |    1 sec  |  -1    |  √  |       |     |     |      |     |                         |
| VALUE_Voltage     | 30-1000  |    1 sec  |  -1    |  √  |   √   |     |     |      |     |                         |
| VALUE_Current     | 30-1000  |    5 sec  |  -1    |  √  |       |  √  |     |      |     |                         |
| VALUE_Size        | 30-1000  |    1 min  |  -1    |  √  |   √   |  √  |  √  |  √   |  √  |                         |
+--------------------------------------------------------------------------------------------------------------------+

Detector Diagnostics :
* Reset to factory settings.
* Perform some sensor test tasks and show test results.

Definition:
  VALUE_xxx: float value. 
  STRUCT_xxx:

STRUCT_xxx {
	VALUE_xxx1,
	VALUE_xxx2,
	VALUE_xxx3
};

DATA_xxx {
	DATA[..]
};
