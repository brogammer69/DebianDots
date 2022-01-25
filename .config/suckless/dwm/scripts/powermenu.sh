#!/bin/bash

# all \e[numberm are color codes
# menu
echo -e "\t\t\e[1m\e[34mPower Menu:"
echo -e "\e[1m\e[32mSelect an option:"
echo -e "\t\e[31mp (power off)"
echo -e "\t\e[33mr (reboot)"
echo -e "\t\e[34ms (suspend)"
echo -e "\t\e[35mh (hibernate)"
echo -e "\t\e[36ml (lock)"
echo -e "\t\e[32mc (cancel)"
echo -e "\e[0m"

# read user input
read -p  $'\e[1m\e[34mEnter your choice\e[0m: ' -n 1 answer
echo 

# conditional
if [ "$answer" == "p" ]; then
    systemctl poweroff
elif [ "$answer" == "r" ]; then
	    systemctl reboot
elif [ "$answer" == "s" ]; then
    systemctl suspend
elif [ "$answer" == "h" ]; then
    systemctl hibernate
elif [ "$answer" == "l" ]; then
    slock
else
    exit
fi
