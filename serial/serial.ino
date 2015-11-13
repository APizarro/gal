volatile int rpmcont;
int Calc;
int pin_sensor=6;

void rpm(){
  rpmcont++;
}

void setup(){
Serial.begin(9600);
delay(1000);
rpmcont=0;

attachInterrupt(pin_sensor,rpm,RISING);
}

void loop(){
rpmcont=0;
interrupts();
delay(1000);
noInterrupts();
Calc=(rpmcont);

Serial.print(Calc,DEC);
attachInterrupt(pin_sensor,rpm,RISING);
}
