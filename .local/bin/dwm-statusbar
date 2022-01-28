#!/bin/bash

# ~/bin/dwm-statusbar
# Adapted from w0ng status bar: https://github.com/w0ng/bin
# Adapted from jasonwryan status bar: https://bitbucket.org/jasonwryan/shiv/src/1ad5950c3108a4e5a9dcb78888a1ccfeb9252b45/Scripts/dwm-status?at=default

#print_song_info() {
#  track="$(mpc current)"
#  artist="${track%%- *}"
#  title="${track##*- }"
#  [[ -n "$artist" ]] && echo -e "${color6}ê${color0}${artist}${color7}${title} ${color0}|"
#}

print_power() {
  status="$(cat /sys/class/power_supply/AC/online)"
  battery="$(cat /sys/class/power_supply/BAT0/capacity)"
  timer="$(acpi -b | grep "Battery" | awk '{print $5}' | cut -c 1-5)"
  if [ "${status}" == 1 ]; then
    echo -ne "Batt:${battery}%"
  else
    echo -ne "Batt:${battery}%"
  fi
}

print_ram() {
	mem_used=$(free -h | awk '/Mem:/ { print $3 }' | cut -f1 -d 'i')
	mem_free=$(free -h | awk '/Mem:/ { print $2 }' | cut -f1 -d 'i')
	echo  -ne " $mem_used/$mem_free"
}

print_wifiqual() {
  wifiessid="$(/sbin/iwconfig 2>/dev/null | awk '/wlx4401bba0b98f/' | grep ESSID | cut -d: -f2)"
  wifiawk="$(echo $wifiessid | awk -F',' '{gsub(/"/, "", $1); print $1}')"
  wificut="$(echo $wifiawk | cut -d' ' -f1)"
  echo -ne " ${wificut}"
}

print_hddfree() {
  hddfree="$(df -Ph /dev/sdb1 | awk '$3 ~ /[0-9]+/ {print $4}')"
  echo -ne " ${hddfree}"
}

 print_volume(){
    mix=`amixer get Master | tail -1`
    vol="$(amixer get Master | tail -n1 | sed -r 's/.*\[(.*)%\].*/\1/')"
    if [[ $mix == *\[off\]* ]]; then
      #red 2                                                
      echo -e ""
    elif [[ $mix == *\[on\]* ]]; then
      #green 9
      echo -e  " ${vol}%"
    else
      #yellow6
      echo -e ""
    fi
 }

print_brightness() {
	echo -ne  " $(xbacklight -get | sed 's/\.[0-9]*$//')"
}

print_datetime() {
  dateonly="$(date "+%a, %d %b")"
  timeonly="$(date "+%I:%M%p")"
  echo -ne " ${dateonly}  ${timeonly}"
}

print_cputemp() {
    cputemp="$(sensors|awk 'BEGIN{i=0;t=0;b=0}/id [0-9]/{b=$4};/Core/{++i;t+=$3}END{if(i>0){printf("%0.1f\n",t/i)}else{sub(/[^0-9.]/,"",b);print b}}')"
    echo -ne " ${cputemp} °C"

}

# cpu (from: https://bbs.archlinux.org/viewtopic.php?pid=661641#p661641)

while true; do
  # get new cpu idle and total usage
  eval $(awk '/^cpu /{print "cpu_idle_now=" $5 "; cpu_total_now=" $2+$3+$4+$5 }' /proc/stat)
  cpu_interval=$((cpu_total_now-${cpu_total_old:-0}))
  # calculate cpu usage (%)
  let cpu_used="100 * ($cpu_interval - ($cpu_idle_now-${cpu_idle_old:-0})) / $cpu_interval"

  # output vars
  print_cpu_used() {
    printf "%-1b" " ${cpu_used}%"
    #"%-10b" "${color7}CPU:${cpu_used}%"
  }
 
  # Pipe to status bar, not indented due to printing extra spaces/tabs
  xsetroot -name "[$(print_cpu_used)|$(print_cputemp)|$(print_ram)|$(print_brightness)|$(print_wifiqual)|$(print_hddfree)|$(print_volume)|$(print_power)|$(print_datetime)]"

  # reset old rates
  cpu_idle_old=$cpu_idle_now
  cpu_total_old=$cpu_total_now
  # loop stats every 10 second
  sleep 60
 done
