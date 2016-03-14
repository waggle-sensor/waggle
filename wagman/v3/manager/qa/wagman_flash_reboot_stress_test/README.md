# Test Scope and Coverage

# Test Setup Procedure


### Events Timeline
* T = 0      : Wagman Boots
* Boot + 35s : Wagman turns off all the ports, including C1+
* Boot + X1s : Wagman boots C1+
* Boot + X2s : C1+ starts stress
* Boot + X3s : Wagman boots XU4
* Boot + X4s : XU4 starts stress
* Boot + X5s : C1+ finishes stress
* Boot + X6s : XU4 finishes stress
* Boot + X7s : XU4 shutsdown
* Boot + X8s : C1+ starts Wagman reflash
* Boot + X10s : Wagman reboots
* Boot + X11s : C1+ shutsdown (if reflash successful, else stays powered on.)
* Boot + X12s : Wagman turns off all the ports, including C1+


###Example Events Verification
* 140.221.10.98 - - [14/Mar/2016:11:25:44 -0500] "GET /flashsuccess_Wagman/node?=C1P36890 HTTP/1.1" 404 458 "-" "curl/7.35.0" </br>
__{end of previous flash}__ </br></br>
__{current cycle}__
* 140.221.10.98 - - [14/Mar/2016:11:28:01 -0500] "GET /startingstress/node?=C1P36890 HTTP/1.1" 404 453 "-" "curl/7.35.0"
* 140.221.10.98 - - [14/Mar/2016:11:29:05 -0500] "GET /startingstress/node?=XU411316 HTTP/1.1" 404 453 "-" "curl/7.35.0"
* 140.221.10.98 - - [14/Mar/2016:11:31:12 -0500] "GET /endstress/node?=C1P36890 HTTP/1.1" 404 448 "-" "curl/7.35.0"
* 140.221.10.98 - - [14/Mar/2016:11:32:16 -0500] "GET /endstress/node?=XU411316 HTTP/1.1" 404 448 "-" "curl/7.35.0"
* 140.221.10.98 - - [14/Mar/2016:11:32:27 -0500] "GET /startflash_Wagman/node?=C1P36890 HTTP/1.1" 404 456 "-" "curl/7.35.0"
* 140.221.10.98 - - [14/Mar/2016:11:32:33 -0500] "GET /endflash_Wagman/node?=C1P36890 HTTP/1.1" 404 454 "-" "curl/7.35.0"
* 140.221.10.98 - - [14/Mar/2016:11:32:33 -0500] "GET /flashsuccess_Wagman/node?=C1P36890 HTTP/1.1" 404 458 "-" "curl/7.35.0" </br>
</br>
__{start of next cycle}__
* 140.221.10.98 - - [14/Mar/2016:11:34:00 -0500] "GET /startingstress/node?=C1P36890 HTTP/1.1" 404 453 "-" "curl/7.35.0"
