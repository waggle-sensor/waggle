#!/bin/sh

#
# Copyright (C) 2010 Matthias Buecher (http://www.maddes.net/)
#
# This program is free software; you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation; either version 2 of the License, or
# (at your option) any later version.
# http://www.gnu.org/licenses/gpl-2.0.txt
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program; if not, write to the Free Software
# Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
#

UIMAGE=$1

OUT_DIR=$2
mkdir -p "${OUT_DIR}"

# check for uImage magic word
# http://git.denx.de/cgi-bin/gitweb.cgi?p=u-boot.git;a=blob;f=include/image.h
echo 'Checking for uImage magic word...'
MAGIC=`dd if="${UIMAGE}" ibs=4 count=1 | hexdump -v -e '1/1 "%02X"'`
[ '27051956' != "${MAGIC}" ]  && { echo 'Not an uImage.' ; exit 1 ; }

# extract data from uImage
echo 'uImage recognized.'
echo 'Extracting data...'
DATAFILE="${OUT_DIR}/uImage.data"
dd if="${UIMAGE}" of="${DATAFILE}" ibs=64 skip=1

# check for ARM mach type ( xx 1C A0 E3 xx 10 81 E3 )
# http://www.simtec.co.uk/products/SWLINUX/files/booting_article.html#d0e600
echo 'Checking for ARM mach-type...'
MAGIC=`dd if="${DATAFILE}" ibs=1 skip=1 count=3 | hexdump -v -e '1/1 "%02X"'`
[ '1CA0E3' = "${MAGIC}" ] && {
	MAGIC=`dd if="${DATAFILE}" ibs=1 skip=5 count=3 | hexdump -v -e '1/1 "%02X"'`
	[ '1081E3' = "${MAGIC}" ] && {
		echo 'ARM mach-type header recognized.'
		echo 'Extracting mach-type header...'
		dd if="${DATAFILE}" of="uImage.mach-type" ibs=8 count=1
#
		ARCH=`hexdump -v -e '1/1 "%02X "' uImage.mach-type`
		echo "The mach-type is: ${ARCH}"
#
		echo 'Stripping mach-type header...'
		TMPFILE='uImage.tmp'
		dd if="${DATAFILE}" of="${TMPFILE}" ibs=8 skip=1
		rm -f "${DATAFILE}"
		mv "${TMPFILE}" "${DATAFILE}"
	}
}

# check for zImage, otherwise assume Image
# http://www.simtec.co.uk/products/SWLINUX/files/booting_article.html#d0e309
TMPFILE='Image'
echo 'Checking for zImage...'
MAGIC=`dd if="${DATAFILE}" ibs=4 skip=9 count=1 | hexdump -v -e '1/1 "%02X"'`
[ '18286F01' = "${MAGIC}" ] && {
	START=`dd if="${DATAFILE}" ibs=4 skip=10 count=1 | hexdump -v -e '1/4 "%08X"'`
	END=`dd if="${DATAFILE}" ibs=4 skip=11 count=1 | hexdump -v -e '1/4 "%08X"'`
#
	SIZE=$(( 0x${END} - 0x${START} ))
#
	echo "zImage recognized with start 0x${START}, end 0x${END} and size ${SIZE}."
	TMPFILE='zImage'
}
mv "${DATAFILE}" "${TMPFILE}"

# ToDo: extract Image from zImage
# http://openinkpot.org/wiki/Documentation/ZImageFormat

echo ">>> ${UIMAGE} extracted to ${TMPFILE}"
