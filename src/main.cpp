#include <Arduino.h>

// marantx uses a mix of RC5 and RC5x
#define SEND_RC5
#define SEND_RC5X

#include <IRremote.h>

#define LED 13

#define ON  1
#define OFF 2

IRsend irsend;

// static unsigned int power_toggle[] = { 900,900,  900,900,   900,900,  1750,900, 900,900,  900,900,  900,900,  900,900,  900,1750,  900,900,  1750,900, 900 };

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(LED, OUTPUT);
}

void loop() {
  int khz = 38; // 38kHz carrier frequency for the NEC protocol
  static int avr_state = OFF;
  
  digitalWrite(LED, HIGH);
  // irsend.sendRaw(power_toggle, sizeof(power_toggle) / sizeof(power_toggle[0]), khz); //Note the approach used to automatically calculate the size of the array.
  if (avr_state == OFF) {
    irsend.sendRC5x(0, 16, 12, 1); // power on
    delay(100);
    irsend.sendRC5x(1, 16, 12, 1); // power on
  } 
  else {
    irsend.sendRC5x(0, 16, 12, 2); // power off
    delay(100);
    irsend.sendRC5x(1, 16, 12, 2); // power off
  }
  digitalWrite(LED, LOW);

  avr_state = avr_state == ON ? OFF : ON;
  delay(5000);
}



