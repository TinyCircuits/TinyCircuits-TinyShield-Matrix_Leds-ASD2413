/*
  LED Matrix TinyShield Nametag Example
  
  This example creates a scrolling nametag on the LED matrix
  given a specific string.
  This example code is in the public domain.

  Written 28 January 2015
  By Tony Batey
  Modified 07 January 2019
  By Hunter Hykes

  https://TinyCircuits.com
*/

/*
  MAKE THE FOLLORING CHANGES TO THE CHARLIEPLEXING.H AND .CPP FILES:

  In Charlieplexing.h change the DISPLAY_COLS definition to 6 and the DISPLAY_ROWS definition to 9

    #define DISPLAY_COLS 6      // Number of columns in the display
    #define DISPLAY_ROWS 9      // Number of rows in the display
  

  In Charlieplexing.cpp change the ledMap array to match the following:

    const LEDPosition PROGMEM ledMap[54] = {
      L(5, 6), L(8, 6), L(6, 9), L(2, 7), L(8, 9), L(2,3),
      L(6, 5), L(6, 8), L(9, 6), L(7, 2), L(9, 8), L(3,2),
      L(5, 7), L(7, 6), L(6, 4), L(3, 7), L(8, 4), L(3,4),
      L(7, 5), L(6, 7), L(4, 6), L(7, 3), L(4, 8), L(4,3),
      L(5, 8), L(2, 5), L(6, 3), L(4, 7), L(8, 3), L(2,9),
      L(8, 5), L(5, 2), L(3, 6), L(7, 4), L(3, 8), L(9,2),
      L(5, 9), L(3, 5), L(6, 2), L(9, 7), L(8, 2), L(3,9),
      L(9, 5), L(5, 3), L(2, 6), L(7, 9), L(2, 8), L(9,3),
      L(5, 4), L(4, 5), L(7, 8), L(8, 7), L(9, 4), L(4,9)
    };
*/

#include "Charlieplexing.h"
#include "Font.h"
#include "Arduino.h"

void setup()  
{
  LedSign::Init();
}

static const char test[]="HI EVERYBODY!  "; //Put whatever you want displayed 
											                      //inside the quotes!
void loop()                     
{
  for (int8_t x=DISPLAY_COLS, i=0;; x--) {
	  LedSign::Clear();
    for (int8_t x2=x, i2=i; x2<DISPLAY_COLS;) {
      int8_t w = Font::Draw(test[i2], x2, 0);
	    x2 += w, i2 = (i2+1)%strlen(test);
	    if (x2 <= 0)	// off the display completely?
        x = x2, i = i2;
	  }
      delay(80);
  }
}
