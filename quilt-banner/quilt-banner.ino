#include <FastLED.h>

#include "colors.h"

#define DATA_PIN 13
#define LED_TYPE WS2812B
#define COLOR_ORDER GRB
#define NUM_LEDS 44
#define BRIGHTNESS 100

#define SECONDS_PER_PATTERN 20
#define NUM_MODES 3

CRGB leds[NUM_LEDS];
uint8_t twinkleBrightness[NUM_LEDS];

#include "Palette.h"
Palette palette;

#include "angles.h"
#include "radii.h"

void setup() {
  Serial.begin(115200);
  delay(500);
  FastLED.addLeds<LED_TYPE, DATA_PIN, COLOR_ORDER>(leds, NUM_LEDS);
  FastLED.setBrightness(BRIGHTNESS);

  initRadii();
  initAngles();
}

void loop() {
  FastLED.clear();
  palette.cycle();

  static int mode = 0;

  EVERY_N_SECONDS(SECONDS_PER_PATTERN) {
    mode = (mode + 1) % NUM_MODES;
  }

  switch (mode) {
    case 0:
    twinkle();
    break;
    case 1:
    ripple();
    break;
    case 2:
    spiral();
    break;
  }

  FastLED.setBrightness(BRIGHTNESS);
  FastLED.show();
}

bool isBetween(float value, float _min, float _max, bool inclusive = false) {
  return inclusive ? value >= _min && value <= _max
                   : value > _min && value < _max;
}

float getAngleDiff(float targetAngle, float pixelAngle, float width) {
  // Calculate distance from the current angle. If angle is near end
  // (360-width < a < 360), also check LEDs near beginning. If angle is near
  // beginning (0 < a < width), also check LEDs near end
  float diff;
  if (targetAngle > 360 - width) {
    diff = abs(targetAngle - (pixelAngle + 360));
    if (isBetween(diff, 0, width)) {
      return diff;
    }
  }
  if (targetAngle < width) {
    diff = abs(targetAngle - (pixelAngle - 360));
    if (isBetween(diff, 0, width)) {
      return diff;
    }
  }
  return abs(targetAngle - pixelAngle);
}

void spiral() {
  static float targetAngle = 0;
  float thickness = 50;

  for (int i = 0; i < NUM_LEDS; i++) {
    float diffAngle = getAngleDiff(targetAngle, ANGLE[i], thickness);
    if (diffAngle < thickness) {
      int brightness = map(diffAngle, 0, thickness, 255, 0);
      leds[i] = palette.mapToColor(ANGLE[i], 0, 360);
      leds[i].nscale8(brightness);
    } else {
      leds[i] = CRGB::Black;
    }
  }

  targetAngle += 0.5;
  if (targetAngle > 360) {
    targetAngle = 0;
  }
}

void ripple() {
  float thickness = 50;
  static float targetRadius = MIN_RADIUS - thickness;

  for (int i = 0; i < NUM_LEDS; i++) {
    float diff = abs(targetRadius - RADIUS[i]);
    if (diff < thickness) {
      int brightness = map(diff, 0, thickness, 255, 0);
      leds[i] = palette.mapToColor(RADIUS[i], MIN_RADIUS, MAX_RADIUS);
      leds[i].nscale8(brightness);
    } else {
      leds[i] = CRGB::Black;
    }
  }
  targetRadius += 0.2;
  if (targetRadius > MAX_RADIUS + thickness) {
    targetRadius = MIN_RADIUS - thickness;
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
