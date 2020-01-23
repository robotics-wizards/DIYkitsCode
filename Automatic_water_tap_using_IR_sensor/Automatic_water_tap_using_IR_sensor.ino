int pumpPin = 4;
int IRpin = 3;

void setup() {
  // put your setup code here, to run once:
  pinMode(pumpPin, OUTPUT);
  pinMode(IRpin, INPUT);
  digitalWrite(pumpPin, HIGH);
}

void loop() {
  // put your main code here, to run repeatedly:
  bool IN = digitalRead(IRpin);
  if (IN == HIGH) {
    digitalWrite(pumpPin, HIGH);
  } else {
    delay(1000);
    digitalWrite(pumpPin, LOW);
  }
}
