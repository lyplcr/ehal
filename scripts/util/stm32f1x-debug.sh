arm-none-eabi-gdb $1 -ex 'target remote | openocd -c "gdb_port pipe; log_output openocd.log" -f interface/jlink.cfg -f target/stm32f1x.cfg -c "init" -c "reset halt"'
