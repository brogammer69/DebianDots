#!/bin/sh

# /etc/X11/xinit/xinitrc
#
# global xinitrc file, used by all X sessions started by xinit (startx)

# invoke global X session script
./etc/X11/Xsession

# All the programs that were starting here has been moved to ~/.local/share/dwm/autostart.sh

#for some wierd andriod-studio bug in dwm
export _JAVA_AWT_WM_NONREPARENTING=1

while true; do
	dwm >/dev/null 2>&1
done

exec dwm
