bool on = true;
bool off = false;

int pinA1 = 3;
int pinB1 = 2;
int pinC1 = 7;
int pinD1 = 8;
int pinE1 = 9;
int pinF1 = 4;
int pinG1 = 5;

int pinA2 = 24;
int pinB2 = 22;
int pinC2 = 30;
int pinD2 = 32;
int pinE2 = 34;
int pinF2 = 26;
int pinG2 = 28;

int currentNumber1 = 0;
int currentNumber2=-1;

int counter=0;

void setup() {
  pinMode(pinA1, OUTPUT);
  pinMode(pinB1, OUTPUT);
  pinMode(pinC1, OUTPUT);
  pinMode(pinD1, OUTPUT);
  pinMode(pinE1, OUTPUT);
  pinMode(pinF1, OUTPUT);
  pinMode(pinG1, OUTPUT);
  
  pinMode(pinA2, OUTPUT);
  pinMode(pinB2, OUTPUT);
  pinMode(pinC2, OUTPUT);
  pinMode(pinD2, OUTPUT);
  pinMode(pinE2, OUTPUT);
  pinMode(pinF2, OUTPUT);
  pinMode(pinG2, OUTPUT);

  initialiseTimer1();
  initialiseTimer2();
}

void initialiseTimer1() {
  cli();

  // reseta o timer;
  TCNT1 = 0;

  // reseta os registradores de controle A e B do timer
  TCCR1A = 0;
  TCCR1B = 0;

  // define o prescaler para clock/256
  TCCR1B |= (1 << CS12);  // 1 no bit CS12
  TCCR1B &= ~(1 << CS11); // 0 no bit CS11 (para ter certeza que está zerado)
  TCCR1B &= ~(1 << CS11);  // 0 no bit CS10 (para ter certeza que está zerado)

  // define o tipo de interrupção para comparação
  TIMSK1 |= (1 << OCIE1A); // aciona o bit OCIE1A    
  
  // define o tempo máximo para comparação 
  OCR1A = 28125;
  
  sei();
}

void initialiseTimer2() {
  cli();
  
  // reseta o timer;
  TCNT2 = 0;

  // reseta os registradores de controle A e B do timer
  TCCR2A = 0;
  TCCR2B = 0;

  // define o prescaler para clock/1024
  TCCR2B |= (1 << CS22);  // 1 no bit CS22
  TCCR2B &= ~(1 << CS21); // 0 no bit CS21 (para ter certeza que está zerado)
  TCCR2B |= (1 << CS20);  // 1 no bit CS20

  // define o tipo de interrupção para overflow
  TIMSK2 |= (1 << TOIE2); // aciona o bit TOIE  

  
  sei();
}

void loop() {}


ISR(TIMER1_COMPA_vect) {
  cli();
  // reseta o timer
  TCNT1 = 0;
  currentNumber1++;
  if(currentNumber1==10){
    currentNumber1=0;
  }
  if(currentNumber1==9){
    currentNumber2++;
  }
  if(currentNumber2==10){
    currentNumber2=0;
  }

  sei();
}


ISR(TIMER2_OVF_vect) {
  cli();
  counter++;
  if(counter==200){
    //UNIDADES
    getNext(2,currentNumber1);
    //DEZENAS
    getNext(1,currentNumber2);
    counter=0;
  }
  sei();
}

void getNext(int display, char currentNumberChar) {
  switch (currentNumberChar) {
    case 0:
      num1(display);
      break;
    case 1:
      num2(display);
      break;
    case 2:
      num3(display);
      break;
     case 3:
      num4(display);
      break;
     case 4:
      num5(display);
      break;
     case 5:
      num6(display);
      break;
     case 6:
      num7(display);
      break;
     case 7:
      num8(display);
      break;
     case 8:
      num9(display);
      break;
     case 9:
      num0(display);
      break;
  }
}
