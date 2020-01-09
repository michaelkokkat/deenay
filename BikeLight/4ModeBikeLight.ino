const int button = 9;              // switch is connected to pin 9
const int led1 = 4;
const int led2 = 5;
const int led3 = 6;
const int led4 = 7;
const int led5 = 8;

int ledState = LOW;             // ledState used to set the LED
int buttonState = digitalRead(button);
// Generally, you should use "unsigned long" for variables that hold time
// The value will quickly become/ too large for an int to store
unsigned long previousMillis = 0;        // will store last time LED was updated

// constants won't change:
const long interval1 = 500;           // interval at which to blink (milliseconds)
const long interval2 = 200;   

void setup() {
  // put your setup code here, to run once:
  pinMode(button, INPUT);    // Set the switch pin as input
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  pinMode(led5, OUTPUT);

  Serial.begin(9600);           // Set up serial communication at 9600bps
  buttonState = digitalRead(button);   // read the initial state
}

void loop() {
  uint8_t i;
  // put your main code here, to run repeatedly:
  while(buttonState == LOW){
    digitalWrite(led1, ledState);
    digitalWrite(led2, ledState);
    digitalWrite(led3, ledState);
    digitalWrite(led4, ledState);  
    digitalWrite(led5, ledState);
    buttonState = digitalRead(button);}
  
  buttonState = digitalRead(button);
  ledState = HIGH;
  
  while(buttonState == LOW){
    digitalWrite(led1, ledState);
    digitalWrite(led2, ledState);
    digitalWrite(led3, ledState);
    digitalWrite(led4, ledState);  
    digitalWrite(led5, ledState);
    buttonState = digitalRead(button);
  }
  
  buttonState = digitalRead(button);
  
  while(buttonState == LOW){
    unsigned long currentMillis = millis();

    if (currentMillis - previousMillis >= interval1) {
    // save the last time you blinked the LED
      previousMillis = currentMillis;

    // if the LED is off turn it on and vice-versa:
      if (ledState == LOW) {
        ledState = HIGH;
        } 
      else {
          ledState = LOW;
          }

      digitalWrite(led1, ledState);
      digitalWrite(led2, !ledState);
      digitalWrite(led3, ledState);
      digitalWrite(led4, !ledState);  
      digitalWrite(led5, ledState);
  }
  buttonState = digitalRead(button);
  }
  
  buttonState = digitalRead(button);
  ledState = HIGH;
  digitalWrite(led1, !ledState);
  digitalWrite(led2, !ledState);
  digitalWrite(led3, !ledState);
  digitalWrite(led4, !ledState);  
  digitalWrite(led5, !ledState);
  
  while(buttonState == LOW){

      for(i=4;i<9;i++){
        unsigned long currentMillis = millis();
        if (currentMillis - previousMillis >= interval2) {
          previousMillis = currentMillis;
          digitalWrite(i, ledState);
          digitalWrite(i-1, !ledState);}
        }
      for(i=7;i>3;i--){
        unsigned long currentMillis = millis();
        if (currentMillis - previousMillis >= interval2) {
          previousMillis = currentMillis;
          digitalWrite(i, ledState);
          digitalWrite(i+1, !ledState);
        }
      }
  }


}
