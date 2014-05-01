#openocd -f board/ek-lm4f120xl.cfg -c "init"\
#	-c "reset halt" &
#arm-none-eabi-gdb $1 -ex "target remote localhost:3333"
#pkill openocd

arm-none-eabi-gdb $1 -ex 'target remote | openocd -c "gdb_port pipe; log_output openocd.log" -f board/ek-lm4f120xl.cfg -c "init" -c "reset halt"'
