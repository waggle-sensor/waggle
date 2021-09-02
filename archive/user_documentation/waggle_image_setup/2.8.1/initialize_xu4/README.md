### Step by step process of setting a new XU4 up at Surya

1. Create uSD image using **Make SD - EP** icon on the desktop
2. Create eMMC image using **Make eMMC - EP(Blue)** icon on the desktop
3. Plug the uSD and eMMC onto a new XU4
4. Place XU4 on the testing harness
5. Connect C-Ser console cable to XU4
6. Connect the **black and Yellow/White** boot select cables together using banana clips.
7. Clear all existing screen sessions on laptop using **Wipe All Screen Sessions** icon on desktop
8. Start a new screen session using **Odroid Init Console**
9. Power XU4 by plugging in the barrel connector

*You should see test scrolling on the serial console with all the boot related messages*
*The XU4 will auto reboot after expanding the SD partitions. It should have 2 SD partitions at this time*
  
10. Wait for console login prompt. The prompt should end with SD, and the console should auto login. 

*The XU4 will now start creating 3 partitions in the eMMC*

11. Watch for the progress of the waggle init-process using `journalctl -fu waggle-init`
12. When the message *Done Initializing waggle!* appears, cntr-C. 
13. Check that the eMMC card has 3 partitions using `blkid` and halt using `halt` command. 
14. After the system has halted, turn off power to the XU4 by unplugging the barrel connector. 

15. Connect the **Red and Yellow/White** boot select cables together using banana clips.
16. Power XU4 by plugging in the barrel connector

*The node should reboot in eMMC mode now, you should see the node name ends with MMC.*

17. Wait for console login prompt. The prompt should end with MMC, and the console should auto login. 
18. Watch for the progress of the waggle init-process using `journalctl -fu waggle-init`
19. When the message *Done Initializing waggle!* appears, cntr-C. 
20. Check that the SD card has 3 partitions using `blkid`. 
21. Run `/usr/lib/waggle/core/scripts/status-service | /usr/lib/waggle/core/scripts/status-validator` to get test results. See `FAIL`s and evaludate them based on the conditions, e.g., it is natural to see FAIL flag on waggle_camera_top and waggle_camera_bottom test items.
22. Halt the XU4 using `halt` command. 

