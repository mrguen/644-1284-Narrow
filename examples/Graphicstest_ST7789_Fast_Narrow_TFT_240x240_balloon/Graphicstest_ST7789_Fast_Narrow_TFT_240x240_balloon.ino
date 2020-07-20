/**************************************************************************
 ST7789 library example
 (c) 2019 Pawel A. Hernik
 Modified by Tierry GUENNOU / Pandauino.com
 **************************************************************************/
 
#define TFT_DC    13
#define TFT_RST   14 
#define SCR_WD   240
#define SCR_HT   320   // 320 - to allow access to full 240x320 frame buffer that is bigger than the display size
#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Arduino_ST7789_Fast.h>

#include "bitmap.h"


//**************************************************************************************
// DECLARATIONS

int ycnt = 0, yscrStep = 1;


//**************************************************************************************
// INSTANCIATIONS

Arduino_ST7789 lcd = Arduino_ST7789(TFT_DC, TFT_RST);


//*************************************************************************************
// SETUP
void setup(void) 
{
  Serial.begin(9600);
  lcd.init(SCR_WD, SCR_HT);
  lcd.fillScreen(BLACK);
  lcd.setScrollArea(0,0);

  // fast drawing of image
  lcd.drawImageF(65,100,108,145,image_data_balloon_145);
  delay(2000);

do {
    ycnt +=1;
    lcd.setScroll(ycnt*yscrStep); // will scroll tha image using tha hardware scrolling capabilities i.e. no data sent from the MCU
    delay(10);
} while (ycnt < 400);

}

//*************************************************************************************
// LOOP
void loop()
{
 
}
