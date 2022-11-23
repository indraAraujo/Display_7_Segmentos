void num0(int display) {
  reset(display);
  if (display == 1) {
    digitalWrite(pinA1, off);
    digitalWrite(pinB1, off);
    digitalWrite(pinC1, off);
    digitalWrite(pinD1, off);
    digitalWrite(pinE1, off);
    digitalWrite(pinF1, off);
  } else {
    digitalWrite(pinA2, off);
    digitalWrite(pinB2, off);
    digitalWrite(pinC2, off);
    digitalWrite(pinD2, off);
    digitalWrite(pinE2, off);
    digitalWrite(pinF2, off);
  }
}

void num1(int display) {
  reset(display);
  if (display == 1) {
    digitalWrite(pinB1, off);
    digitalWrite(pinC1, off);
  } else {
    digitalWrite(pinB2, off);
    digitalWrite(pinC2, off);
  }
}

void num2(int display) {
  reset(display);
  if (display == 1) {
    digitalWrite(pinA1, off);
    digitalWrite(pinB1, off);
    digitalWrite(pinD1, off);
    digitalWrite(pinE1, off);
    digitalWrite(pinG1, off);
  } else {
    digitalWrite(pinA2, off);
    digitalWrite(pinB2, off);
    digitalWrite(pinD2, off);
    digitalWrite(pinE2, off);
    digitalWrite(pinG2, off);
  }
}

void num3(int display) {
  reset(display);
  if (display == 1) {
    digitalWrite(pinA1, off);
    digitalWrite(pinB1, off);
    digitalWrite(pinC1, off);
    digitalWrite(pinD1, off);
    digitalWrite(pinG1, off);
  } else {
    digitalWrite(pinA2, off);
    digitalWrite(pinB2, off);
    digitalWrite(pinC2, off);
    digitalWrite(pinD2, off);
    digitalWrite(pinG2, off);
  }
}

void num4(int display) {
  reset(display);
  if (display == 1) {
    digitalWrite(pinB1, off);
    digitalWrite(pinC1, off);
    digitalWrite(pinF1, off);
    digitalWrite(pinG1, off);
  } else {
    digitalWrite(pinB2, off);
    digitalWrite(pinC2, off);
    digitalWrite(pinF2, off);
    digitalWrite(pinG2, off);
  }
}

void num5(int display) {
  reset(display);
  if (display == 1) {
    digitalWrite(pinA1, off);
    digitalWrite(pinC1, off);
    digitalWrite(pinD1, off);
    digitalWrite(pinF1, off);
    digitalWrite(pinG1, off);
  } else {
    digitalWrite(pinA2, off);
    digitalWrite(pinC2, off);
    digitalWrite(pinD2, off);
    digitalWrite(pinF2, off);
    digitalWrite(pinG2, off);
  }
}

void num6(int display) {
  reset(display);
  if (display == 1) {
    digitalWrite(pinA1, off);
    digitalWrite(pinC1, off);
    digitalWrite(pinD1, off);
    digitalWrite(pinE1, off);
    digitalWrite(pinF1, off);
    digitalWrite(pinG1, off);
  } else {
    digitalWrite(pinA2, off);
    digitalWrite(pinC2, off);
    digitalWrite(pinD2, off);
    digitalWrite(pinE2, off);
    digitalWrite(pinF2, off);
    digitalWrite(pinG2, off);
  }
}

void num7(int display) {
  reset(display);
  if (display == 1) {
    digitalWrite(pinA1, off);
    digitalWrite(pinB1, off);
    digitalWrite(pinC1, off);
  } else {
    digitalWrite(pinA2, off);
    digitalWrite(pinB2, off);
    digitalWrite(pinC2, off);
  }
}

void num8(int display) {
  reset(display);
  if (display == 1) {
    digitalWrite(pinA1, off);
    digitalWrite(pinB1, off);
    digitalWrite(pinC1, off);
    digitalWrite(pinD1, off);
    digitalWrite(pinE1, off);
    digitalWrite(pinF1, off);
    digitalWrite(pinG1, off);
  } else {
    digitalWrite(pinA2, off);
    digitalWrite(pinB2, off);
    digitalWrite(pinC2, off);
    digitalWrite(pinD2, off);
    digitalWrite(pinE2, off);
    digitalWrite(pinF2, off);
    digitalWrite(pinG2, off);
  }
}

void num9(int display) {
  reset(display);
  if (display == 1) {
    digitalWrite(pinA1, off);
    digitalWrite(pinB1, off);
    digitalWrite(pinC1, off);
    digitalWrite(pinF1, off);
    digitalWrite(pinG1, off);
  } else {
    digitalWrite(pinA2, off);
    digitalWrite(pinB2, off);
    digitalWrite(pinC2, off);
    digitalWrite(pinF2, off);
    digitalWrite(pinG2, off);
  }
}

void reset(int display) {
  if (display == 1) {
    digitalWrite(pinA1, on);
    digitalWrite(pinB1, on);
    digitalWrite(pinC1, on);
    digitalWrite(pinD1, on);
    digitalWrite(pinE1, on);
    digitalWrite(pinF1, on);
    digitalWrite(pinG1, on);
  } else {
    digitalWrite(pinA2, on);
    digitalWrite(pinB2, on);
    digitalWrite(pinC2, on);
    digitalWrite(pinD2, on);
    digitalWrite(pinE2, on);
    digitalWrite(pinF2, on);
    digitalWrite(pinG2, on);
  }
}
