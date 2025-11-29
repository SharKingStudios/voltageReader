// Libraries
#include <SPI.h>
#include <RF24.h>

RF24 radio(9,8); // Pin assignments for the NRF CE, CSN

// Node addresses
const byte address[6] = "00001";
boolean buttonState = 0;

void setup() {
  Serial.begin(9600); // Start the serial communication with the computer
  pinMode(A0, INPUT); // Set the A0 pin as input

  radio.begin();
  radio.openWritingPipe(address);
  radio.setPALevel(RF24_PA_MIN);
  radio.stopListening();
}

void loop() {
  int sensorValue = analogRead(A0); // Read the input on analog pin 0
  float voltage = sensorValue * (5.0 / 1023.0); // Convert the analog reading (which goes from 0 - 1023) to a voltage (0 - 5V)

  Serial.println(voltage);

  // Send out message using radio module
  sendVoltage(voltage);

  delay(10);
}

void displayNumber(int number) {
  // Display a thing
}

void sendVoltage(float volt){
  radio.write(&volt, sizeof(volt));
  //Serial.println("MESSAGE SENT!");
}