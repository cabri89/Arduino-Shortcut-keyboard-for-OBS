/* HID KeyBoard Example
by: Jim Lindblom
date: 1/12/2012
license: MIT License - Feel free to use this code for any purpose.
No restrictions. Just keep this license if you go on to use this
code in your future endeavors! Reuse and share. 

This is very simplistic code that allows you to send a 'z' with
a momentary pushbutton. 
*/

#include <Keyboard.h>
#include <string> 
int keys[] = {2, 3, 4, 5, 6, 7};

void setup()
{
    Serial.begin(9600);
    for (int i = 2; i < 7; ++i) {
        // initilize pins
        pinMode(i, INPUT);
        digitalWrite(i, HIGH); // Pull the button high
    }
}

void loop()
{
    for (int i = 2; i < 7; ++i)
    {
        // check buttons
        if (readButton(i)){
        Keyboard.press(KEY_LEFT_CTRL);
        Keyboard.press(KEY_RIGHT_ALT);
        Keyboard.press(std::to_string(i));
        Serial.print(i);
        delay(100);
        }
    }
}

boolean readButton(int pin)
{
    // check and debounce buttons
    if (digitalRead(pin) == HIGH)
    {
        delay(10);
        if (digitalRead(pin) == HIGH)
        {
            return true;
        }
    }
    return false;
}
