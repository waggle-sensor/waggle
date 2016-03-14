#!/bin/bash
echo "#define CURRENT_TIME "$(echo $(date +%s)+12 | bc) > rtc_conf.cpp
echo "#define SET_RTC_TIME" >> rtc_conf.cpp
cat rtc_conf.cpp
