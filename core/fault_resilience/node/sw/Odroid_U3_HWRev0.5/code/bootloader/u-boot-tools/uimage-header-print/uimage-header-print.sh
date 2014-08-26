#!/bin/sh

##
## Modified from extract_uImage.sh of Matthias Buecher (http://www.maddes.net/)
##


UIMAGE=$1

OUT_DIR=$2
if [ -z ${OUT_DIR} ]
then 
    ${OUT_DIR}=`pwd`
else 
    if [ ! -e ${OUT_DIR} ]
    then 
        mkdir -p "${OUT_DIR}"
    fi
fi

# check for uImage magic word
# http://git.denx.de/cgi-bin/gitweb.cgi?p=u-boot.git;a=blob;f=include/image.h
# #define IH_MAGIC    0x27051956    /* Image Magic Number     */
UIMAGE_MAGIC='27051956'
echo "==== Checking for uImage magic word [${UIMAGE_MAGIC}]."
MAGIC=`dd if="${UIMAGE}" ibs=4 count=1 | hexdump -v -e '1/1 "%02X"'`
[ "${UIMAGE_MAGIC}" != "${MAGIC}" ]  && {
    echo "==== MAGIC is [${MAGIC}]. Not an uImage."
    exit 1
}
echo "==== uImage recognized."

## Split header and data
## http://www.isysop.com/unpacking-and-repacking-u-boot-uimage-files/

#extract header from uImage
HEADERFILE="${OUT_DIR}/uImage.header"
echo "==== Extracting header to ${HEADERFILE}"
dd if="${UIMAGE}" of="${HEADERFILE}" ibs=64 count=1

# uint32_t    ih_magic;         /* Image Header Magic Number */
IH_MAGIC=`dd if=${HEADERFILE} ibs=4 count=1 | hexdump -v -e '1/1 "%02X"'`
# uint32_t    ih_hcrc;          /* Image Header CRC Checksum */
IH_HCRC=`dd if=${HEADERFILE} ibs=4 skip=1 count=1 | hexdump -v -e '1/1 "%02X"'`
# uint32_t    ih_time;          /* Image Creation Timestamp  */
IH_TIME=`dd if=${HEADERFILE} ibs=4 skip=2 count=1 | hexdump -v -e '1/1 "%02X"'`
# uint32_t    ih_size;          /* Image Data Size           */
IH_SIZE=`dd if=${HEADERFILE} ibs=4 skip=3 count=1 | hexdump -v -e '1/1 "%02X"'`
# uint32_t    ih_load;          /* Data     Load  Address    */
IH_LOAD=`dd if=${HEADERFILE} ibs=4 skip=4 count=1 | hexdump -v -e '1/1 "%02X"'`
# uint32_t    ih_ep;            /* Entry Point Address       */
IH_EP=`dd if=${HEADERFILE} ibs=4 skip=5 count=1 | hexdump -v -e '1/1 "%02X"'`
# uint32_t    ih_dcrc;          /* Image Data CRC Checksum   */
IH_DCRC=`dd if=${HEADERFILE} ibs=4 skip=6 count=1 | hexdump -v -e '1/1 "%02X"'`
# uint8_t     ih_os;            /* Operating System          */
IH_OS=`dd if=${HEADERFILE} ibs=1 skip=28 count=1 | hexdump -v -e '1/1 "%02X"'`
# uint8_t     ih_arch;          /* CPU architecture          */
IH_ARCH=`dd if=${HEADERFILE} ibs=1 skip=29 count=1 | hexdump -v -e '1/1 "%02X"'`
# uint8_t     ih_type;          /* Image Type                */
IH_TYPE=`dd if=${HEADERFILE} ibs=1 skip=30 count=1 | hexdump -v -e '1/1 "%02X"'`
# uint8_t     ih_comp;          /* Compression Type          */
IH_COMP=`dd if=${HEADERFILE} ibs=1 skip=31 count=1 | hexdump -v -e '1/1 "%02X"'`
# #define IH_NMLEN    32            /* Image Name Length      */
# uint8_t     ih_name[IH_NMLEN];    /* Image Name            */
IH_NAME=`dd if=${HEADERFILE} ibs=1 skip=32 count=32 | hexdump -v -e '1/1 "%_p"'`

echo ""
echo "=== uImage Header ============================"
echo "= Image Header Magic Number: ${IH_MAGIC}"
echo "= Image Header CRC Checksum: ${IH_HCRC}"
echo "= Image Creation Timestamp: ${IH_TIME}"
echo "= Image Data Size: ${IH_SIZE}"
echo "= Data Load Address: ${IH_LOAD}"
echo "= Entry Point Address: ${IH_EP}"
echo "= Image Data CRC Checksum: ${IH_DCRC}"
echo "= Operating System: ${IH_OS}"
echo "= CPU architecture: ${IH_ARCH}"
echo "= Image Type: ${IH_TYPE}"
echo "= Compression Type: ${IH_COMP}"
echo "= Image Name: ${IH_NAME}"
echo "==========================================="
echo ""

rm ${HEADERFILE}


# extract data from uImage
DATAFILE="${OUT_DIR}/uImage.data"
echo "==== Extracting data to ${DATAFILE}"
dd if="${UIMAGE}" of="${DATAFILE}" ibs=64 skip=1


# check for ARM mach type ( xx 1C A0 E3 xx 10 81 E3 )
# http://www.simtec.co.uk/products/SWLINUX/files/booting_article.html#d0e600
echo "==== Checking for ARM mach-type..."
MAGIC=`dd if="${DATAFILE}" ibs=1 skip=1 count=3 | hexdump -v -e '1/1 "%02X"'`
[ '1CA0E3' = "${MAGIC}" ] && {
	MAGIC=`dd if="${DATAFILE}" ibs=1 skip=5 count=3 | hexdump -v -e '1/1 "%02X"'`
	[ '1081E3' = "${MAGIC}" ] && {
		echo '==== ARM mach-type header recognized.'
		echo '==== Extracting mach-type header...'
		dd if="${DATAFILE}" of="uImage.mach-type" ibs=8 count=1
#
		ARCH=`hexdump -v -e '1/1 "%02X "' uImage.mach-type`
		echo "==== The mach-type is: ${ARCH}"
#
		echo '==== Stripping mach-type header...'
		TMPFILE='uImage.tmp'
		dd if="${DATAFILE}" of="${TMPFILE}" ibs=8 skip=1
		rm -f "${DATAFILE}"
		mv "${TMPFILE}" "${DATAFILE}"
	}
}

# check for zImage, otherwise assume Image
# http://www.simtec.co.uk/products/SWLINUX/files/booting_article.html#d0e309
TMPFILE='Image'
echo '==== Checking for zImage...'
MAGIC=`dd if="${DATAFILE}" ibs=4 skip=9 count=1 | hexdump -v -e '1/1 "%02X"'`
[ '18286F01' = "${MAGIC}" ] && {
	START=`dd if="${DATAFILE}" ibs=4 skip=10 count=1 | hexdump -v -e '1/4 "%08X"'`
	END=`dd if="${DATAFILE}" ibs=4 skip=11 count=1 | hexdump -v -e '1/4 "%08X"'`
#
	SIZE=$(( 0x${END} - 0x${START} ))
#
	echo "==== zImage recognized with start 0x${START}, end 0x${END} and size ${SIZE}."
	TMPFILE='zImage'
}
mv "${DATAFILE}" "${TMPFILE}"

# ToDo: extract Image from zImage
# http://openinkpot.org/wiki/Documentation/ZImageFormat

echo "==== >>> ${UIMAGE} extracted to ${TMPFILE}"
