// candle for Adafruit NeoPixel
// by Tim Bartlett, December 2013

// Call CANDLE STATES, with duration in seconds
// 1. on() = solid yellow
// 2. burn() = candle is flickering normally
// 3. flutter() = candle needs air
// 4. flicker() = use sparingly, wind on candle

#include <Adafruit_NeoPixel.h>
#define PIN 6

int grnHigh = 130; //130 for 5v, 3.3v tbd
int bluePx = 10; //10 for 5v, 3.3v tbd
int fDelay;// = 4;
int fRep;// = 120;
int burnDelay = 4;
int burnLow = 118;
int flutDelay = 3;
int flutLow = 112;
int flickDelay = 2;
int flickLow = 105;

Adafruit_NeoPixel strip = Adafruit_NeoPixel(1, PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  strip.begin();
  strip.show();
}

void loop() {
  on(3);
  burn(15);
  flutter(5);
  burn(3);
  flicker(1);
  burn(10);
  flutter(1);
  flicker(2);
  flutter(3);
  
}


// basic fire funciton - not called in main loop
void fire(int grnLow) {
  for (int grnPx = grnHigh; grnPx > grnLow; grnPx--) {
    strip.setPixelColor(0, 255, grnPx, bluePx);
    strip.show();
    delay(fDelay);
  }  
  for (int grnPx = grnLow; grnPx < grnHigh; grnPx++) {
    strip.setPixelColor(0, 255, grnPx, bluePx);
    strip.show();
    delay(fDelay);
  }
}

// fire animation
void on(int f) {
  fRep = f * 1000;  
  strip.setPixelColor(0, 255, grnHigh, bluePx);
  strip.show();
  delay(fRep);
}

void burn(int f) {
  fRep = f * 8;
  fDelay = burnDelay;
  for (int var = 0; var < fRep; var++) {
    fire(burnLow);
  }  
}

void flutter(int f) {
  fRep = f * 8;
  fDelay = burnDelay;
  fire(burnLow);
  fDelay = flutDelay;
  for (int var = 0; var < fRep; var++) {
    fire(flutLow);
  }
  fDelay = burnDelay;
  fire(burnLow);
}

void flicker(int f) {
  fRep = f * 8;  
  fDelay = burnDelay;
  fire(burnLow);
  fDelay = flutDelay;
  fire(flutLow);
  fDelay = flickDelay;
  for (int var = 0; var < fRep; var++) {
    fire(flickLow);
  }
  fDelay = flutDelay;
  fire(flutLow);
  fDelay = burnDelay;
  fire(burnLow);
  fire(burnLow);
}

/* notes for multiple pixels
For an 8 pixel strip as one bright source, center pixels (3, 4) are full dip, neighbors (1, 2, 5, 6) are half, and outer (0, 7) are always on. Alternately, any pixel can flicker, and pixel+1 and pixel-1 run at half.
halfPx = grnHigh - ((grnHigh - grnPx) / 2)
*/
