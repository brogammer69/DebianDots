#!/bin/sh

# This file is ran by dwm while starting. 
# Dwm will autostart these programs before running itself.

#check to see if second monitor is connected
# ~/.local/bin/detechscreen &

#start some nice programs
feh --recursive --bg-fill --randomize ~/Media/Wallpapers/ &

# compisitor
# compton &
picom -f &

#for battery logentivity but meh!
/usr/sbin/tlp-start &

#for status bar 
#/home/ghost/.config/dwm-statusbar.sh &
dwm-statusbar &

#/home/ghost/.local/bin
suspender &

#for clipboard manager. This is the daemon
clipmenud &

