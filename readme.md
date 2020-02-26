# 644/1284 Narrow

<img src="https://github.com/mrguen/644-1284-Narrow/blob/master/images/644_1284%20Narrow%20v0.9%20global%20view.jpg">

644 Narrow and 1284 Narrow are tiny boards based on Atmega644/Atmega1284, using the MightyCore https://github.com/MCUdude/MightyCore.

It is conceived to be an upgrade for any project using the Nano board or any other Arduino board particularly those based on Atmega328 but also other MCUs because it gives a lot of resources on a tiny board while keeping the 8 bits technology that is more efficient in using resources.

<img src="https://github.com/mrguen/644-1284-Narrow/blob/master/images/board-outline-nano-narrow-uno-mega-1-5x_png_project-body.jpg">


There is a slot to solder an optional small 0.49" 64x32 OLED.
To the difference with the standard pinout, the builtin_led is PB7.

<img src="https://github.com/mrguen/644-1284-Narrow/blob/master/images/644%20Narrow%20v0.9%20OLED%20TOP%203D.jpg">

Examples sketches are provided to show the use of this OLED to display graphics (using Adafruit's libraries) or advanced text rendering (using Greiman's library).



# Installation

# CH340G

You need to instal the CH340G Serial/USB driver if you want to communicate between the board and the PC USB port.
The driver is available from http://www.wch.cn/download/CH341SER_EXE.html but the page is mostly in Chinese language. You can also refer to https://sparks.gogo.co.nz/ch340.html

# Boards definition

There are a couple of repositories on github to use Atmega644 and Atmega1284 MCUs in the Arduino IDE. See

https://github.com/search?q=Atmega644  
or  
https://github.com/search?q=Atmega1284   

But you will probably like the MightyCore. See the installation process https://github.com/MCUdude/MightyCore#how-to-install

Then make some additions to the MightyCore:

* add the directory "narrow" that you will find in https://github.com/mrguen/644-1284-Narrow/tree/master/variants
to 
YOUR_ARDUINO_PACKAGE_ROOT\Arduino15\packages\MightyCore\hardware\avr\ **2.0.3** \variants (the **version number** might be different!)

* replace or modify the file YOUR_ARDUINO_PACKAGE_ROOT\Arduino15\packages\MightyCore\hardware\avr\ **2.0.3** \boards.txt (the **version number** might be different!)

to include these lines written in https://github.com/mrguen/644-1284-Narrow/blob/master/boards.txt

**644.menu.pinout.narrow=Narrow pinout  
644.menu.pinout.narrow.build.variant=narrow  
644.menu.pinout.narrow.build.builtin_led=B7** 

**1284.menu.pinout.narrow=Narrow pinout  
1284.menu.pinout.narrow.build.variant=narrow  
1284.menu.pinout.narrow.build.builtin_led=B7**

This allows the Arduino IDE to define the builtin_led so it will select the appropriate bootloader.

<img src="https://github.com/mrguen/644-1284-Narrow/blob/master/images/Narrow_V0.9_Pinout.jpg">

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

