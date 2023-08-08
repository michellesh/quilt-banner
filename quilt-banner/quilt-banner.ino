#include "colors.h"
#include <FastLED.h>

#define DATA_PIN 13
#define LED_TYPE WS2812B
#define COLOR_ORDER GRB
#define NUM_LEDS 50
#define BRIGHTNESS 100

CRGB leds[NUM_LEDS];
uint8_t twinkleBrightness[NUM_LEDS];

#include "Palette.h"
Palette palette;

#include "radii.h"

void setup() {
  Serial.begin(115200);
  delay(500);
  FastLED.addLeds<LED_TYPE, DATA_PIN, COLOR_ORDER>(leds, NUM_LEDS);
  FastLED.setBrightness(BRIGHTNESS);

  setRadii();
}

void loop() {
  FastLED.clear();
  palette.cycle();

  ripple();

  FastLED.setBrightness(BRIGHTNESS);
  FastLED.show();
}

void ripple() {
  static float currentRadius = 0;
  float thickness = 50;

  for (int i = 0; i < NUM_LEDS; i++) {
    float diff = abs(currentRadius - radius[i]);
    if (diff < thickness) {
      int brightness = map(diff, 0, thickness, 255, 0);
      leds[i] = palette.getColor(i);
      leds[i].nscale8(brightness);
    } else {
      leds[i] = CRGB::Black;
    }
  }
  currentRadius += 0.2;
  if (currentRadius > maxRadius + thickness) {
    currentRadius = 0;
  }
}

void twinkle() {
  setTwinkleBrightness();

  for (int i = 0; i < NUM_LEDS; i++) {
    uint8_t hue = map(i, 0, NUM_LEDS, 0, 255);
    leds[i] = palette.getColor(i);
    leds[i].nscale8(twinkleBrightness[i]);
  }
}
