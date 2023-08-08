#define MAX_PALETTE_INDEX 240
#define SECONDS_PER_PALETTE 20

class Palette {
private:
  CRGBPalette16 _currentPalette = *(activePalettes[0]);
  CRGBPalette16 _targetPalette = *(activePalettes[0]);
  uint8_t _activeColorMode = GRADIENT;

  void _setNextColorPalette() {
    const uint8_t numberOfPalettes =
        sizeof(activePalettes) / sizeof(activePalettes[0]);
    static uint8_t whichPalette = -1;
    whichPalette = addmod8(whichPalette, 1, numberOfPalettes);

    _targetPalette = *(activePalettes[whichPalette]);
  }

public:
  static const uint8_t SOLID = 0;
  static const uint8_t GRADIENT = 1;
  static const uint8_t RAINBOW = 2;

  void cycle() {
    EVERY_N_SECONDS(SECONDS_PER_PALETTE) { _setNextColorPalette(); }

    EVERY_N_MILLISECONDS(10) {
      nblendPaletteTowardPalette(_currentPalette, _targetPalette, 12);
    }
  }

  CRGB mapToColor(int value, int fromLow, int fromHigh) {
    uint8_t paletteIndex = map(value, fromLow, fromHigh, 0, MAX_PALETTE_INDEX);
    return ColorFromPalette(_currentPalette, paletteIndex);
  }

  CRGB getColorFromPalette(uint8_t paletteIndex) {
    return ColorFromPalette(_currentPalette, paletteIndex);
  }

  CRGB getColor(uint8_t i) {
    uint8_t paletteIndex = 0;
    switch (_activeColorMode) {
    case RAINBOW: {
      //return rainbowColors[i];
    }
    case GRADIENT: {
      paletteIndex = map(i, 0, NUM_LEDS - 1, 0, MAX_PALETTE_INDEX);
      break;
    }
    default:
      break;
    }
    return ColorFromPalette(_currentPalette, paletteIndex);
  }
};
