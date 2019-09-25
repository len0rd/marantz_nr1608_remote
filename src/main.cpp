#include <Arduino.h>

// marantx uses a mix of RC5 and RC5x
#define SEND_RC5
#define SEND_RC5X

#include <IRremote.h>

#define LED 13

IRsend irsend;

static unsigned int power_toggle[] = { 900,900,  900,900,   900,900,  1750,900, 900,900,  900,900,  900,900,  900,900,  900,1750,  900,900,  1750,900, 900 };

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(LED, OUTPUT);
}

void loop() {
  int khz = 38; // 38kHz carrier frequency for the NEC protocol
  static int led_state = HIGH;
  
  digitalWrite(LED_BUILTIN, led_state);
  digitalWrite(LED, HIGH);
  // irsend.sendRaw(power_toggle, sizeof(power_toggle) / sizeof(power_toggle[0]), khz); //Note the approach used to automatically calculate the size of the array.
  irsend.sendRC5x();
  digitalWrite(LED, LOW);

  led_state = led_state == HIGH ? LOW : HIGH;
  delay(5000); // 10s repeat
}



