function mkgpio() {
	n=$1
	t=$2
	dir=$3
	sed -e "s/!N/$n/g" -e "s/!T/$t/g" ${dir}template_gpio.c > ${dir}gpio${n}.c
	sed -e "s/!N/$n/g" -e "s/!T/$t/g" ${dir}template_gpio.h > ${dir}gpio${n}.h
}

# lm4f120
mkgpio 0 B $1
mkgpio 1 C $1
mkgpio 2 D $1
