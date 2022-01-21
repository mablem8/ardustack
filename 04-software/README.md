# Ardustack Software

Software documentation for the Arduino stack

## Directory Contents

* [README.md](README.md): This document

## Install Arduino

These installation instructions assume a Raspberry Pi 400 running the Ubuntu
21.10 operating system.

```bash
sudo apt install linux-modules-extra-raspi
cd $HOME/Downloads/
wget https://downloads.arduino.cc/arduino-1.8.19-linuxaarch64.tar.xz
tar xf arduino-1.8.19-linuxaarch64.tar.xz
cd arduino-1.8.19/
sudo ./install.sh
rm $HOME/Desktop/arduino-arduinoide.desktop
sudo usermod -aG dialout $USER
```

## Burning the Bootloader to a Chip with an Arduino Uno

See
[this webpage](https://docs.arduino.cc/built-in-examples/arduino-isp/ArduinoToBreadboard).

1. In the Arduino IDE, choose File > Examples > 11.ArduinoISP > ArduinoISP.
   Upload this sketch to an Arduino Uno board.
2. Connect the Arduino Uno to the ATmega328P-PU chip as shown in the web page.
3. Select "Arduino as ISP" from Tools > Programmer and then choose
   Tools > Burn Bootloader
4. Test that the bootloader has been burned correctly by powering the stack and
   pressing the reset button. The LED should blink twice in quick succession.

## Loading the Blink Program

After burning the bootloader and testing the stack, connect the FTDI cable to
the I/O board. The black cable should be farthest from the reset button. Open
File > Examples > 01.Basics > Blink. Choose Tools > Board: "Arduino Uno" and
Tools > Port > "/dev/ttyUSB0". Choose Tools > Programmer: "AVRISP mkII". Upload
the Blink program.

## License

Written by Bradley Denby  
Other contributors: None

See the [LICENSE](LICENSE) file for the license.
