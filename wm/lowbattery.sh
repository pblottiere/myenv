#!/bin/bash
#
# low battery warning
#

BATTERY=/sys/class/power_supply/BAT0

while true; do
  REM=`grep "POWER_SUPPLY_CHARGE_NOW" $BATTERY/uevent | awk -F= '{ print $2 }'`
  FULL=`grep "POWER_SUPPLY_CHARGE_FULL_DESIGN" $BATTERY/uevent | awk -F= '{ print $2 }'`
  PERCENT=`echo $(( $REM * 100 / $FULL ))`

  if [ $PERCENT -le "10" ]; then
    /usr/bin/i3-nagbar -m "Low battery"
  fi
  sleep 300
done
