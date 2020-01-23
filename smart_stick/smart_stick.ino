void setup() {
  // put your setup code here, to run once:
  pinMode(A0, OUTPUT);
  pinMode(A1, INPUT);
  pinMode(A2, OUTPUT);
  Serial.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(A0, HIGH);
  delayMicroseconds(10);
  digitalWrite(A0, LOW);
  int duration = PulseIn(A1, HIGH);
  int distance = duration * 0.034 / 2;


  if (distance < 40) {
    digitalWrite(A2, HIGH);
    delay(50);
    digitalWrite(A2, LOW);
    delay(distance * 20);
  } else {
    delay(50);
  }
}
