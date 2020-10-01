# 644/1284 Narrow

**644 Narrow and 1284 Narrow are tiny boards based on Atmega644/Atmega1284.** 

They were conceived as an upgrade for any project using the Nano board or any other Arduino board particularly those based on Atmega328. They can also compete with other MCUs because they provide a lot of resources on a tiny board while keeping the 8 bits technology that is more efficient in using resources.  
  
<img src="https://github.com/mrguen/644-1284-Narrow/blob/master/images/644_1284%20Narrow%20v0.9%20global%20view.jpg">


<img src="https://github.com/mrguen/644-1284-Narrow/blob/master/images/board-outline-nano-narrow-uno-mega-1-5x_png_project-body.jpg">


There feature a slot to solder an optional small 0.49" 64x32 OLED.

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

**You should update to the 2.0.5 version at least**

* Add the "narrow" variant(https://github.com/mrguen/644-1284-Narrow/tree/master/variants) to YOUR_ARDUINO_PACKAGE_ROOT\Arduino15\packages\MightyCore\hardware\avr\ **2.0.5** \variants (the **version number** might be different!)

* And replace the boards.txt file located at YOUR_ARDUINO_PACKAGE_ROOT\Arduino15\packages\MightyCore\hardware\avr\ **2.0.5** \boards.txt (the **version number** might be different!)

with the one that you will find at the root of this repository. 

This will add these lines to the boards.txt

**644.menu.pinout.narrow=Narrow pinout  
644.menu.pinout.narrow.build.variant=narrow  
644.menu.pinout.narrow.build.bootloader_led=B7**

**1284.menu.pinout.narrow=Narrow pinout  
1284.menu.pinout.narrow.build.variant=narrow  
1284.menu.pinout.narrow.build.bootloader_led=B7**

To allow the Arduino IDE to select the appropriate bootloader.
  
  
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

The bootloader has been installed already but if needed install it from the IDE menu Tools/Burn Bootloader.   

When the bootloader is present "L led (yellow)" continuously flashes twice if not other program is loaded.

You can then load your program as usual.

# Programming examples

**Blink**  
Usually you might want to check that everything is working properly by programming the  sketch Blink.ino that you will find in the Arduino IDE menu Files/Examples/Basic/Blink

The led labelled “L” on the board will be blinking at low speed.

**2nd Serial port**  

The 1284 Narrow has two serial ports. 

1) You can test that they are working using the sketch that you will find int the Arduino IDE menu File/Examples/Communication/MultiSerial


This sketch needs to have a serial device attached to the Serial 1 port (pin 10 RX1, pin 11 TX1).


2) If you don’t have such a device you can simply try this sketch

https://github.com/mrguen/644-1284-Narrow/tree/master/examples/Endless_Serial_0_1/Endless_Serial_0_1.ino/ 


Connect pins TX and 10 together.

Program the sketch through the USB port. In the Serial Monitor, if you type a letter to send to the board through the Serial port, it will display endlessly on the screen because it is sent back by serial “0” Tx pin to the serial monitor and also to serial “1” Rx, that writes again to serial “0” Tx. 

 
**0.49” OLED display**  

There is a group of four plated through-holes on the board to solder a tiny 0.49” OLED 64x32 pixels display. Not all I2C OLED modules connections are arranged in the same order so check it before soldering in your display. These holes are connected to 

GND – 5V – SCL - SDA

Attention: the labels SDA and SCL on the board are for the pins on the edge of the board and not for this connector that has SCL and SDA arranged the other way and that are not labelled.


There are three examples available. 

1) Using the Adafruit libraries 
https://github.com/mrguen/644-1284-Narrow/tree/master/examples/test_SSD1306_Adafruit

The Adafruit library is mostly interesting is you want to display shapes, or even bitmaps. See https://learn.adafruit.com/adafruit-gfx-graphics-library


2)  Using the Greiman library 
https://github.com/mrguen/644-1284-Narrow/tree/master/examples/test_SSD1306_Ascii

Initially based on https://github.com/greiman/SSD1306Ascii library, it is mostly limited to text rendering but with a large and nice choice of fonts.


2)  Using the ST7789_Fast library by cbm80amiga 
https://github.com/mrguen/644-1284-Narrow/tree/master/examples/Graphicstest_ST7789_Fast_Narrow_TFT_240x240_balloon
That will allow you to fast draw heavy bitmaps



**1024 samples FFT** 

See https://www.instructables.com/1024-Samples-FFT-Spectrum-Using-an-Atmega1284/ 

# Complete user's manual

See the content of https://github.com/mrguen/644-1284-Narrow/tree/master/doc

