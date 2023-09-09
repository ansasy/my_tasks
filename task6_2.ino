// Rotary Encoder Pins
const int encoderPinA = 2;
const int encoderPinB = 3; 

int count = 0;         

void setup() {
  pinMode(encoderPinA, INPUT_PULLUP);
  pinMode(encoderPinB, INPUT_PULLUP);

  attachInterrupt(digitalPinToInterrupt(encoderPinA), updateEncoderA, CHANGE);
  attachInterrupt(digitalPinToInterrupt(encoderPinB), updateEncoderB, CHANGE);

  Serial.begin(9600); // Initialize the Serial Monitor
}

void loop() {
 // handled by interrupts
}

void updateEncoderA() {
  if (digitalRead(encoderPinA) != digitalRead(encoderPinB)) {
      count++;
    } else {
      count--;
  
  }


  // Print the count to the Serial Monitor
  Serial.print("Count: ");
  Serial.println(count);
}

void updateEncoderB() {
  if (digitalRead(encoderPinA) != digitalRead(encoderPinB)) {
    count++;
  } else {
    count--;
  }
  // Print the count to the Serial Monitor
  Serial.print("Count2: ");
  Serial.println(count);
}
