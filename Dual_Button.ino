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

#include <M5StickCPlus.h>                  // System Library to manage the M5 
#include "displayHelper.h"                 // Local Library to manage the Lcd
#include "buttonHelper.h"                  // Local Library to manage  the push buttons

/* integer values for the buttons */
int last_value_red  = 0;
int cur_value_red   = 0;
int last_value_blue = 0;
int cur_value_blue  = 0;

/* define a macro of program code */
#define PRESSED 0

/* Set up the program */
void setup() {

  disp::setup();                           // set up the display
  disp::drawDualButton();                  // draw the dual button image
  btn::setup();                            // set up the dual buttons

} // setup()

/* Main program loop */
void loop() {

  cur_value_red = btn::redButton();        // get red pushbutton state
  cur_value_blue = btn::blueButton();      // get blue pushbutton state

  /********************************************************************
  * Check the Blue button condition
  *
  * First line prevents debounce of the button input 
  * Then draw a button image dependent of whether it's pressed or not
  ********************************************************************/
  if (cur_value_blue != last_value_blue) {

    if (cur_value_blue == PRESSED) {
      disp::drawBlueCircle(true);          // draw a pushed button
    } else {
      disp::drawBlueCircle(false);         // draw an unpushed button
    }

    last_value_blue = cur_value_blue;      // reset the debouce variables

  } // (cur_value_blue != last_value_blue)

  /********************************************************************
  * Check the Red button condition
  *
  * First line prevents debounce of the button input 
  * Then draw a button image dependent of whether it's pressed or not
  ********************************************************************/
  if (cur_value_red != last_value_red) {

    if (cur_value_red == PRESSED) {
      disp::drawRedCircle(true);           // draw a pushed button
    } else {
      disp::drawRedCircle(false);          // draw an unpushed button
    }

    last_value_red = cur_value_red;        // reset the debouce variables

  } // (cur_value_red != last_value_red)

  M5.update();                             // make the changes visible in the display

} //loop()
