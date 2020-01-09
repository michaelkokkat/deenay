// NeoPixel Ring simple sketch (c) 2013 Shae Erisson
// Released under the GPLv3 license to match the rest of the
// Adafruit NeoPixel library

#include <Adafruit_NeoPixel.h>
#include <MPU6050_tockn.h>
#include <Wire.h>
#ifdef __AVR__
#include <avr/power.h> // Required for 16 MHz Adafruit Trinket
#endif

MPU6050 mpu6050(Wire);

// Which pin on the Arduino is connected to the NeoPixels?
#define PIN        9 // On Trinket or Gemma, suggest changing this to 1

// How many NeoPixels are attached to the Arduino?
#define NUMPIXELS 16 // Popular NeoPixel ring size

// When setting up the NeoPixel library, we tell it how many pixels,
// and which pin to use to send signals. Note that for older NeoPixel
// strips you might need to change the third parameter -- see the
// strandtest example for more information on possible values.
Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

#define DELAYVAL 500 // Time (in milliseconds) to pause between pixels
unsigned long previousMillis = 0;
unsigned long currentMillis = 0;
int interval = 200;
int die;
int finalinterval = 5000;
void setup() {
  Serial.begin(9600);
  Wire.begin();
  mpu6050.begin();
  mpu6050.calcGyroOffsets(true);
#if defined(__AVR_ATtiny85__) && (F_CPU == 16000000)
  clock_prescale_set(clock_div_1);
#endif


  pixels.begin(); // INITIALIZE NeoPixel strip object (REQUIRED)
}

void loop() {
  mpu6050.update();
  pixels.clear();
  if ((abs(mpu6050.getAccX()) > 0.85) || ((abs(mpu6050.getAccX()) > 0.85))) {
    for (int shakingcounter = 0; shakingcounter < 6; shakingcounter++)
    {
      pixels.clear(); // Set all pixel colors to 'off'
      pixels.setPixelColor(0, pixels.Color(255, 0, 255));
      pixels.setPixelColor(2, pixels.Color(255, 0, 255));
      pixels.setPixelColor(4, pixels.Color(255, 0, 255));
      pixels.setPixelColor(6, pixels.Color(255, 0, 255));
      pixels.setPixelColor(8, pixels.Color(255, 0, 255));
      pixels.setPixelColor(10, pixels.Color(255, 0, 255));
      pixels.setPixelColor(12, pixels.Color(255, 0, 255));
      pixels.setPixelColor(14, pixels.Color(255, 0, 255));
      pixels.setPixelColor(16, pixels.Color(255, 0, 255));
      pixels.show();
      currentMillis = millis();
      while (currentMillis - previousMillis <= interval) {
        currentMillis = millis();
      }
      pixels.clear();
      previousMillis = currentMillis;
      pixels.setPixelColor(1, pixels.Color(255, 0, 255));
      pixels.setPixelColor(3, pixels.Color(255, 0, 255));
      pixels.setPixelColor(5, pixels.Color(255, 0, 255));
      pixels.setPixelColor(7, pixels.Color(255, 0, 255));
      pixels.setPixelColor(9, pixels.Color(255, 0, 255));
      pixels.setPixelColor(11, pixels.Color(255, 0, 255));
      pixels.setPixelColor(13, pixels.Color(255, 0, 255));
      pixels.setPixelColor(15, pixels.Color(255, 0, 255));
      pixels.show();
      currentMillis = millis();
      while (currentMillis - previousMillis <= interval) {
        currentMillis = millis();
      }
      previousMillis = currentMillis;
      pixels.clear();
    }
    die = random(1, 7);
    if (die == 1)
    {
      pixels.setPixelColor(0, pixels.Color(0, 0, 255));
      pixels.show();
      currentMillis = millis();
      while (currentMillis - previousMillis <= interval) {
        currentMillis = millis();
      }
      previousMillis = currentMillis;
      pixels.clear();
    }
    if (die == 2)
    {
      pixels.setPixelColor(3, pixels.Color(0, 0, 255));
      pixels.setPixelColor(11, pixels.Color(0, 0, 255));
      pixels.show();
      currentMillis = millis();
      while (currentMillis - previousMillis <= interval) {
        currentMillis = millis();
      }
      previousMillis = currentMillis;
      pixels.clear();
    }
    if (die == 3)
    {
      pixels.setPixelColor(4, pixels.Color(0, 0, 255));
      pixels.setPixelColor(9, pixels.Color(0, 0, 255));
      pixels.setPixelColor(14, pixels.Color(0, 0, 255));
      pixels.show();
      currentMillis = millis();
      while (currentMillis - previousMillis <= interval) {
        currentMillis = millis();
      }
      previousMillis = currentMillis;
      pixels.clear();
    }
    if (die == 4)
    {
      pixels.setPixelColor(3, pixels.Color(0, 0, 255));
      pixels.setPixelColor(7, pixels.Color(0, 0, 255));
      pixels.setPixelColor(11, pixels.Color(0, 0, 255));
      pixels.setPixelColor(15, pixels.Color(0, 0, 255));
      pixels.show();
      currentMillis = millis();
      while (currentMillis - previousMillis <= interval) {
        currentMillis = millis();
      }
      previousMillis = currentMillis;
      pixels.clear();
    }
    if (die == 5)
    {
      pixels.setPixelColor(2, pixels.Color(0, 0, 255));
      pixels.setPixelColor(5, pixels.Color(0, 0, 255));
      pixels.setPixelColor(8, pixels.Color(0, 0, 255));
      pixels.setPixelColor(11, pixels.Color(0, 0, 255));
      pixels.setPixelColor(14, pixels.Color(0, 0, 255));
      pixels.show();
      currentMillis = millis();
      while (currentMillis - previousMillis <= interval) {
        currentMillis = millis();
      }
      previousMillis = currentMillis;
      pixels.clear();
    }
    if (die == 6)
    {
      pixels.setPixelColor(2, pixels.Color(0, 0, 255));
      pixels.setPixelColor(3, pixels.Color(0, 0, 255));
      pixels.setPixelColor(4, pixels.Color(0, 0, 255));
      pixels.setPixelColor(9, pixels.Color(0, 0, 255));
      pixels.setPixelColor(10, pixels.Color(0, 0, 255));
      pixels.setPixelColor(11, pixels.Color(0, 0, 255));
      pixels.show();
      currentMillis = millis();
      while (currentMillis - previousMillis <= interval) {
        currentMillis = millis();
      }
      previousMillis = currentMillis;
      pixels.clear();
    }
  }
}
