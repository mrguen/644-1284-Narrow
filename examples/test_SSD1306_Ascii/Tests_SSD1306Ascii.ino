// Complete test 
// * for 64x32 0.49" oled module wih I2C interface
// * light library only for printing text
// * with more than 20 fonts of different sizes
// * Use smaller faster AvrI2c class in place of Wire.
// * Edit AVRI2C_FASTMODE in SSD1306Ascii.h to change the default I2C frequency.
//
// Based on https://github.com/mrguen/SSD1306Ascii
// Initialy based on https://github.com/greiman/SSD1306Ascii
//

#include "SSD1306Ascii.h"
#include "SSD1306AsciiAvrI2c.h"

#define I2C_ADDRESS 0x3C

#define pauseDelay 2000

SSD1306AsciiAvrI2c oled;

const char* fontName[] = {
  "Arial14",
  "Arial_bold_14",
  "Callibri11",
  "Callibri11_bold",
  "Callibri11_italic",
  "Callibri15",
  "Corsiva_12",
  "fixed_bold10x15",
  "font5x7",
  "font8x8",
  "Iain5x7",
  "lcd5x7",
  "Stang5x7",
  "System5x7",
  "TimesNewRoman16",
  "TimesNewRoman16_bold",
  "TimesNewRoman16_italic",
  "utf8font10x16",
  "Verdana12",
  "Verdana12_bold",
  "Verdana12_italic",
  "X11fixed7x14",
  "X11fixed7x14B",
  "ZevvPeep8x16"
};
const uint8_t* fontList[] = {
  Arial14,
  Arial_bold_14,
  Callibri11,
  Callibri11_bold,
  Callibri11_italic,
  Callibri15,
  Corsiva_12,
  fixed_bold10x15,
  font5x7,
  font8x8,
  Iain5x7,
  lcd5x7,
  Stang5x7,
  System5x7,
  TimesNewRoman16,
  TimesNewRoman16_bold,
  TimesNewRoman16_italic,
  utf8font10x16,
  Verdana12,
  Verdana12_bold,
  Verdana12_italic,
  X11fixed7x14,
  X11fixed7x14B,
  ZevvPeep8x16
};
uint8_t nFont = sizeof(fontList)/sizeof(uint8_t*);

uint8_t nameSize;
char tampon[11];

uint8_t rows;

int blank = 0; // Count of blank lines.
int count = 0; // Count of displayed lines.
int dir = 1;   // Scroll direction.
uint32_t scrollTime = 0;

//***********************************
void test2X() {
  
  oled.setFont(Arial_bold_14);
  oled.clear();
  oled.setCursor(0,1);
  oled.print("Set1X/2X");
  delay(pauseDelay);
  oled.setFont(Adafruit5x7);
  oled.clear();

  // first row
  oled.println("Adafruit5x7");
  oled.println("set1X");

  // second row
  oled.set2X();
  oled.println("set2X");  
  oled.set1X();
}

//***********************************
void testRemap() {
  oled.setFont(Arial_bold_14);
  oled.clear();
  oled.setCursor(0,1);
  oled.print("Remap");
  delay(pauseDelay);
  oled.setFont(Adafruit5x7);
  oled.clear();

  oled.println("ABCDEF");
  oled.println("+-/*");
  oled.println("012345");
  delay(pauseDelay);
  oled.displayRemap(true);
  delay(pauseDelay);
  oled.displayRemap(false);  
}

void testInvert(){
  oled.setFont(Arial_bold_14);
  oled.clear();
  oled.setCursor(0,1);
  oled.print("Invert");
  delay(pauseDelay);
  oled.setFont(Adafruit5x7);
  oled.clear();

  oled.setInvertMode(true);
  oled.println("ABCDEF");

  delay(pauseDelay);
  oled.setInvertMode(false);
}
//***********************************
void testFonts() {

  oled.setFont(Arial_bold_14);
  oled.clear();
  oled.setCursor(0,1);
  oled.print("Fonts");
  delay(pauseDelay);
  
  for (uint8_t i = 0; i < nFont; i++) {

  oled.setFont(System5x7);
  oled.clear();

  nameSize = strlen(fontName[i]);
    
  if  (nameSize > 10) {
    strncpy(tampon, fontName[i] , 10);
    oled.println(tampon);
    memset(tampon, 0, sizeof tampon);
    strncpy(tampon, fontName[i] + 10, nameSize - 10);
    oled.println(tampon);
  }
  else {
    oled.println(fontName[i]);
    oled.println("");
  }
    
  oled.setFont(fontList[i]);
  oled.println("ABC*01");
  delay(5000);
  }
}

//***********************************
void testLetterSpacing() {
  oled.setFont(Arial_bold_14);
  oled.clear();
  oled.setCursor(0,1);
  oled.print("Spacing");
  delay(pauseDelay);
  
  oled.setFont(Callibri11_bold);
  oled.clear();
  oled.println("Hello you!");
  oled.setLetterSpacing(2);
  oled.print("Hello you!");  
}

//***********************************
void testVerticalScroll() {
  
  oled.setFont(Arial_bold_14);
  oled.clear();
  oled.setCursor(0,1);
  oled.print("Scroll. 1");
  delay(pauseDelay);
  oled.clear();  
  oled.setFont(System5x7);
  
  #if INCLUDE_SCROLLING == 0
  #error INCLUDE_SCROLLING must be non-zero.  Edit SSD1306Ascii.h
  #endif //  INCLUDE_SCROLLING
  // Set auto scrolling at end of window.
  oled.setScrollMode(SCROLL_MODE_AUTO);
  
  for (int i = 0; i <= 10; i++) {
    oled.print("Line ");
    oled.println(i);
    delay(500);
  }
  oled.setScrollMode(SCROLL_MODE_OFF);
}

//***********************************
void testSmoothScroll() {
  
  oled.setFont(Arial_bold_14);
  oled.clear();
  oled.setCursor(0,1);
  oled.print("Scroll. 2");
  delay(pauseDelay);
  
  oled.setFont(System5x7);
  oled.clear();  
  // Set cursor to last row of window.
  oled.setRow(oled.displayRows() - oled.fontRows());

  for (int i = 0; i <= 800; i++) {
    
    if (!oled.scrollIsSynced()) {
      uint32_t now = millis();
      if ((now - scrollTime) >= 15) {
        // Scroll display window.
        oled.scrollDisplay(dir);
        scrollTime = now;
      }
      // Reduce flicker by allowing display to scroll before writing.
    } else if ((millis() - scrollTime) > 15) {
    // Done if screen is blank.
      if (blank*oled.fontRows() > oled.displayRows()) {
        // Set new direction and magnification.
        blank = 0;
        count = 0;
        // Reverse scroll direction.
        dir = -dir;
        // Set font magnification.
        if (dir > 0) {
          if (oled.magFactor() == 1) {
            oled.set2X();
          } else {
            oled.set1X();
          }
        }
        
        // Set cursor to first or last line of memory window.
        oled.setCursor(0, dir < 0 ? 0 : oled.displayRows() - oled.fontRows());
      }
    
      // Scroll memory window.
      oled.scrollMemory(dir*oled.fontRows());
      oled.setCol(0);
      if (count*oled.fontRows() <= oled.displayRows()) {
        oled.print(dir < 0 ? "DN " : "UP ");
        oled.print(++count);
      } else {
        blank++;
      }
    
      oled.clearToEOL();
    }    
    delay(10);
  }
}

//------------------------------------------------------------------------------
void setup() {

  oled.begin(&SSD1306_64x32, I2C_ADDRESS);
  // Call oled.setI2cClock(frequency) to change from the default frequency.

  oled.setFont(Arial_bold_14);
  oled.println("Examples");
  oled.println("of using");
  delay(pauseDelay);
  oled.clear();
  oled.println("SSD1306");
  oled.println("Ascii");
  delay(pauseDelay);
  oled.clear();
  oled.println("library");
  delay(pauseDelay);
/*    
  test2X();

  delay(pauseDelay);
  
  testRemap();

  testInvert();
*/
  testFonts();
/*
  delay(pauseDelay);
  testLetterSpacing();
  delay(pauseDelay);
  testVerticalScroll();
  testSmoothScroll();
  
  oled.setFont(Arial_bold_14);
  oled.clear();
  oled.setCursor(0,1);
  oled.print("Values");
  delay(pauseDelay);
  oled.setFont(Adafruit5x7);
  oled.clear();

  // Setup form.  Could use F() macro to save RAM on AVR.
  oled.println("ADC0: 9999");
  oled.println("ADC1: 9999");
  oled.println("ADC2: 9999");
  oled.println("ADC3: 9999");
  rows = oled.fontRows();
  */
}
//------------------------------------------------------------------------------
void loop() {
  /*
  for (uint8_t i = 0; i < 4; i++) {  
    oled.setCursor(35, rows*i);
    oled.clearToEOL();
    oled.print(analogRead(i));
  }
  delay(1000);
    */
  }
