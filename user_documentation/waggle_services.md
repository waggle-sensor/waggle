

Waggle services on the waggle node are currently executed by upstart. Upstart scripts can be found in the corresponding git repositories in the upstart directory. The configure scripts in the corresponding git repositories copy the upstart scripts in the /etc/init/ directory.

List of waggle services
```text
- waggle-init 
    - waggle-data_cache
    - waggle-communications	  			 
    - waggle-plugin_manager
- waggle-heartbeat
- waggle-epoch
- waggle-reverse_ssh_tunnel
- waggle-wagman
```

#### waggle-init
increases filesystem, creates recovery files, provisons empty/broken memory cards. Only once this has completeted, data_cache, communications and plugin_manager will be started.

#### waggle-heartbeat
Sends a heartbeat on GPIO pins to be read by the WagMan hardware.

#### waggle-epoch
Get date from beehive server.

#### waggle-reverse_ssh_tunnel
Creates a reverse ssh tunnel to beehive.

#### waggle-wagman
Does something.

## waggle-services command

Use the command "waggle-services" to stop or start waggle services. This script is located in the waggle_image git repository

Example:
```text
> waggle-service list
+------------------+--------+---------+
| name             | goal   | state   |
|------------------+--------+---------|
| waggle-epoch     | start  | running |
| waggle-init      | start  | running |
| waggle-heartbeat | start  | running |
+------------------+--------+---------+
```
or
```text
> waggle-service stop waggle-epoch
State:  waiting
(Goal: stop)
```

Note that waggle plugins are handled by the waggle plugin_manager.



