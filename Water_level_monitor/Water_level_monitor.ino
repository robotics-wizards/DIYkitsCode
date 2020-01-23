int waterLevelPin = A2;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(waterLevelPin, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int lvl = analogRead(waterLevelPin);
  lvl = map(lvl, 0, 1023, 0, 100);

  if (lvl < 10) {
    Serial.println("Water level low. Please refill.");
    delay(10000); //wait for atleast 10 seconds
  }
  delay(1000);
}
