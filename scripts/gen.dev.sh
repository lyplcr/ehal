#!/bin/sh

# Generate a device .c or .h from a template,eg. gen.gpio.c / gen.gpio.h
# Templates substitute !N for the device number, eg. gpio!N_ctor -> gpio0_ctor

function gen_one {
	dir=$1
	dev=$2
	e=$3

	from=$4
	to=$5

	cat '/dev/stdin' | sed -e "s/\$$from/$to/g"
}

function gen {
	dir=$1
	dev=$2
	n0=$3
	e=$4
	subs=$5

	template=${dir}gen.${dev}${e}
	case $dev in
		"gpio")	# run twice
			cat $template |\
				gen_one $dir $dev $e 0 $n0 |\
				gen_one $dir $dev $e 1 ${subs:$n0:1}
			;;
		*)	# run once
			cat $template |\
				gen_one $dir $dev $e 0 $n0
			;;
	esac
}

# breaks a file path/device(number).[ch] into "path/" "device" "number" ".c|h"
V=$(echo "$1" | sed -E 's|(.+/)(.+)([0-9]+)(.c\|.h)|\1 \2 \3 \4|')
gen $V $2 > $1
