# UgBox_Brain
## How to: Verify Ugly Box Brain Function

### Load Wagman Firmware
**Step 1.**
1. Remove barrel power cables from ODROID C1+ and ODROID XU4.
![image of power removal](./images/unplug_power_bothboards.jpg)

***
NOTE: Use long USB - connector pin cables for camera - XU4 connection instead of  short cables.
***

2. Turn OFF USB AVRISP XPII (blue box).
![image of SURGE](./images/19727195_707031689507944_158428806_o.jpg?raw=true)
1. Remove SRE board from Wagman.
![image of SRE](./images/SRE.jpg)
1. Connect USB AVRISP XPII connector to six pins in place of SRE (see third image for proper orientation).
![image of RISP connector](./images/AVRISP_orientation.jpg)
1. Wire the SURGE power supply on the connector port (green) on the Wagman; red wire connected near plus sign, black wire connects to the port of the right of the red wire.
![image of SURGE pigtail](./images/SURGE_power_pigtails.jpg)
1. Remove ODROID C1+ uUSB from Wagman port.
![image of C1+ uUSB to Wagman port](./images/uUSB_to_Wagman.jpg)
1. Connect 'Brain Test' uUSB to Wagman port.

**Step 2.**

1. Turn ON USB AVRISP XPII (blue box) with SURGE.
![image of SURGE](./images/19727195_707031689507944_158428806_o.jpg?raw=true)
1. Click the 'Setup Wagman' icon on the desktop.
1. Check that the terminal reads 'Bootloader Pass', 'Firmware Pass', 'Setup Pass'.
1. Wait for the terminal to disappear from the screen.
1. Turn OFF USB AVRISP XPII (blue box) with SURGE.
1. Remove USB AVRISP XPII (blue box) connector from pins on Wagman.

### Verify Ugly Box Brain Function - including ODROID C1+, ODROID XU4, and Cameras
**Step 1.**
1. Reconnect both barrel power cables to ODROID C1+ and ODROID XU4.
1. Reconnect SRE board to six pins on Wagman.
1. Remove the USB AVRISP XPII uUSB from the Wagman.
1. Connect uUSB on ODROID C1+ to Wagman.
1. Remove the USB cables from the front and side cameras.
1. Place connector dongle extenders on the connector for C1+ and XU4 cables.
![image of dongle connectors](./images/dongle_extender.jpg)
1. Connect the connector to the ODROID C1+ and ODROID XU4 boards.

**Step 2.**
1. Click 'Brain Test NC' and 'Brain Test EP' icons on the desktop.
![image of brain test icons](./images/braintest_select.jpg)
1. Turn ON Surge power supply.
1. Select the 'Set to SD' button.
1. Check that the Node Controller (ODROID C1+) and Edge Processor (ODROID XU4) pass the sd brain test.
1. On the ep (Edge Processor) test page, select the 'Set to eMMC' button.
1. Wait at least 10 seconds before selecting the 'Set to eMMC' button on the nc (Node Controller) test page.
![image of set to... icons](./images/braintest_ncep.jpg)
1. Check that the Node Controller (ODROID C1+) and Edge Processor (ODROID XU4) pass the sd brain test.
1. Shutdown both the Node Controller (ODROID C1+) and Edge Processor (ODROID XU4).
![image shutdown icons](./images/braintest_shutdown.jpg)
