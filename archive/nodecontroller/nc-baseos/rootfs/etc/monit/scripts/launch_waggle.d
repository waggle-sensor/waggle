#!/bin/bash
 
##
## Launch waggle suite
##

source /etc/profile.d/custom.source

case $1 in
    start)
	# The following echo is only needed if the deamon is not generating its 
	# own lock file
	echo $$ > ${WAGGLE_PID}
	C_PID=$$
	
	#echo "START"
	#cset set --cpu=0 --mem=0 --set="waggle"
	cset proc --move --pid=$C_PID --toset="waggle"
	/usr/bin/python /usr/bin/waggle.py start
	#exec /usr/bin/python /usr/bin/waggle.py
	#echo "START~"
        ;;
    stop)
	#echo "STOP"
	#/usr/bin/python /usr/bin/waggle.py stop
        kill -SIGINT `cat ${WAGGLE_PID}`
        rm "${WAGGLE_PID}"
	#echo "STOP~"
        ;;
    *)
        echo "usage: launch_waggle {start|stop}" ;;
esac
exit 0
