int pumpPin = 3;
int soilPin = A3;

void setup() {
  // put your setup code here, to run once:
  pinMode(pumpPin,OUTPUT);
  pinMode(soilPin,INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int moisture = analogRead(soilPin);

  if (moisture>400){
    digitalWrite(pumpPin,HIGH);
    delay(5000); //turn on pump for 5 seconds
    digitalWrite(pumpPin,LOW);
    delay(3600000); //wait for 1 hour before checking again
  }
}
