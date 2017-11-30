### Step by step process of setting a new C1+ up at Surya

1. Create uSD image using **Make SD - NC** icon on the desktop
2. Create eMMC image using **Make eMMC - NC(Pink)** icon on the desktop
3. Plug the uSD and eMMC onto a new C1+
4. Place C1+ on the testing harness
5. Connect C-Ser console cable to C1+
6. Connect USB ATT modem to C1+ 
7. Clear all existing screen sessions on laptop using **Wipe All Screen Sessions** icon on desktop
8. Start a new screen session using **Odroid Init Console**
9. Power C1+ by plugging in the barrel connector

*You should see test scrolling on the serial console with all the boot related messages*
*The C1+ will auto reboot after expanding the SD partitions. It should have 2 SD partitions at this time*
  
10. Wait for console login prompt. The prompt should end with SD, and the console should auto login. 

*The C1+ will now start creating 3 partitions in the eMMC*

11. Watch for the progress of the waggle init-process using `journalctl -fu waggle-init`
12. When the message *Done Initializing waggle!* appears, cntr-C. 
13. Check that the eMMC card has 3 partitions using `blkid` 
14. Unplug boot-select pins from the C1+ and reboot using `reboot` command. 

*The node should reboot in eMMC mode now, you should see the node name end with MMC.*

15. Wait for console login prompt. The prompt should end with MMC, and the console should auto login. 
16. Watch for the progress of the waggle init-process using `journalctl -fu waggle-init`
17. When the message *Done Initializing waggle!* appears, cntr-C. 
18. Check that the uSD card has 3 partitions as well as eMMC using `blkid`.
19. Run `/usr/lib/waggle/core/scripts/status-service | /usr/lib/waggle/core/scripts/status-validator` to get test results. See `FAIL`s and evaludate them based on the conditions, e.g., it is natural to see FAIL flag on waggle_coresense test item.
19. Check for the C1+ on beehive, match the node-id with a new or old entry of `live-nodes`. Modify the C1+ metadata using `set-node-*` scripts. 
20. Halt the C1+ using `halt` command. 

