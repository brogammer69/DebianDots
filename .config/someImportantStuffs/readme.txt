if you are using systemd based distro and kernel version is < 6.2
copy wpa_supplicant.service and dhclient.service to /etc/systemd/system/ for wifi

if you are using systemd distro
copy suspend@.service to /etc/systemd/system/ for using slock at suspend


if you are using runnit based distro then
copy system-sleep dir to /etc/elogind for slock
