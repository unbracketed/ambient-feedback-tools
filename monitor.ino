/*
dev-lights
 
 Ambient feedback indicators for CI or test suite-related events
 */

int debug_led = 8;
int indicator_R = 9;
int indicator_G = 10;
int indicator_B = 11;


void setup() {                
  pinMode(debug_led, OUTPUT);   
  digitalWrite(debug_led, HIGH);
  pinMode(indicator_R, OUTPUT);   
  pinMode(indicator_G, OUTPUT);   
  pinMode(indicator_B, OUTPUT); 

  // test RGB LED
  blink_channel(indicator_R);
  blink_channel(indicator_G);
  blink_channel(indicator_B);  

  Serial.begin(9600);
  establishContact();
}


void blink_channel(int pin) {
  digitalWrite(pin, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);               // wait for a second
  digitalWrite(pin, LOW);    // turn the LED off by making the voltage LOW
  delay(1000);               // wait for a second
}


void loop() {
  //  blink_channel(debug_led);
  //   if we get a valid byte, read analog ins:
  if (Serial.available() > 0) {
    // get incoming byte:
    int inByte = Serial.read();
    blink_channel(indicator_G);
  }
}

void establishContact() {
  while (Serial.available() <= 0) {
    Serial.print('A');   // send a capital A
    delay(300);
  }
}



