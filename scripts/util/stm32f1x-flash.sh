openocd -f interface/jlink.cfg \
	-f target/stm32f1x.cfg \
	-c init \
	-c "reset halt" \
	-c "flash write_image erase unlock $1" \
	-c "reset run" \
	-c "shutdown"
