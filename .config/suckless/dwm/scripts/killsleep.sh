#!/bin/sh

#Refresh the dwm-statusbar
#this is done by killing ghe sleep in the bar script

kill "$(pstree -lp | grep -- -dwm-statusbar\([0-9] | sed "s/.*sleep(\([0-9]\+\)).*/\1/"))"
