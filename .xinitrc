#!/bin/sh

# /etc/X11/xinit/xinitrc
#
# global xinitrc file, used by all X sessions started by xinit (startx)

# invoke global X session script
./etc/X11/Xsession


#start some nice programs
nitrogen --set-zoom-fill --random ~/Media/Wallpapers/ &
compton &

#for battery logentivity but meh!
/usr/sbin/tlp start &

#for status bar 
/home/ghost/.config/dwm-statusbar.sh &

#for not automatically locking screen while playing videos
xautolock -time 10 -locker 'systemctl suspend' -corners 0+0- -cornerdelay 1 -cornerredelay 5 -cornersize 10 -secure &

while true; do
	dwm >/dev/null 2>&1
done

exec dwm
