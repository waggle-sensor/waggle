
# Remove and install packages

The waggle image is based on the ODROID stock image (ubuntu). As there is currently no officially supported/maintained minimal server image, we take the default ubuntu image for ODROID and remove all packages that are not needed. Before we remove packages we verify that we do not remove the network-manager. For this do the apt-get purge first with simulation option "-s". Then do the actual purge without the "-s" option.
 
```bash
apt-get update

apt-get purge -s \
"^gimp-*" "^x11*" abiword* apport* aspell aspell-en audacious* ca-certificates-java chromium-* consolekit python-crcmod cups-* dictionaries-common dpkg-dev fonts-* fonts-dejavu-core gnome-* gstreamer* gvfs-common gvfs-libs:armhf hicolor-icon-theme hplip-data hunspell-en-us imagemagick-common jade java-common joe kerneloops-daemon ladspa-sdk laptop-detect libart-2.0-dev libasound2-dev libatomic-ops-dev libaudit-dev libavahi-client-dev libavahi-common-dev libavc1394-0:armhf libavresample1:armhf libavutil52:armhf libbison-dev libbluetooth3:armhf libbluray1:armhf libbonobo2-common libbonoboui2-common libboost* libbs2b0 libburn4 libbz2-dev libc-dev-bin libc6-dev libcaca0:armhf libcamel-1.2-45 libcap-dev libcdaudio1 libcddb2 libcdio-cdda1 libcdio-paranoia1 libcdio13 libcdparanoia0:armhf libcdt5 libcec libcgraph6 libcogl15:armhf libcolamd2.8.0:armhf libcolord1:armhf libcolorhug1:armhf libcompfaceg1 libcrack2:armhf libcroco3:armhf libcue1 libcups2:armhf libcupscgi1:armhf libcupsfilters1:armhf libcupsimage2:armhf libcupsmime1:armhf libcupsppdc1:armhf libdatrie1:armhf libdbus-1-dev libdc1394-22:armhf libdca0:armhf libdirac-decoder0:armhf libdirac-encoder0:armhf libdiscid0:armhf libdjvulibre-text libdjvulibre21:armhf libdmx1:armhf libdrm-nouveau2:armhf libdrm-omap1:armhf libdrm-radeon1:armhf libdv4:armhf libdvdnav4:armhf libdvdread4:armhf libegl1-mesa-drivers:armhf libegl1-mesa:armhf libenca-dev libexempi-dev libexo-common libexo-helpers libexpat1-dev libfaad2:armhf libfakeroot:armhf libffi-dev libfftw3-bin libfftw3-double3:armhf libfftw3-single3:armhf libfl-dev libflac8:armhf libfontembed1:armhf libfontenc1:armhf libframe6:armhf libfreetype6:armhf libfribidi0:armhf libfs6:armhf libftdi1:armhf libfuse2:armhf libgbm1:armhf libgcc-4.9-dev libgck-1-0:armhf libgcr-3-common libgcr-base-3-1:armhf libgcrypt11-dev libgda-5.0-common libgdk-pixbuf2.0-0:armhf libgdk-pixbuf2.0-common libgdome2-0 libgdome2-cpp-smart0c2a libgeis1:armhf libgeoclue0:armhf libgeoip1:armhf libgif4:armhf libgirepository-1.0-1 libgl1-mesa-dri:armhf libgl1-mesa-glx:armhf libglapi-mesa:armhf libgles1-mesa:armhf libgles2-mesa:armhf libglib-perl libglib2.0-doc libgme0 libgmpxx4ldbl:armhf libgoffice-0.10-10-common libgomp1:armhf libgpg-error-dev libgphoto2-port10:armhf libgraphite2-3:armhf libgs9-common libgsf-1-114 libgsf-1-common libgsl0ldbl libgsm1:armhf libgtk* libgtk-3-common libgtk2.0-common libgtop2-7 libgtop2-common libguess1:armhf libgusb2:armhf libgutenprint2 libgweather-common libhogweed2:armhf libhpmud0 libhunspell-1.3-0:armhf libibus-1.0-5:armhf libical1 libid3tag0 libidn11-dev libieee1284-3:armhf libijs-0.35 libilmbase6:armhf libimage-exiftool-perl libiptcdata0 libisofs6 libiw30:armhf libjack-jackd2-0:armhf libjasper1:armhf libjavascriptcoregtk-3.0-0:armhf libjbig0:armhf libjbig2dec0 libjna-java libjpeg-turbo8:armhf libjpeg8:armhf libjs-jquery libjte1 libkate1 liblavjpeg-2.1-0 liblcms2-2:armhf libldap2-dev liblircclient0 libllvm3.4:armhf liblockfile-bin liblockfile1:armhf libloudmouth1-0 liblqr-1-0:armhf libltdl7:armhf liblua5.2-0:armhf liblzma-dev liblzo2-dev libmad0:armhf libmbim-glib0:armhf libmeanwhile1 libmenu-cache-bin libmenu-cache3 libmessaging-menu0 libmicrohttpd10 libmikmod2:armhf libmimic0 libmirprotobuf0:armhf libmjpegutils-2.1-0 libmms0:armhf libmodplug1 libmp3lame0:armhf libmpcdec6 libmpeg2-4:armhf libmpeg2encpp-2.1-0 libmpeg3-dev libmpg123-0:armhf libmplex2-2.1-0 libmtdev1:armhf libmtp-common libmtp-runtime libmtp9:armhf libncurses5-dev libnetpbm10 libnettle4:armhf libnfs-dev libobt2 libogg0:armhf libopenal-data libopenal1:armhf libopencv* libopenjpeg2:armhf libopenobex1 libopenvg1-mesa:armhf libopus-dev liborbit-2-0:armhf liborc-0.4-0:armhf libots0 libp11-kit-dev libp11-kit-gnome-keyring:armhf libpam-gnome-keyring:armhf libpaper-utils libpaper1:armhf libpathplan4 libpciaccess-dev libpcre3-dev libpixman-1-0-dbg:armhf libpixman-1-0:armhf libplist1:armhf libpopt-dev libpostproc52 libprotobuf-lite8:armhf libprotobuf8:armhf libpthread-stubs0-dev libpython-dev libpython2.7-dev libqmi-glib0:armhf libqpdf13:armhf libquvi-scripts libraptor2-0:armhf librarian0 librasqal3:armhf libraw1394-11:armhf libreadline-dev libreadline6-dev libreoffice-* librxtx-java libsamplerate0:armhf libsane-common libsbc1:armhf libschroedinger-1.0-0:armhf libsecret-1-0:armhf libsecret-common libselinux1-dev libsepol1-dev libshairplay libsidplayfp:armhf libsoundtouch0:armhf libsp1c2 libspeex1:armhf libspeexdsp1:armhf libsqlite3-dev libsrtp0 libssh2-1-dev libstdc++-4.9-dev libt1-5 libtag1-vanilla:armhf libtag1c2a:armhf libtagc0:armhf libtasn1-6-dev libtcl8.6:armhf libtelepathy-glib0:armhf libthai-data libtheora0:armhf libtinfo-dev libtinyxml-dev libudev-dev libudisks2-0:armhf libusb-1.0-0-dev libusb-dev libusbmuxd2 libv4l2rds0:armhf libva1:armhf libvdpau1:armhf libvisual-0.4-0:armhf libvo-aacenc0:armhf libvo-amrwbenc0:armhf libvpx1:armhf libvte-2.90-common libvte-common libwavpack1:armhf libwayland-client0:armhf libwayland-cursor0:armhf libwayland-server0:armhf libwbclient0:armhf libwebcam0 libwebkitgtk-3.0-common libwebp5:armhf libwebpdemux1:armhf libwebpmux1:armhf libwhoopsie0 libwildmidi-config libwildmidi1:armhf libwnck-3-common libwnck-common libwpd-0.9-9 libwpg-0.2-2 libwps-0.2-2 libwvstreams4.6-base libwvstreams4.6-extras libx11-6:armhf libx11-data libx11-xcb1:armhf libx264-142:armhf libxapian22 libxau6:armhf libxcb-* libxcomposite1:armhf libxcursor1:armhf libxdamage1:armhf libxdmcp6:armhf libxdot4 libxext6:armhf libxfce4ui-common libxfce4util-common libxfce4util6 libxfixes3:armhf libxi6:armhf libxinerama1:armhf libxkbfile1:armhf libxml2-dev libxp6:armhf libxshmfence-dev libxslt1-dev libxvidcore-dev lightdm link-grammar-dictionaries-en lintian linux-libc-dev linux-sound-base lubuntu-lxpanel-icons lxmenu-data lxsession-data m4 maliddx mc mc-data mesa* metacity-common mircommon-dev:armhf mobile-broadband-provider-info mysql-common nautilus-data netpbm obex-data-server openjdk-7-jre openjdk-7-jre* openprinting-ppds p11-kit p11-kit-modules:armhf pastebinit pcmciautils pidgin-data policykit-desktop-privileges poppler-data printer-driver-c2esp printer-driver-foo2zjs-common printer-driver-min12xxw pulseaudio pulseaudio* python-cups python-cupshelpers python-dbus-dev python-dev python2.7-dev python3 qpdf quilt rfkill samba* samba-* sgml-base sgml-data sgmlspl smbclient snappy sound-theme-freedesktop swig swig2.0 sylpheed-doc system-config-printer-common system-config-printer-udev t1utils transmission* transmission-common tsconf ttf-* uno-libs3 usb-modeswitch usbmuxd uvcdynctrl uvcdynctrl-data valgrind valgrind vim vim-* whoopsie wireless-tools wvdial wvdial x11-xfs-utils x11proto-* xarchiver xarchiver xbmc xdg-user-dirs xdg-user-dirs-gtk xfce4-* xfce4-power-manager xfonts-100dpi xfonts-base xfonts-mathml xfonts-scalable xfonts-utils xinit xinput xserver-* xserver-xorg-core xul-ext-ubufox \
glib-networking+ libsoup2.4-1+ wpasupplicant+ policykit-1+ network-manager+ dpkg+ libselinux1+
```

Note that the last line contains packages we do not want to be removed ! Those package have a plus character as suffix.


In case you make changes to the above list of packages, you may want to sort it afterwards:
```bash
echo b a | tr " " "\n" | sort | tr "\n" " "
```

Cleaning, upgrading and more cleaning:
```bash
rm -rf /usr/local/share/kodi/ /etc/cups /usr/lib/xorg/modules/drivers
apt-get clean
apt-get autoclean
apt-get upgrade
apt-get clean
apt-get autoclean
dpkg --list | grep ^rc | awk -F" " ' { print $2 } ' | xargs apt-get -y purge
```

Packages we want to install:
```bash
apt-get install htop iotop iftop bwm-ng screen git python-serial python-pip monit tree
```

# Other image modifications

Deploy start-up script for host key etc...

# Shrink image

TODO: e2fsck, resize2fs, fdisk

