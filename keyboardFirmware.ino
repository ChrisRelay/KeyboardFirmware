//USB
#include <USBComposite.h>

//Key definitions
#include "key.h"

//Change to desired layout
#include "layouts/iso_76.h"

//Keeps track if a key is being held down
unsigned char keypress[rows][columns];
unsigned char keypressCode[0xFF];

//FN
unsigned char FNPress;

//USB
USBHID HID;
HIDKeyboard Keyboard(HID);

unsigned char checkFNKeyOnce(unsigned char data) {
	if (keypressCode[data]) {
		if (FNPress != data) {
			FNPress = data;
			return 1;
		}
	}else if (FNPress == data){
		FNPress = 0;
	}

	return 0;
}

//Plugins
#include "plugin/HELLOWORLD.h"

//When FN is down
void handleFN() {
	plugin_handleFN_HELLOWORLD();
}

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

	//Check and send keys
	for (int rowI = 0; rowI < rows; rowI++) {
		//Power up GPIO
		gpio_write_bit(GPIOA, row[rowI], HIGH);

		//Go through columns
		for (int columnI = 0; columnI < columns; columnI++) {

			//Check if power from row is coming to column 
			if (gpio_read_bit(GPIOB, column[columnI])) {
			
				//Track key is pressed
				keypress[rowI][columnI] = true;
				keypressCode[keymap[rowI][columnI]] = true;

				//Don't send FN key
				if (keypress[FN_ROW][FN_COLUMN]) {//FN is down
					Keyboard.releaseAll();
					handleFN();
				}else {
					//Add press to report
					Keyboard.press(keymap[rowI][columnI]);
				}
				
			}else if(keypress[rowI][columnI]) {//If its not being pressed check if its being held

				//Release key
				Keyboard.release(keymap[rowI][columnI]);
				keypress[rowI][columnI] = false;
				keypressCode[keymap[rowI][columnI]] = false;

			}


		}

		//Unpower row
		gpio_write_bit(GPIOA, row[rowI], LOW);

	}
	
	
}