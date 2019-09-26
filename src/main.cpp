#include <Arduino.h>

#include <IRremote.h>
#include <marantz_avr_cmd_defs.h>

#define LED 13

#define ON  1
#define OFF 2

IRsend irsend;

// static unsigned int power_toggle[] = { 900,900,  900,900,   900,900,  1750,900, 900,900,  900,900,  900,900,  900,900,  900,1750,  900,900,  1750,900, 900 };

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(LED, OUTPUT);

  pinMode(7, INPUT); // temp button pin to control ir-output
}

void loop() {
  // int khz = 38; // 38kHz carrier frequency for the NEC protocol
  static int avr_state = OFF;

  int val = digitalRead(7); // read button

  static int cmd_to_run = MARANTZ_AVR_CMD_INPUT_TUNER;
  
  if (val == LOW) {
    digitalWrite(LED, LOW);
    // irsend.sendRaw(power_toggle, sizeof(power_toggle) / sizeof(power_toggle[0]), khz); //Note the approach used to automatically calculate the size of the array.

    // marantz_avr_cmd_config_t input_next = MARANTZ_AVR_CMDS[MARANTZ_AVR_CMD_INPUT_NEXT];
    // irsend.sendRC5x(0, input_next.address, input_next.command, input_next.extension);
    // delay(100);
    // irsend.sendRC5x(1, input_next.address, input_next.command, input_next.extension);

    marantz_avr_cmd_config_t input_next = MARANTZ_AVR_CMDS[cmd_to_run];
    if (input_next.type == MARANTZ_TYPE_RC5) {
      irsend.sendRC5(irsend.encodeRC5(input_next.address, input_next.command,0), 12);
      delay(100);
      irsend.sendRC5(irsend.encodeRC5(input_next.address, input_next.command,1), 12);
    }
    else {
      irsend.sendRC5x(0, input_next.address, input_next.command, input_next.extension);
      delay(100);
      irsend.sendRC5x(1, input_next.address, input_next.command, input_next.extension);
    }

    // next state
    cmd_to_run++;
    if (cmd_to_run == MARANTZ_AVR_CMD_NUM_CMDS) {
      cmd_to_run = MARANTZ_AVR_CMD_INPUT_TUNER;
    }

    // irsend.sendRC5(irsend.encodeRC5(16,12,0), 12);
    // delay(100);
    // irsend.sendRC5(irsend.encodeRC5(16,12,1), 12);

    // if (avr_state == OFF) {
    //   irsend.sendRC5x(0, 16, 12, 1); // power on
    //   delay(100);
    //   irsend.sendRC5x(1, 16, 12, 1); // power on
    // } 
    // else {
    //   irsend.sendRC5x(0, 16, 12, 2); // power off
    //   delay(100);
    //   irsend.sendRC5x(1, 16, 12, 2); // power off
    // }

    avr_state = avr_state == ON ? OFF : ON;
    delay(1000); // wait a second so we dont repeat input
  }
  else {
    digitalWrite(LED, HIGH);
  }
}



