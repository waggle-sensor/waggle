

Waggle Message Types
====================

All message sent through waggle must have a declared message type. This is split into two components

Major Type
   The general category that the message falls into.

Minor Type
   The subtype of the message, used for various things.

Below is a list of waggle message types


+------------+-----------------------+--------------------------------+
|Major Type  | Description           | Minor Types                    |
+------------+-----------------------+--------------------------------+
| 'F' (0x46) | Large file transfer   | Transfer Number (0x00-0xFF)    |
+------------+-----------------------+--------------------------------+
| 'f' (0x66) | Small file transfer   | None                           |
+------------+-----------------------+--------------------------------+
| 'p' (0x70) | Ping                  | 'r' (0x72) request             |
|            |                       | 'a' (0x61) answer              |
+------------+-----------------------+--------------------------------+
| 't' (0x74) | Time                  | 'r' (0x72) request             |
|            |                       | 'a' (0x61) answer              |
+------------+-----------------------+--------------------------------+
| 's' (0x73) | Sensor                | 'd' (0x64) data                |
+------------+-----------------------+--------------------------------+
| 'r' (0x72) | Registration          | None                           |
+------------+-----------------------+--------------------------------+