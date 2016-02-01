arm-none-eabi-objcopy -O binary build/example example.bin
sudo st-flash --reset write example.bin 0x8000000
