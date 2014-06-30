openocd -f board/ek-lm4f120xl.cfg -c "init"\
	-c "reset halt"\
	-c "flash write_image erase $1"\
	-c "reset run"\
	-c "shutdown"
