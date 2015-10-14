#! /bin/sh
### BEGIN INIT INFO
# Provides:          waggle_first_boot
# Required-Start:    $remote_fs $syslog
# Required-Stop:     $remote_fs $syslog
# Default-Start:     2 3 4 5
# Default-Stop:      0 1 6
# Short-Description: a waggle script
# Description:       a waggle script this is
### END INIT INFO

# Author: Foo Bar <foobar@baz.org>
#
# Please remove the "Author" lines above and replace them
# with your own name if you copy and modify this script.

# Do NOT "set -e"

# PATH should only include /usr/* if it runs after the mountnfs.sh script
PATH=/sbin:/usr/sbin:/bin:/usr/bin
DESC="Description of the service"
NAME=waggle_first_boot

SCRIPTNAME=/etc/init.d/$NAME

# Exit if the package is not installed
#[ -x "$DAEMON" ] || exit 0

# Read configuration variable file if it is present
#[ -r /etc/default/$NAME ] && . /etc/default/$NAME

# Load the VERBOSE setting and other rcS variables
. /lib/init/vars.sh

# Define LSB log_* functions.
# Depend on lsb-base (>= 3.2-14) to ensure that this file is present
# and status_of_proc is working.
. /lib/lsb/init-functions

#
# Function that starts the daemon/service
#
do_start()
{
	# Return
	#   0 if daemon has been started
	#   1 if daemon was already running
	#   2 if daemon could not be started

	if [ ! -e /root/first_boot ] ; then
          echo "waggle_first_boot.sh has nothing to do."
	  return 0
	fi

	set -x

	# this script increases the partition size. It is an odroid script. The user will have to reboot afterwards.
	source  /usr/local/bin/fs_resize.sh ; resize_p2

	if [ ! -e /media/boot/boot.ini ] ; then
	  echo "error: could not find /media/boot/boot.ini"
	  return 2
	fi

	export ODROIDMODEL=`head -n 1 /media/boot/boot.ini | cut -d '-' -f 1`

	if [[ ! ${ODROIDMODEL} =~ ^ODROID ]] ; then
	  echo "error: could not detect ODROID model"
	  return 2
	fi

	### hostname
	export UNIQUE="undefined"
	if [ ${ODROIDMODEL}_ == "ODROIDC_" ] ; then
	  export UNIQUE=`ifconfig eth0 | head -n 1 | grep -o "[[:xdigit:]:]\{17\}" | sed 's/://g'`
	  if [ ! ${#UNIQUE} -ge 12 ]; then
	    echo "error: could not extract MAC address"
	    return 2
	  fi
	else
	  # use serial number from SD-card
	  # some devices do not have a unique MAC address, they could use this code
	  export CID_FILE="/sys/block/mmcblk0/device/cid"
	  if [ ! -e ${CID_FILE} ] ; then 
	    echo "error: File not found: ${CID_FILE}" 
	    return 2 
	  fi
	  export UNIQUE=`python -c "cid = '$(cat ${CID_FILE})' ; len=len(cid) ; mid=cid[:2] ; psn=cid[-14:-6] ; print mid+'_'+psn"`
	  if [ ! ${#UNIQUE} -ge 11 ]; then
	    echo "error: could not create unique identifier from SD-card serial number"
	    return 2
	  fi
	fi
	echo waggle_${UNIQUE} > /etc/hostname

	# new host keys
	# Not needed here because they will be recreated by the /etc/rc.local script by default.
	#rm /etc/ssh/ssh_host*
	#dpkg-reconfigure openssh-server

	rm -f /root/first_boot
	return 0
}

#
# Function that stops the daemon/service
#
do_stop()
{
	# Return
	#   0 if daemon has been stopped
	#   1 if daemon was already stopped
	#   2 if daemon could not be stopped
	#   other if a failure occurred
	return 0
}

#
# Function that sends a SIGHUP to the daemon/service
#
do_reload() {
	#
	# If the daemon can reload its configuration without
	# restarting (for example, when it is sent a SIGHUP),
	# then implement that here.
	#
	#start-stop-daemon --stop --signal 1 --quiet --pidfile $PIDFILE --name $NAME
	return 0
}

case "$1" in
  start)
	[ "$VERBOSE" != no ] && log_daemon_msg "Starting $DESC" "$NAME"
	do_start
	case "$?" in
		0|1) [ "$VERBOSE" != no ] && log_end_msg 0 ;;
		2) [ "$VERBOSE" != no ] && log_end_msg 1 ;;
	esac
	;;
  stop)
	[ "$VERBOSE" != no ] && log_daemon_msg "Stopping $DESC" "$NAME"
	do_stop
	case "$?" in
		0|1) [ "$VERBOSE" != no ] && log_end_msg 0 ;;
		2) [ "$VERBOSE" != no ] && log_end_msg 1 ;;
	esac
	;;
  status)
	status_of_proc "$DAEMON" "$NAME" && exit 0 || exit $?
	;;
  #reload|force-reload)
	#
	# If do_reload() is not implemented then leave this commented out
	# and leave 'force-reload' as an alias for 'restart'.
	#
	#log_daemon_msg "Reloading $DESC" "$NAME"
	#do_reload
	#log_end_msg $?
	#;;
  restart|force-reload)
	#
	# If the "reload" option is implemented then remove the
	# 'force-reload' alias
	#
	log_daemon_msg "Restarting $DESC" "$NAME"
	do_stop
	case "$?" in
	  0|1)
		do_start
		case "$?" in
			0) log_end_msg 0 ;;
			1) log_end_msg 1 ;; # Old process is still running
			*) log_end_msg 1 ;; # Failed to start
		esac
		;;
	  *)
		# Failed to stop
		log_end_msg 1
		;;
	esac
	;;
  *)
	#echo "Usage: $SCRIPTNAME {start|stop|restart|reload|force-reload}" >&2
	echo "Usage: $SCRIPTNAME {start|stop|status|restart|force-reload}" >&2
	exit 3
	;;
esac

:
