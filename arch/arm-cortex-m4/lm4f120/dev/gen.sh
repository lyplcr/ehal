function mkgpio() {
	n=$1
	t=$2
	sed -e "s/!N/$n/g" -e "s/!T/$t/g" gpioN.c > gpio${n}.c
	sed -e "s/!N/$n/g" -e "s/!T/$t/g" gpioN.h > gpio${n}.h
}

# lm4f120
mkgpio 0 A
mkgpio 1 B
mkgpio 2 C
mkgpio 3 D
mkgpio 4 E
mkgpio 5 F
