#include <USBComposite.h>

//Key definitions
#include "key.h"

//Change to desired layout
#include "layouts/uk_76.h"

//Keeps track if a key is being held down
bool keypress[rows][columns];

USBHID HID;
HIDKeyboard Keyboard(HID);

void setup() {

  //Give us access to B3 & B4
  disableDebugPorts();

  //Pull down all columns and set as inputs
  for (int i = 0; i < columns; i++) {
    gpio_set_mode(GPIOB, column[i], GPIO_INPUT_PD);
  }

  //Set all rows as outputs
  for (int i = 0; i < rows; i++) {
    gpio_set_mode(GPIOA, row[i], GPIO_OUTPUT_PP);
  }

  //Setup keyboard device
  HID.begin(HID_KEYBOARD);
  Keyboard.begin();

  //Wait just in case
  delay(3000);

  //Stop any keys being stuck
  Keyboard.releaseAll();

}

void loop() {

  for (int x = 0; x < rows; x++) {
    //Power up GPIO
    gpio_write_bit(GPIOA, row[x], HIGH);

   //Go through columns
    for (int y = 0; y < columns; y++) {

      //Check if power from row is coming to column 
      if (gpio_read_bit(GPIOB, column[y])) {

        //Add press to report
        Keyboard.press(keymap[x][y]);

        //Track key is pressed
        keypress[x][y] = true;
        
      }else if(keypress[x][y]){//If its not being pressed check if its being held

        //Release key
        Keyboard.release(keymap[x][y]);
        keypress[x][y] = false;
        
      }


    }

    //Unpower row
    gpio_write_bit(GPIOA, row[x], LOW);
  
  }
  
}
