#include <Adafruit_NeoPixel.h>

#define PIN 2

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(512, PIN, NEO_GRB + NEO_KHZ800);

float cx = 0;
float cy = 0;

void setup() {
  pixels.begin();
  pixels.setBrightness(30);
  pixels.show();
  for (int i = 1; i <= 8; i++) {
    for (int a = 0; a < 360; a++) {
      cx = 4 + 3 * cos(radians(a));
      cy = 4 + -3 * sin(radians(a));
      pixels.setPixelColor(getPoint(round(cx), round(cy), i), pixels.Color(128, 0, 0));
    }
  }
  pixels.show();
}

void loop() {

}

int getPoint(int x, int y, int z) {
  return (x - 1) * 8 + (y - 1) + (z - 1) * 64;
}

