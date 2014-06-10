function mkgpio() {
	n=$1
	t=$2
	dir="$3/"
	#echo ${dir}/gpioN.c
	#echo ${n}
	#echo ${t}
	sed -e "s/!N/$n/g" -e "s/!T/$t/g" ${dir}template_gpio.c > ${dir}gpio${n}.c
	sed -e "s/!N/$n/g" -e "s/!T/$t/g" ${dir}template_gpio.h > ${dir}gpio${n}.h
}

# lm4f120
mkgpio 0 A $1
mkgpio 1 B $1
mkgpio 2 C $1
mkgpio 3 D $1
mkgpio 4 E $1
mkgpio 5 F $1
