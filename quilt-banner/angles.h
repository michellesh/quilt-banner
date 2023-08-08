float ANGLE[NUM_LEDS];

void initAngles() {
  // Right side of spark
  ANGLE[0] = 180;
  ANGLE[1] = 179;
  ANGLE[2] = 175;
  ANGLE[3] = 160;
  ANGLE[4] = 151;
  ANGLE[5] = 146;
  ANGLE[6] = 145;
  ANGLE[7] = 140;
  ANGLE[8] = 133;
  ANGLE[9] = 121;
  ANGLE[10] = 114;
  ANGLE[11] = 100;
  ANGLE[12] = 89;
  ANGLE[13] = 79;
  ANGLE[14] = 76;
  ANGLE[15] = 67;
  ANGLE[16] = 57;
  ANGLE[17] = 57;
  ANGLE[18] = 48;
  ANGLE[19] = 37;
  ANGLE[20] = 31;
  ANGLE[21] = 18;
  ANGLE[22] = 8;
  ANGLE[23] = 4;
  ANGLE[24] = 0;

  // Left side of spark. Subtract from 360 because angles were measured with top
  // pixel
  ANGLE[25] = 360 - 4;
  ANGLE[26] = 360 - 20;
  ANGLE[27] = 360 - 37;
  ANGLE[28] = 360 - 42;
  ANGLE[29] = 360 - 48;
  ANGLE[30] = 360 - 64;
  ANGLE[31] = 360 - 76;
  ANGLE[32] = 360 - 84;
  ANGLE[33] = 360 - 98;
  ANGLE[34] = 360 - 111;
  ANGLE[35] = 360 - 123;
  ANGLE[36] = 360 - 134;
  ANGLE[37] = 360 - 135;
  ANGLE[38] = 360 - 137;
  ANGLE[39] = 360 - 142;
  ANGLE[40] = 360 - 146;
  ANGLE[41] = 360 - 161;
  ANGLE[42] = 360 - 172;
  ANGLE[43] = 360 - 176;
}
