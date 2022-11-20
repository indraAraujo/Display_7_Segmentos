bool on = true;
bool off = false;

int pinA = 3;
int pinB = 2;
int pinC = 7;
int pinD = 8;
int pinE = 9;
int pinF = 4;
int pinG = 5;
int pinDP = 6;

int pinNext = 19;
int pinBack = 20;
int pinNextPinchange = A8;

char currentWord;
int displayTime = 2; // em segundos
void setup() {
  pinMode(pinA, OUTPUT);
  pinMode(pinB, OUTPUT);
  pinMode(pinC, OUTPUT);
  pinMode(pinD, OUTPUT);
  pinMode(pinE, OUTPUT);
  pinMode(pinF, OUTPUT);
  pinMode(pinG, OUTPUT);
  pinMode(pinDP, OUTPUT);
  pinMode(pinNext, INPUT_PULLUP);
  pinMode(pinBack, INPUT_PULLUP);
  pinMode(pinNextPinchange, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(pinNext), next, RISING);
  attachInterrupt(digitalPinToInterrupt(pinBack), back, CHANGE);
  initialisePinchange();
  initialiseTimer1();
}

void initialisePinchange() {
  cli();
  PCICR = 4; // pino A8
  PCMSK2 = 1;
  sei();
}

void initialiseTimer1() {
  cli();

  // reseta o timer;
  TCNT1 = 0;

  // reseta os registradores de controle A e B do timer
  TCCR1A = 0;
  TCCR1B = 0;

  // define o prescaler para clock/1024
  TCCR1B |= (1 << CS12);  // 1 no bit CS12
  TCCR1B &= ~(1 << CS11); // 0 no bit CS11 (para ter certeza que está zerado)
  TCCR1B |= (1 << CS10);  // 1 no bit CS10

  // define o tipo de interrupção para comparação
  TIMSK1 |= (1 << OCIE1A); // aciona o bit OCIE1A

  // define o tempo máximo para comparação
  // calculo do prescaler:
  // clock do sistema = 12MHz
  // tempo do contador = (tempo de display*clock)/prescaler -> T =
  // (2*12000000)/1024 = 23437
  OCR1A = 23437;

  // define o modo CTC para resetar o timer
  // automaticamente quando ocorrer uma interrupção
  // TCCR1B &= ~(1<<WGM13);
  // TCCR1B | = (1 << WGM12)

  sei();
}

void loop() {}

ISR(PCINT2_vect) {
  cli();
  next();
  sei();
}

ISR(TIMER1_COMPA_vect) {
  cli();
  // reseta o timer
  TCNT1 = 0;
  getNext();
  sei();
}
void H() {
  reset();
  digitalWrite(pinB, off);
  digitalWrite(pinC, off);
  digitalWrite(pinF, off);
  digitalWrite(pinE, off);
  digitalWrite(pinG, off);
}

void E() {
  reset();
  digitalWrite(pinA, off);
  digitalWrite(pinD, off);
  digitalWrite(pinE, off);
  digitalWrite(pinF, off);
  digitalWrite(pinG, off);
}

void L() {
  reset();
  digitalWrite(pinD, off);
  digitalWrite(pinE, off);
  digitalWrite(pinF, off);
}

void O() {
  reset();
  digitalWrite(pinA, off);
  digitalWrite(pinB, off);
  digitalWrite(pinC, off);
  digitalWrite(pinD, off);
  digitalWrite(pinE, off);
  digitalWrite(pinF, off);
}

void A() {
  reset();
  digitalWrite(pinA, off);
  digitalWrite(pinB, off);
  digitalWrite(pinC, off);
  digitalWrite(pinF, off);
  digitalWrite(pinE, off);
  digitalWrite(pinG, off);
}

void T() {
  reset();
  digitalWrite(pinA, off);
  digitalWrite(pinB, off);
  digitalWrite(pinC, off);
}

void M() {
  reset();
  digitalWrite(pinA, off);
  digitalWrite(pinC, off);
  digitalWrite(pinE, off);
}

void G() {
  reset();
  digitalWrite(pinA, off);
  digitalWrite(pinB, off);
  digitalWrite(pinC, off);
  digitalWrite(pinF, off);
  digitalWrite(pinD, off);
  digitalWrite(pinG, off);
}

void num3() {
  reset();
  digitalWrite(pinA, off);
  digitalWrite(pinB, off);
  digitalWrite(pinC, off);
  digitalWrite(pinD, off);
  digitalWrite(pinG, off);
}

void num2() {
  reset();
  digitalWrite(pinA, off);
  digitalWrite(pinB, off);
  digitalWrite(pinD, off);
  digitalWrite(pinE, off);
  digitalWrite(pinG, off);
}

void num8() {
  reset();
  digitalWrite(pinA, off);
  digitalWrite(pinB, off);
  digitalWrite(pinC, off);
  digitalWrite(pinD, off);
  digitalWrite(pinE, off);
  digitalWrite(pinF, off);
  digitalWrite(pinG, off);
}

void P() {
  reset();
  digitalWrite(pinA, off);
  digitalWrite(pinB, off);
  digitalWrite(pinE, off);
  digitalWrite(pinF, off);
  digitalWrite(pinG, off);
}

void space() {
  reset();
  digitalWrite(pinDP, off);
}
void getNext() {
  switch (currentWord) {
  case 1: // H
    currentWord = 2;
    E();
    break;
  case 2: // E 1
    currentWord = 3;
    L();
    break;
  case 3: // L 1
    currentWord = 4;
    L();
    break;
  case 4: // L 2
    currentWord = 5;
    O();
    break;
  case 5: // O
    currentWord = 6;
    space();
    break;
  case 6: // SPACE
    currentWord = 7;
    A();
    break;
  case 7: // A 1
    currentWord = 8;
    T();
    break;
  case 8: // T
    currentWord = 9;
    M();
    break;
  case 9: // M
    currentWord = 10;
    E();
    break;
  case 10: // E 2
    currentWord = 11;
    G();
    break;
  case 11: // G
    currentWord = 12;
    A();
    break;
  case 12: // A 2
    currentWord = 13;
    num3();
    break;
  case 13: // 3
    currentWord = 14;
    num2();
    break;
  case 14: // 2
    currentWord = 15;
    num8();
    break;
  case 15: // 8
    currentWord = 16;
    P();
    break;
  case 16: // P
    currentWord = 0;
    space();
    break;
  case 0: // SPACE 2
    currentWord = 1;
    H();
    break;
  }
}

void getBack() {
  switch (currentWord) {
  case 1:
    currentWord = 0;
    space();
    break;
  case 2:
    currentWord = 1;
    H();
    break;
  case 3:
    currentWord = 2;
    E();
    break;
  case 4:
    currentWord = 3;
    L();
    break;
  case 5:
    currentWord = 4;
    L();
    break;
  case 6:
    currentWord = 5;
    O();
    break;
  case 7:
    currentWord = 6;
    space();
    break;
  case 8:
    currentWord = 7;
    A();
    break;
  case 9:
    currentWord = 8;
    T();
    break;
  case 10:
    currentWord = 9;
    M();
    break;
  case 11:
    currentWord = 10;
    E();
    break;
  case 12:
    currentWord = 11;
    G();
    break;
  case 13:
    currentWord = 12;
    A();
    break;
  case 14:
    currentWord = 13;
    num3();
    break;
  case 15:
    currentWord = 14;
    num2();
    break;
  case 16:
    currentWord = 15;
    num8();
    break;
  case 0:
    currentWord = 16;
    P();
    break;
  }
}

void next() {
  cli();
  static unsigned long debounce = millis();
  if ((millis() - debounce) > 300) {
    debounce = millis();
    getNext();
  }
  sei();
}

void back() {
  cli();
  static unsigned long debounce = millis();
  if ((millis() - debounce) > 300) {
    debounce = millis();
    getBack();
  }
  sei();
}

void reset() {
  digitalWrite(pinA, on);
  digitalWrite(pinB, on);
  digitalWrite(pinC, on);
  digitalWrite(pinD, on);
  digitalWrite(pinE, on);
  digitalWrite(pinF, on);
  digitalWrite(pinG, on);
  digitalWrite(pinDP, on);
}
