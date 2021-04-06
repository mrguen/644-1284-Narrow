# 644/1284 Narrow

**644 Narrow and 1284 Narrow are tiny boards based on Atmega644/Atmega1284.** 

**---------------------------------------  
FR: Les cartes 644 Narrow et 1284 Narrow sont des cartes très compactes à base de Atmega644/Atmega1284.
La présentation détaillé est faite dans le manuel utilisateur. Voir: https://github.com/mrguen/644-1284-Narrow/tree/master/doc 
---------------------------------------** 

They were conceived as an upgrade for any project using the Nano board or any other Arduino board particularly those based on Atmega328. They can also compete with other MCUs because they provide a lot of resources on a tiny board while keeping the 8 bits technology that is more efficient in using resources.  
  
<img src="https://github.com/mrguen/644-1284-Narrow/blob/master/images/644_1284%20Narrow%20v0.9%20global%20view.jpg">


<img src="https://github.com/mrguen/644-1284-Narrow/blob/master/images/board-outline-nano-narrow-uno-mega-1-5x_png_project-body.jpg">


There feature a slot to solder an optional small 0.49" 64x32 OLED.

<img src="https://github.com/mrguen/644-1284-Narrow/blob/master/images/644%20Narrow%20v0.9%20OLED%20TOP%203D.jpg">

Examples sketches are provided to show the use of this OLED to display graphics (using Adafruit's libraries) or advanced text rendering (using Greiman's library).


# Installation and configuration:

To install Narrow boards there are a couple of possibilities

**1) For Windows users: automatic install**

* Download and execute https://github.com/mrguen/644-1284-Narrow/blob/master/install/MightyCore-Pandauino.exe
  
  The installer is not signed so it is normal if you get a warning. 
  
  It will:
  - Install the boards definitions in your local sketch/hardware folder
  - Install the CH340 driver (close the driver installer if it is already installed)

  Then have a look at the Arduino IDE configuration in the user's manual  https://github.com/mrguen/644-1284-Narrow/tree/master/doc 
  
**2) Manual install for Windows and other systems**

See the user's manual https://github.com/mrguen/644-1284-Narrow/tree/master/doc 
"INSTALLATION" section


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


There are two examples available. 

1) Using the Adafruit libraries 
https://github.com/mrguen/644-1284-Narrow/tree/master/examples/test_SSD1306_Adafruit

The Adafruit library is mostly interesting is you want to display shapes, or even bitmaps. See https://learn.adafruit.com/adafruit-gfx-graphics-library


2)  Using the Greiman library 
https://github.com/mrguen/644-1284-Narrow/tree/master/examples/test_SSD1306_Ascii

Initially based on https://github.com/greiman/SSD1306Ascii library, it is mostly limited to text rendering but with a large and nice choice of fonts.



**1024 samples FFT** 

See https://www.instructables.com/1024-Samples-FFT-Spectrum-Using-an-Atmega1284/ 

# Complete user's manual

See the content of https://github.com/mrguen/644-1284-Narrow/tree/master/doc

