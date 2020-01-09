// Bike light

int switchPin = 9;              // switch is connected to pin 9
int led1Pin = 4;
int led2Pin = 5;
int led3Pin = 6;
int led4Pin = 7;
int led5Pin = 8;

int val;                        // variable for reading the pin status
int val2;                       // variable for reading the delayed status
int buttonState;                // variable to hold the button state

int lightMode = 0;              // What mode is the light in?

// Variables will change:
int ledState = LOW;             // ledState used to set the LED

// Generally, you should use "unsigned long" for variables that hold time
// The value will quickly become too large for an int to store
unsigned long previousMillis = 0;        // will store last time LED was updated

// constants won't change:
const long interval = 500;           // interval at which to blink (milliseconds)

void setup()
// put your setup code here, to run once:
{
  pinMode(switchPin, INPUT);    // Set the switch pin as input

  pinMode(led1Pin, OUTPUT);
  pinMode(led2Pin, OUTPUT);
  pinMode(led3Pin, OUTPUT);
  pinMode(led4Pin, OUTPUT);
  pinMode(led5Pin, OUTPUT);

  Serial.begin(9600);           // Set up serial communication at 9600bps
  buttonState = digitalRead(switchPin);   // read the initial state
}

void loop()
// put your main code here, to run repeatedly:

{

 
  val = digitalRead(switchPin);      // read input value and store it in val
  delay(10);                         // 10 milliseconds is a good amount of time
  val2 = digitalRead(switchPin);     // read the input again to check for bounces
  if (val == val2) {                 // make sure we got 2 consistant readings!
    if (val != buttonState) {          // the button state has changed!
      if (val == LOW) {                // check if the button is pressed
        if (lightMode == 0) {          // if its off
          lightMode = 1;               // turn lights on!
        } else {
          if (lightMode == 1) {        // if its all-on
            lightMode = 2;             // make it blink!
          } else {
            if (lightMode == 2) {      // if its blinking
              lightMode = 3;           // make it wave!
            } else {
              if (lightMode == 3) { //  if its waving,
                lightMode = 0;           // turn light off!
              }
            }
          }
        }
      }
    }
    buttonState = val;                 // save the new state in our variable
  }

  // Now do whatever the lightMode indicates
  if (lightMode == 0) { // all-off
    digitalWrite(led1Pin, LOW);
    digitalWrite(led2Pin, LOW);
    digitalWrite(led3Pin, LOW);
    digitalWrite(led4Pin, LOW);
    digitalWrite(led5Pin, LOW);
  }

  if (lightMode == 1) { // all-on
    digitalWrite(led1Pin, HIGH);
    digitalWrite(led2Pin, HIGH);
    digitalWrite(led3Pin, HIGH);
    digitalWrite(led4Pin, HIGH);
    digitalWrite(led5Pin, HIGH);
  }

  if (lightMode == 2) { // blinking
    unsigned long currentMillis = millis();

    if (currentMillis - previousMillis >= interval) {
      // save the last time you blinked the LED
      previousMillis = currentMillis;

      // if the LED is off turn it on and vice-versa:
      if (ledState == LOW) {
        ledState = HIGH;
      } else {
        ledState = LOW;
      }

      // set the LED with the ledState of the variable:
      digitalWrite(led1Pin, ledState);
      digitalWrite(led2Pin, !ledState);
      digitalWrite(led3Pin, ledState);
      digitalWrite(led4Pin, !ledState);
      digitalWrite(led5Pin, ledState);
   
    }

  }
  if (lightMode == 3)  { // "wave"
  digitalWrite(led1Pin, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(100);               // wait for a second
  digitalWrite(led1Pin, LOW);    // turn the LED off by making the voltage LOW
  delay(100);
  {digitalWrite(led2Pin, HIGH);
delay(100);
digitalWrite(led2Pin, LOW);
delay(100);}
{digitalWrite(led3Pin, HIGH);
delay(100);
digitalWrite(led3Pin, LOW);
delay(100);}
{digitalWrite(led4Pin, HIGH);
delay(100);
digitalWrite(led4Pin, LOW);
delay(100);}
{digitalWrite(led5Pin, HIGH);
delay(100);
digitalWrite(led5Pin, LOW);
delay(100);}
  }
}
