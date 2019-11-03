# 644/1284 Narrow

<img src="https://github.com/mrguen/644-1284-Narrow/blob/master/images/644-narrow-top-3d-2-1_jpg_project-main.jpg">

644 Narrow and 1284 Narrow are tiny boards based on Atmega644/Atmega1284, using the MightyCore https://github.com/MCUdude/MightyCore.

It is conceived to be an upgrade for any project using the Nano board or any other Arduino board particularly those based on Atmega328 but also other MCUs because it gives a lot of resources on a tiny board while keeping the 8 bits technology that is more efficient in using resources.

<img src="https://github.com/mrguen/644-1284-Narrow/blob/master/images/board-outline-nano-narrow-uno-mega-1-5x_png_project-body.jpg">


There is a slot to solder an optional small 0.49" 64x32 OLED.
To the difference with the standard pinout, the builtin_led is PB7.

Two examples sketches are provided to show the use of this OLED to display graphics (using Adafruit's libraries) or advanced text rendering (using Greiman's library).

<img src="https://github.com/mrguen/644-1284-Narrow/blob/master/images/644-narrow-top-3d-with-oled_png_project-body.jpg">


# Installation

You need to install https://github.com/MCUdude/MightyCore

MightyCore will possibly commit changes from me to support 644/1284 Narrow.

At the moment you will need to modify MightyCore:

* add the bootloaders directory content to YOUR_ARDUINO_PACKAGE_ROOT\Arduino15\packages\MightyCore\hardware\avr\2.0.3\bootloaders\optiboot_flash

This adds two new bootloader with the LED name included in the bootloader name

* add the variants directory to YOUR_ARDUINO_PACKAGE_ROOT\Arduino15\packages\MightyCore\hardware\avr\2.0.3

This will add the "Narrow" variant

* change YOUR_ARDUINO_PACKAGE_ROOT\Arduino15\packages\MightyCore\hardware\avr\2.0.3\boards.txt

you could save the old file and replace it with the provided boards.txt 

This allows the Arduino IDE to define the builtin_led so it will select the appropriate bootloader.

<img src="https://github.com/mrguen/644-1284-Narrow/blob/master/images/narrow-v0-8-pinout_jpg_project-body.jpg">

# IDE configuration

Once MightyCore has been correctly insalled in the Arduino IDE and modified, you will need to select in the Tools menu

* board: Atmega644 or Atmega1284
* clock: external 16 MHz
* BOD: 2.7V
* Compiler LTO disabled
* Variant 644P or 1284P
* Pinout Narrow pinout (if not selectable then you did not changed boards.txt)
* Bootloader: yes (UART0)

If needed you can upload the bootloader.

When the bootloader is present "L led (yellow)" continuously flashes twice if not other program is loaded.

You can then load your program as usual.

