function gen_gpio() {
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
gen_gpio 0 A $1
gen_gpio 1 B $1
gen_gpio 2 C $1
gen_gpio 3 D $1
gen_gpio 4 E $1
gen_gpio 5 F $1
