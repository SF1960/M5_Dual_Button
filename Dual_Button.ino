/***************************************************************************************
* Description:  Using the Dual Button module on the M5StickCPlus
* Sketch:       Dual_Button.ino
* Version:      1.0
* Version Desc: Using graphics to display the button state
* Board:        M5StickCPlus 1.1
* Author:       Steve Fuller
* Website:      sgfpcb@gmail.com
* Comments      Connect the Grove Connector to the device
*               Adapted from M5 Docs https://docs.m5stack.com/en/unit/dual_button
***************************************************************************************/
#include <M5StickCPlus.h>
#include "displayHelper.h"
#include "buttonHelper.h"

/* integer values for the buttons */
int last_value_red  = 0;
int cur_value_red   = 0;
int last_value_blue = 0;
int cur_value_blue  = 0;

/* define program code */
#define PRESSED 0

/* Set up the program */
void setup() {

  disp::setup();                           // set up the display
  disp::drawDualButton();                  // draw the dual button image
  btn::setup();

}

void loop() {

  cur_value_red = btn::redButton();        // get red pushbutton state
  cur_value_blue = btn::blueButton();      // get blue pushbutton state

  // Blue button condition
  if (cur_value_blue != last_value_blue) {

    if (cur_value_blue == PRESSED) {
      disp::drawBlueCircle(true);
    } else {
      disp::drawBlueCircle(false);
    }

    last_value_blue = cur_value_blue;

  }

  // Red button condition
  if (cur_value_red != last_value_red) {

    if (cur_value_red == PRESSED) {
      disp::drawRedCircle(true);
    } else {
      disp::drawRedCircle(false);
    }

    last_value_red = cur_value_red;

  }

  M5.update();

} //loop()




