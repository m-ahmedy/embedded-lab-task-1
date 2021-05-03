#include <Arduino.h>

#define BAUD_RATE 115200

#define DIGITAL_IN PD2
#define DIGITAL_OUT PD3

#define ANALOG_IN A0
#define ANALOG_OUT PD5

void setup() {
  // Digital Pins
  pinMode(DIGITAL_IN, INPUT);
  pinMode(DIGITAL_OUT, OUTPUT);

  // Analog Pins
  pinMode(ANALOG_OUT, OUTPUT);

  Serial.begin(BAUD_RATE);
  Serial.println("Hello from Task 1");
}

uint8_t curr_dval, prev_dval;
uint16_t curr_aval, prev_aval;

void loop() {
  // put your main code here, to run repeatedly:
  curr_dval = digitalRead(DIGITAL_IN);
  curr_aval = analogRead(ANALOG_IN);

  if (curr_dval != prev_dval) {
    Serial.print("Current digital value: ");
    Serial.println(curr_dval ? "High" : "Low");

    digitalWrite(DIGITAL_OUT, curr_dval);
  }

  if (curr_aval != prev_aval) {
    Serial.print("Current analog value: ");
    Serial.println(curr_aval);

    analogWrite(ANALOG_OUT, curr_aval / 4);
  }

  prev_dval = curr_dval;
  prev_aval = curr_aval;

  delay(200);
}