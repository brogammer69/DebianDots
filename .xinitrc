#!/bin/sh

# /etc/X11/xinit/xinitrc
#
# global xinitrc file, used by all X sessions started by xinit (startx)

# invoke global X session script
./etc/X11/Xsession

#check to see if second monitor is connected
~/.local/bin/detechscreen &

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

#for not automatically locking screen while playing videos
# xautolock -time 12 -detectsleep -corners 0+0- -cornerdelay 1 -cornerredelay 5 -cornersize 10 -secure -notify 15 -notifier /home/ghost/.local/bin/notifysleep -locker 'loginctl suspend' &

# locking using xidlehook. (compiled from source)
# Run xidlehook
export PRIMARY_DISPLAY="$(xrandr | awk '/ connected/{print $1}')"
xidlehook --not-when-fullscreen --not-when-audio --timer 60 'xrandr --output "$PRIMARY_DISPLAY" --brightness 0' 'xrandr --output "$PRIMARY_DISPLAY" --brightness 1' --timer 20 'slock' 'xrandr --output "$PRIMARY_DISPLAY" --brightness 1' --timer 600 'loginctl suspend' '' &

# locking using xss-lock
xss-lock slock &


#for clipboard manager. This is the daemon
clipmenud &

#for some wierd andriod-studio bug in dwm
export _JAVA_AWT_WM_NONREPARENTING=1

while true; do
	dwm >/dev/null 2>&1
done

exec dwm
