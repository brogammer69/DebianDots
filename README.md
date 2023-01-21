# My dotfiles for Debian setup
The setup is a minimal install of debian with dwm, st, dmenu, slock.

---
## Patches used in dwm
fullgaps
pertag
swallow
rotatestack
statusallmons
attachasideandbelow
preservetag
status2d

## Required packages to build my build of dwm
libx11-dev
libxft-dev
libxinerama-dev
libxcb-res0-dev
libx11-xcb-dev

---
## Required package to build slock
libxrandr-dev

---
## Some installed utility packages
ly - the minimal display manager
xautolock - tool to lock the display if idle
clipmenu - clipboard history manager paired with dmenu
dunst and notify-send - for notifications
feh - for setting wallpapers
xdotool - for moving mouse curosr to primary monitor in dual monitor setup

## Steps for setup
1. First install minimal iso (or any other)
2. Make sure you are connected to internet. If not use usb tathering.
3. Install sudo and uncomment appropriate line to give yourself appropriate privilege. Reboot
4. Install git, neovim, picom (or compton), linux-headers, build-essentials.
5. Install xorg.
6. Clone this repo into home directory of your user(or wherever you prefer)
7. Copy the contents of this repo to similar places within your home directory.
8. Install above utility packages. 
9. Install dwm, st, dmenu, slock from the repo
10. Copy .xinitrc from the repo to your home directory
11. Reboot
