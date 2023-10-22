#pragma once

/************************************************
* local library to manage the display
************************************************/

/* additional colour definitions - https://rgbcolorpicker.com/565 */
#define DARKRED   0x5800
#define DARKBLUE  0x000b
#define LIGHTGREY 0xd6bb

/* define XY coordinates for buttons */
#define BlueXposn 50
#define BlueYposn 77
#define RedXposn  120
#define RedYposn  77

namespace disp{

  /* setup the Lcd */
  void setup(){

    M5.begin();
    M5.Lcd.setRotation(3);
    M5.Lcd.setTextSize(2);  // title size
    M5.Lcd.setTextColor(YELLOW);
    M5.Lcd.setCursor(5, 1);
    M5.Lcd.println("Dual Button example");
    M5.Lcd.drawLine(0, 16, 240, 16, YELLOW);
    M5.Lcd.setTextSize(1);

  } // setup()

  /* Draw the Dual Button Image on the display */
  void drawDualButton(){

    M5.Lcd.fillRoundRect(5, 29, 225, 100, 15, WHITE);               // button body
    M5.Lcd.fillCircle(BlueXposn, BlueYposn, 30, DARKBLUE);          // blue button umpressed
    M5.Lcd.fillCircle(RedXposn,RedYposn, 30, DARKRED);              // red button unpressed
    M5.Lcd.drawRoundRect(12, 38, 147, 80, 33, DARKGREY);            // draw raised oval
    M5.Lcd.fillCircle(165, 42, 11, LIGHTGREY);                      // top LEGO hole
    M5.Lcd.fillCircle(165, 115, 11, LIGHTGREY);                     // bottom LEGO hole

    M5.Lcd.fillRect(180, 50, 50, 50, DARKGREY);                     // cable connector
    M5.Lcd.fillRect(210, 58, 25, 5, WHITE);                         // white I2C cable
    M5.Lcd.fillRect(210, 68, 25, 5, YELLOW);                        // yellow I2C cable
    M5.Lcd.fillRect(210, 78, 25, 6, RED);                           // red I2C cable
    M5.Lcd.fillRect(210, 88, 25, 6, BLACK);                         // black I2V cable
    M5.Lcd.drawRect(185, 55, 26 , 40, BLACK);                       // cable connector definition

  } // drawDualButton()

  /* Draw the pressed and unpressed RED button and value on the button */
  void drawRedCircle(bool Pressed){

    if (Pressed){
      M5.Lcd.fillCircle(RedXposn, RedYposn, 28, RED);               // Red button pressed image
      M5.Lcd.drawString("1",119, 75, 1);                            // draw text on button Value == 1
    } else {
      M5.Lcd.fillCircle(RedXposn, RedYposn, 30, DARKRED);           // Red button unpressed image
      M5.Lcd.drawString("0",119, 75, 1);                            // draw text on button Value == 0
    }

  } // drawRedCircle

  /* Draw the pressed and unpressed BLUE button and value on the button */
  void drawBlueCircle(bool Pressed){

    if (Pressed){
      M5.Lcd.fillCircle(BlueXposn, BlueYposn, 28, BLUE);            // Blue button pressed image
      M5.Lcd.drawString("1",49, 75, 1);                             // draw text on button Value == 1
    } else {
      M5.Lcd.fillCircle(BlueXposn, BlueYposn, 30, DARKBLUE);        // Blue button unpressed image
      M5.Lcd.drawString("0",49, 75, 1);                             // draw texrt on button Value == 0
    }

  } // drawBlueCircle()

} // namespace disp{}