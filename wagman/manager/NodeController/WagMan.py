import collections
import time
import datetime

########################################################################
#           Edit CORE (SysMon, NC, network switch) parameters here.
#           Do not change the order or number of items.
#           (if you must change it, you need to modify the
#            "get_params_nc()" function in SysMon)
########################################################################
params_SysMon = collections.OrderedDict()

# Min: 1, max: 65535
params_SysMon['baud rate'] = 57600

# Be courteous to the SysMon...it has very little RAM
# Min: total num of chars in each field + 1 for each field
params_SysMon['SysMon RX buffer size (characters)'] = 150

# Min: 1, max: 255
params_SysMon['max num of SOS boot attempts'] = 3

# How many times NC and GNs should try to boot
# Min: 1, max: 255
params_SysMon['max num of subsystem boot attempts'] = 4

# Min: 1, max: 65535
params_SysMon['boot time for NC (seconds)'] = 10
# Min: 1, max: 255
params_SysMon['boot time for ethernet switch (seconds)'] = 6

# Min: 1, max: 255
params_SysMon['heartbeat timeout (NC) (seconds)'] = 5
params_SysMon['heartbeat timeout (switch) (seconds)'] = 3

# Min: 1, max: 255
params_SysMon['bad temperature timeout (SysMon) (seconds)'] = 10
params_SysMon['bad temperature timeout (NC) (seconds)'] = 15
params_SysMon['bad temperature timeout (switch) (seconds)'] = 15

# Min: 1, max: 255
params_SysMon['bad current timeout (SysMon) (seconds)'] = 6
params_SysMon['bad current timeout (NC) (seconds)'] = 6
params_SysMon['bad current timeout (switch) (seconds)'] = 6

# Min: 15, max: 8000
params_SysMon['noise ceiling for current sensors (mA)'] = 15

# Min: -32768, max: 32767
params_SysMon['temperature min (SysMon) (Celsius)'] = -20
params_SysMon['temperature max (SysMon) (Celsius)'] = 140
params_SysMon['temperature min (NC) (Celsius)'] = -20
params_SysMon['temperature max (NC) (Celsius)'] = 140
params_SysMon['temperature min (switch) (Celsius)'] = -20
params_SysMon['temperature max (switch) (Celsius)'] = 140

# Min: 0, max: 100
params_SysMon['relative humidity min (SysMon) (%)'] = 0
params_SysMon['relative humidity max (SysMon) (%)'] = 100

# Min: 1, max: 8000
params_SysMon['maximum current draw (SysMon) (mA)'] = 500
params_SysMon['maximum current draw (NC) (mA)'] = 4000
params_SysMon['maximum current draw (switch) (mA)'] = 1500
########################################################################

########################################################################
#           Edit GUEST NODE parameters here.
#           Do not change the order or number of items.
#           (if you must change it, you need to modify the
#            "get_params_gn()" function in SysMon)
########################################################################
params_GuestNodes = collections.OrderedDict()

# Present: 1, not present: 0
params_GuestNodes['present (GN 1)'] = 1
params_GuestNodes['present (GN 2)'] = 0
params_GuestNodes['present (GN 3)'] = 0

# Min: 1, max: 255
# If a guest node is not present, its value will be ignored
params_GuestNodes['heartbeat timeout (GN 1) (seconds)'] = 10
params_GuestNodes['heartbeat timeout (GN 2) (seconds)'] = 10
params_GuestNodes['heartbeat timeout (GN 3) (seconds)'] = 10

# Min: 1, max: 255
# If a guest node is not present, its value will be ignored
params_GuestNodes['bad temperature timeout (GN 1) (seconds)'] = 15
params_GuestNodes['bad temperature timeout (GN 2) (seconds)'] = 15
params_GuestNodes['bad temperature timeout (GN 3) (seconds)'] = 15

# Min: 1, max: 255
# If a guest node is not present, its value will be ignored
params_GuestNodes['bad current timeout (GN 1) (seconds)'] = 5
params_GuestNodes['bad current timeout (GN 2) (seconds)'] = 5
params_GuestNodes['bad current timeout (GN 3) (seconds)'] = 5

# Min: -32768, max: 32767
# If a guest node is not present, its value will be ignored
params_GuestNodes['temperature min (GN 1) (Celsius)'] = -20
params_GuestNodes['temperature max (GN 1) (Celsius)'] = 140
params_GuestNodes['temperature min (GN 2) (Celsius)'] = -20
params_GuestNodes['temperature max (GN 2) (Celsius)'] = 140
params_GuestNodes['temperature min (GN 3) (Celsius)'] = -20
params_GuestNodes['temperature max (GN 3) (Celsius)'] = 140

# Min: 1, max: 8000
# If a guest node is not present, its value will be ignored
params_GuestNodes['maximum current draw (GN 1) (mA)'] = 4000
params_GuestNodes['maximum current draw (GN 2) (mA)'] = 4000
params_GuestNodes['maximum current draw (GN 3) (mA)'] = 4000
########################################################################

########################################################################
#           Lookup table for thermistors
#
#           It is too expensive to convert (mathematically or with a
#           lookup table) the temperature to an ADC value onboard the
#           SysMon, so we do it here and send the appropriate ADC
#           value instead.
########################################################################
thermistor_LUT = {
    0: -55,
    4: -54.95,
    8: -54.90,
    11: -54.85,
    15: -54.80,
    19: -54.75,
    22: -54.70,
    26: -54.65,
    30: -54.60,
    33: -54.55,
    37: -54.50,
    41: -54.45,
    44: -54.40,
    48: -54.35,
    52: -54.30,
    55: -54.25,
    59: -54.20,
    62: -54.15,
    66: -54.10,
    69: -54.05,
    73: -54,
    76: -53.95,
    80: -53.90,
    83: -53.85,
    87: -53.80,
    90: -53.75,
    94: -53.70,
    97: -53.65,
    100: -53.60,
    104: -53.55,
    107: -53.50,
    110: -53.45,
    114: -53.40,
    117: -53.35,
    120: -53.30,
    124: -53.25,
    127: -53.20,
    130: -53.15,
    133: -53.10,
    137: -53.05,
    140: -53,
    143: -52.95,
    146: -52.90,
    150: -52.85,
    153: -52.80,
    156: -52.75,
    159: -52.70,
    162: -52.65,
    165: -52.60,
    168: -52.55,
    172: -52.50,
    175: -52.45,
    178: -52.40,
    181: -52.35,
    184: -52.30,
    187: -52.25,
    190: -52.20,
    193: -52.15,
    196: -52.10,
    199: -52.05,
    202: -52,
    205: -51.95,
    208: -51.90,
    211: -51.85,
    214: -51.80,
    217: -51.75,
    220: -51.70,
    222: -51.65,
    225: -51.60,
    228: -51.55,
    231: -51.50,
    234: -51.45,
    237: -51.40,
    240: -51.35,
    242: -51.30,
    245: -51.25,
    248: -51.20,
    251: -51.15,
    254: -51.10,
    256: -51.05,
    259: -51,
    262: -50.95,
    265: -50.90,
    267: -50.85,
    270: -50.80,
    273: -50.75,
    275: -50.70,
    278: -50.65,
    281: -50.60,
    283: -50.55,
    286: -50.50,
    289: -50.45,
    291: -50.40,
    294: -50.35,
    297: -50.30,
    299: -50.25,
    302: -50.20,
    304: -50.15,
    307: -50.10,
    309: -50.05,
    312: -50,
    315: -49.95,
    317: -49.90,
    320: -49.85,
    322: -49.80,
    325: -49.75,
    327: -49.70,
    330: -49.65,
    332: -49.60,
    335: -49.55,
    337: -49.50,
    339: -49.45,
    342: -49.40,
    344: -49.35,
    347: -49.30,
    349: -49.25,
    351: -49.20,
    354: -49.15,
    356: -49.10,
    359: -49.05,
    361: -49,
    363: -48.95,
    366: -48.90,
    368: -48.85,
    370: -48.80,
    373: -48.75,
    375: -48.70,
    377: -48.65,
    379: -48.60,
    382: -48.55,
    384: -48.50,
    386: -48.45,
    388: -48.40,
    391: -48.35,
    393: -48.30,
    395: -48.25,
    397: -48.20,
    400: -48.15,
    402: -48.10,
    404: -48.05,
    406: -48,
    408: -47.95,
    410: -47.90,
    413: -47.85,
    415: -47.80,
    417: -47.75,
    419: -47.70,
    421: -47.65,
    423: -47.60,
    425: -47.55,
    427: -47.50,
    430: -47.45,
    432: -47.40,
    434: -47.35,
    436: -47.30,
    438: -47.25,
    440: -47.20,
    442: -47.15,
    444: -47.10,
    446: -47.05,
    448: -47,
    450: -46.95,
    452: -46.90,
    454: -46.85,
    456: -46.80,
    458: -46.75,
    460: -46.70,
    462: -46.65,
    464: -46.60,
    466: -46.55,
    468: -46.50,
    470: -46.45,
    472: -46.40,
    473: -46.35,
    475: -46.30,
    477: -46.25,
    479: -46.20,
    481: -46.15,
    483: -46.10,
    485: -46.05,
    487: -46,
    489: -45.95,
    490: -45.90,
    492: -45.85,
    494: -45.80,
    496: -45.75,
    498: -45.70,
    500: -45.65,
    501: -45.60,
    503: -45.55,
    505: -45.50,
    507: -45.45,
    509: -45.40,
    510: -45.35,
    512: -45.30,
    514: -45.25,
    516: -45.20,
    517: -45.15,
    519: -45.10,
    521: -45.05,
    523: -45,
    524: -44.95,
    526: -44.90,
    528: -44.85,
    529: -44.80,
    531: -44.75,
    533: -44.70,
    535: -44.65,
    536: -44.60,
    538: -44.55,
    540: -44.50,
    541: -44.45,
    543: -44.40,
    544: -44.35,
    546: -44.30,
    548: -44.25,
    549: -44.20,
    551: -44.15,
    553: -44.10,
    554: -44.05,
    556: -44,
    557: -43.95,
    559: -43.90,
    561: -43.85,
    562: -43.80,
    564: -43.75,
    565: -43.70,
    567: -43.65,
    568: -43.60,
    570: -43.55,
    572: -43.50,
    573: -43.45,
    575: -43.40,
    576: -43.35,
    578: -43.30,
    579: -43.25,
    581: -43.20,
    582: -43.15,
    584: -43.10,
    585: -43.05,
    587: -43,
    588: -42.95,
    590: -42.90,
    591: -42.85,
    593: -42.80,
    594: -42.75,
    595: -42.70,
    597: -42.65,
    598: -42.60,
    600: -42.55,
    601: -42.50,
    603: -42.45,
    604: -42.40,
    606: -42.35,
    607: -42.30,
    608: -42.25,
    610: -42.20,
    611: -42.15,
    613: -42.10,
    614: -42.05,
    615: -42,
    617: -41.95,
    618: -41.90,
    619: -41.85,
    621: -41.80,
    622: -41.75,
    623: -41.70,
    625: -41.65,
    626: -41.60,
    627: -41.55,
    629: -41.50,
    630: -41.45,
    631: -41.40,
    633: -41.35,
    634: -41.30,
    635: -41.25,
    637: -41.20,
    638: -41.15,
    639: -41.10,
    641: -41.05,
    642: -41,
    643: -40.95,
    644: -40.90,
    646: -40.85,
    647: -40.80,
    648: -40.75,
    649: -40.70,
    651: -40.65,
    652: -40.60,
    653: -40.55,
    654: -40.50,
    656: -40.45,
    657: -40.40,
    658: -40.35,
    659: -40.30,
    661: -40.25,
    662: -40.20,
    663: -40.15,
    664: -40.10,
    665: -40.05,
    667: -40,
    668: -39.95,
    669: -39.90,
    670: -39.85,
    671: -39.80,
    672: -39.75,
    674: -39.70,
    675: -39.65,
    676: -39.60,
    677: -39.55,
    678: -39.50,
    679: -39.45,
    680: -39.40,
    682: -39.35,
    683: -39.30,
    684: -39.25,
    685: -39.20,
    686: -39.15,
    687: -39.10,
    688: -39.05,
    689: -39,
    691: -38.95,
    692: -38.90,
    693: -38.85,
    694: -38.80,
    695: -38.75,
    696: -38.70,
    697: -38.65,
    698: -38.60,
    699: -38.55,
    700: -38.50,
    701: -38.45,
    702: -38.40,
    703: -38.35,
    705: -38.30,
    706: -38.25,
    707: -38.20,
    708: -38.15,
    709: -38.10,
    710: -38.05,
    711: -38,
    712: -37.95,
    713: -37.90,
    714: -37.85,
    715: -37.80,
    716: -37.75,
    717: -37.70,
    718: -37.65,
    719: -37.60,
    720: -37.55,
    721: -37.50,
    722: -37.45,
    723: -37.40,
    724: -37.35,
    725: -37.30,
    726: -37.25,
    727: -37.20,
    728: -37.15,
    729: -37.10,
    730: -37.05,
    731: -37,
    732: -36.90,
    733: -36.85,
    734: -36.80,
    735: -36.75,
    736: -36.70,
    737: -36.65,
    738: -36.60,
    739: -36.55,
    740: -36.50,
    741: -36.45,
    742: -36.40,
    743: -36.35,
    744: -36.30,
    745: -36.25,
    746: -36.15,
    747: -36.10,
    748: -36.05,
    749: -36,
    750: -35.95,
    751: -35.90,
    752: -35.85,
    753: -35.75,
    754: -35.70,
    755: -35.65,
    756: -35.60,
    757: -35.55,
    758: -35.50,
    759: -35.40,
    760: -35.35,
    761: -35.30,
    762: -35.25,
    763: -35.20,
    764: -35.15,
    765: -35.05,
    766: -35,
    767: -34.95,
    768: -34.90,
    769: -34.85,
    770: -34.75,
    771: -34.70,
    772: -34.65,
    773: -34.60,
    774: -34.50,
    775: -34.45,
    776: -34.40,
    777: -34.35,
    778: -34.25,
    779: -34.20,
    780: -34.15,
    781: -34.05,
    782: -34,
    783: -33.95,
    784: -33.85,
    785: -33.80,
    786: -33.75,
    787: -33.65,
    788: -33.60,
    789: -33.55,
    790: -33.45,
    791: -33.40,
    792: -33.35,
    793: -33.25,
    794: -33.20,
    795: -33.15,
    796: -33.05,
    797: -33,
    798: -32.90,
    799: -32.85,
    800: -32.80,
    801: -32.70,
    802: -32.65,
    803: -32.55,
    804: -32.50,
    805: -32.45,
    806: -32.35,
    807: -32.30,
    808: -32.20,
    809: -32.15,
    810: -32.05,
    811: -32,
    812: -31.90,
    813: -31.85,
    814: -31.75,
    815: -31.70,
    816: -31.60,
    817: -31.55,
    818: -31.45,
    819: -31.35,
    820: -31.30,
    821: -31.20,
    822: -31.15,
    823: -31.05,
    824: -31,
    825: -30.90,
    826: -30.80,
    827: -30.75,
    828: -30.65,
    829: -30.55,
    830: -30.50,
    831: -30.40,
    832: -30.30,
    833: -30.25,
    834: -30.15,
    835: -30.05,
    836: -30,
    837: -29.90,
    838: -29.80,
    839: -29.70,
    840: -29.65,
    841: -29.55,
    842: -29.45,
    843: -29.35,
    844: -29.30,
    845: -29.20,
    846: -29.10,
    847: -29,
    848: -28.90,
    849: -28.80,
    850: -28.70,
    851: -28.65,
    852: -28.55,
    853: -28.45,
    854: -28.35,
    855: -28.25,
    856: -28.15,
    857: -28.05,
    858: -27.95,
    859: -27.85,
    860: -27.75,
    861: -27.65,
    862: -27.55,
    863: -27.45,
    864: -27.35,
    865: -27.25,
    866: -27.15,
    867: -27.05,
    868: -26.95,
    869: -26.85,
    870: -26.70,
    871: -26.60,
    872: -26.50,
    873: -26.40,
    874: -26.30,
    875: -26.15,
    876: -26.05,
    877: -25.95,
    878: -25.85,
    879: -25.70,
    880: -25.60,
    881: -25.50,
    882: -25.35,
    883: -25.25,
    884: -25.15,
    885: -25,
    886: -24.90,
    887: -24.80,
    888: -24.65,
    889: -24.55,
    890: -24.40,
    891: -24.30,
    892: -24.15,
    893: -24,
    894: -23.90,
    895: -23.75,
    896: -23.65,
    897: -23.50,
    898: -23.35,
    899: -23.25,
    900: -23.10,
    901: -22.95,
    902: -22.80,
    903: -22.70,
    904: -22.55,
    905: -22.40,
    906: -22.25,
    907: -22.10,
    908: -21.95,
    909: -21.80,
    910: -21.65,
    911: -21.50,
    912: -21.35,
    913: -21.20,
    914: -21.05,
    915: -20.90,
    916: -20.75,
    917: -20.60,
    918: -20.40,
    919: -20.25,
    920: -20.10,
    921: -19.90,
    922: -19.75,
    923: -19.60,
    924: -19.40,
    925: -19.25,
    926: -19.05,
    927: -18.85,
    928: -18.70,
    929: -18.50,
    930: -18.35,
    931: -18.15,
    932: -17.95,
    933: -17.75,
    934: -17.55,
    935: -17.35,
    936: -17.15,
    937: -16.95,
    938: -16.75,
    939: -16.55,
    940: -16.35,
    941: -16.15,
    942: -15.90,
    943: -15.70,
    944: -15.50,
    945: -15.25,
    946: -15,
    947: -14.80,
    948: -14.55,
    949: -14.30,
    950: -14.10,
    951: -13.85,
    952: -13.60,
    953: -13.35,
    954: -13.05,
    955: -12.80,
    956: -12.55,
    957: -12.30,
    958: -12,
    959: -11.70,
    960: -11.45,
    961: -11.15,
    962: -10.85,
    963: -10.55,
    964: -10.25,
    965: -9.95,
    966: -9.60,
    967: -9.30,
    968: -8.95,
    969: -8.65,
    970: -8.30,
    971: -7.95,
    972: -7.60,
    973: -7.20,
    974: -6.85,
    975: -6.45,
    976: -6.05,
    977: -5.65,
    978: -5.25,
    979: -4.85,
    980: -4.40,
    981: -3.95,
    982: -3.50,
    983: -3.05,
    984: -2.55,
    985: -2.05,
    986: -1.55,
    987: -1,
    988: -0.50,
    989: 0.10,
    990: 0.65,
    991: 1.25,
    992: 1.85,
    993: 2.50,
    994: 3.20,
    995: 3.85,
    996: 4.60,
    997: 5.35,
    998: 6.10,
    999: 6.95,
    1000: 7.80,
    1001: 8.70,
    1002: 9.65,
    1003: 10.60,
    1004: 11.65,
    1005: 12.80,
    1006: 13.95,
    1007: 15.20,
    1008: 16.55,
    1009: 18.05,
    1010: 19.60,
    1011: 21.30,
    1012: 23.20,
    1013: 25.25,
    1014: 27.55,
    1015: 30.15,
    1016: 33.10,
    1017: 36.55,
    1018: 40.70,
    1019: 45.75,
    1020: 52.35,
    1021: 61.55,
    1022: 76.40,
    1023: 80
}
########################################################################





########################################################################
import serial

# Establish serial connection to SysMon
ser_SysMon = serial.Serial('/dev/arduinoMicro', params_SysMon['baud rate'], timeout = 10)
########################################################################
#           DO NOT TOUCH ANYTHING BELOW HERE
########################################################################
while True:
    # Receive line from SysMon
    incomingNotifier = ser_SysMon.readline().strip()

    print incomingNotifier

    # Did SysMon request parameters?
    if incomingNotifier == "$":
        # Send parameters
        for i in params_SysMon.keys():
            ser_SysMon.write(str(params_SysMon[i]))
            ser_SysMon.write(",")

        # Send terminator
        ser_SysMon.write("!")

    # Is SysMon about to send a status report?
    elif incomingNotifier == "@":
        # Wait for status report
        incomingStatus = ser_SysMon.readline().strip()

    # Is SysMon about to inform me of a problem?
    elif incomingNotifier == "#":
        # Wait for problem report
        incomingProblem = ser_SysMon.readline().strip()

    # Did SysMon request guest node info?
    elif incomingNotifier == "^":
        # Send guest node parameters
        for i in params_GuestNodes.keys():
            ser_SysMon.write(str(params_GuestNodes[i]))
            ser_SysMon.write(",")

    # Did SysMon request the current time?
    elif incomingNotifier == "*":
        # Get current time
        secondsSinceEpoch = time.time()
        timeStamp = datetime.datetime.fromtimestamp(secondsSinceEpoch).strftime('%Y,%m,%d,%H,%M,%S')
        ser_SysMon.write(timeStamp)

        # Send terminator
        ser_SysMon.write("!")

    # Clear incomingNotifier
    incomingNotifier = ''