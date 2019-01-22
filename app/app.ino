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

int keys[] = {1, 2, 3, 4, 5, 6, 7, 8};
int keysF[] = {KEY_F1, KEY_F2, KEY_F3, KEY_F4, KEY_F5, KEY_F6, KEY_F7, KEY_F8};
void setup()
{
    Serial.begin(9600);
    for (int i = 1; i < 8; ++i) {
        Serial.print(i);
        // initilize pins
        pinMode(i, INPUT);
        digitalWrite(i, HIGH); // Pull the button high
    }
}

void loop()
{
    for (int i = 1; i < 8; ++i)
    {
        // check buttons
        if (readButton(i)){
            Keyboard.press(KEY_LEFT_CTRL);
            Keyboard.press(KEY_RIGHT_ALT);
            Keyboard.press(keysF[i]);
            delay(100);
            Keyboard.release(KEY_LEFT_CTRL);
            Keyboard.release(KEY_RIGHT_ALT);
            Keyboard.release(keysF[i]);
        }
    }
}

boolean readButton(int pin)
{
    // check and debounce buttons
    if (digitalRead(pin) == LOW)
    {
        delay(10);
        if (digitalRead(pin) == LOW)
        {
            return true;
        }
    }
    return false;
}
