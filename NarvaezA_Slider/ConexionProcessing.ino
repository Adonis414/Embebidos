#include <TimerOne.h>

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Timer1.initialize(1000000);
  Timer1.attachInterrupt(conteo);
}

void loop() {

}

void conteo() {
  Serial.print(random(100));
}
