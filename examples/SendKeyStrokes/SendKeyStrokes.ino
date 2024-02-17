/**
 * This example turns the ESP32 into a Bluetooth LE keyboard that writes the words, presses Enter, presses a media key and then Ctrl+Alt+Delete
 */
#include <BleKeyboard.h>

BleKeyboard bleKB;

void setup()
{
    Serial.begin(115200);
    Serial.println("Starting BLE work!");
    bleKB.setBatteryLevel(80);
    bleKB.setName("kbName");
    bleKB.set_vendor_id(0x3333);
    bleKB.set_product_id(0x3333);
    bleKB.begin();
}

void loop()
{
    if (bleKB.isConnected())
    {
        Serial.println("Sending 'Hello world'...");
        bleKB.print("Hello world");

        delay(1000);

        Serial.println("Sending Enter key...");
        bleKB.write(KEY_RETURN);

        delay(1000);

        Serial.println("Sending Play/Pause media key...");
        bleKB.write(KEY_MEDIA_PLAY_PAUSE);

        delay(1000);

        // bleKB.NumLockOn ? digitalWrite(led1,HIGH) : digitalWrite(led1,LOW);
        // bleKB.CapsLockOn ? ? digitalWrite(led2,HIGH) : digitalWrite(led2,LOW);
        // bleKB.ScrollLockOn ? ? digitalWrite(led3,HIGH) : digitalWrite(led3,LOW);

        //
        // Below is an example of pressing multiple keyboard modifiers
        // which by default is commented out.
        /*
        Serial.println("Sending Ctrl+Alt+Delete...");
        bleKB.press(KEY_LEFT_CTRL);
        bleKB.press(KEY_LEFT_ALT);
        bleKB.press(KEY_DELETE);
        delay(100);
        bleKB.releaseAll();
        */
    }

    Serial.println("Waiting 5 seconds...");
    delay(5000);
}
