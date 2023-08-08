float angle[NUM_LEDS];

void initAngles() {
  // Right side of spark
  angle[0] = 180;
  angle[1] = 179;
  angle[2] = 175;
  angle[3] = 160;
  angle[4] = 151;
  angle[5] = 146;
  angle[6] = 145;
  angle[7] = 140;
  angle[8] = 133;
  angle[9] = 121;
  angle[10] = 114;
  angle[11] = 100;
  angle[12] = 89;
  angle[13] = 79;
  angle[14] = 76;
  angle[15] = 67;
  angle[16] = 57;
  angle[17] = 57;
  angle[18] = 48;
  angle[19] = 37;
  angle[20] = 31;
  angle[21] = 18;
  angle[22] = 8;
  angle[23] = 4;
  angle[24] = 0;

  // Left side of spark. Subtract from 360 because angles were measured with top
  // pixel
  angle[25] = 360 - 4;
  angle[26] = 360 - 20;
  angle[27] = 360 - 37;
  angle[28] = 360 - 42;
  angle[29] = 360 - 48;
  angle[30] = 360 - 64;
  angle[31] = 360 - 76;
  angle[32] = 360 - 84;
  angle[33] = 360 - 98;
  angle[34] = 360 - 111;
  angle[35] = 360 - 123;
  angle[36] = 360 - 134;
  angle[37] = 360 - 135;
  angle[38] = 360 - 137;
  angle[39] = 360 - 142;
  angle[40] = 360 - 146;
  angle[41] = 360 - 161;
  angle[42] = 360 - 172;
  angle[43] = 360 - 176;
}
