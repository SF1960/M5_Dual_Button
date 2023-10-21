#pragma once

/* set pin numbers for the pushbuttons */
#define ButtonRED 32
#define ButtonBLUE 33

namespace btn {

  void setup(){
    pinMode(ButtonRED, INPUT);         /* set up the input pins for the buttons */
    pinMode(ButtonBLUE, INPUT);
  }

  int redButton(){
    return digitalRead(ButtonRED);
  }

  int blueButton(){
    return digitalRead(ButtonBLUE);
  }

}