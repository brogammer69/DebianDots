#!/bin/sh

# this command kills all the sleep processes. The n second sleep in dwm-statusbar is killed
# and dwm-statusbar is restarted fresh with updated values

kill "$(pidof sleep)"
