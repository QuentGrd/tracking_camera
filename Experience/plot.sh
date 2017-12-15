#!/bin/sh
#Gnuplot
if [ -n $1 ] && [ -n $2 ]; then
	echo `gnuplot -e \'set term png; set output $2; plot $1\'\; qlmanage -p $2`
	exit 0
else
	exit 1
fi