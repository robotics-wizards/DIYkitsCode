// Include the libraries we need
#include <OneWire.h>
#include <DallasTemperature.h>

int LEDpin = 3;
int MQpin  = A1;
int tempProbe = A0;

OneWire oneWire(tempProbe);

// Pass our oneWire reference to Dallas Temperature.
DallasTemperature sensors(&oneWire);

// arrays to hold device address
DeviceAddress insideThermometer;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  sensors.begin();

  sensors.setResolution(insideThermometer, 9);

  if (!sensors.getAddress(insideThermometer, 0)) Serial.println("Unable to find address for Device 0");

  pinMode(LEDpin, OUTPUT);

  digitalWrite(LEDpin, HIGH); //turn on the LED strip
}

void loop() {
  // put your main code here, to run repeatedly:
  float tempC = sensors.getTempC(insideThermometer);

  int MQ = analogRead(MQpin);

  String msg = "Soil Temperature: ");
  msg += tempC;
  msg += "\t Gas intensity: ");
  msg += MQ;

  Serial.println(msg);
  delay(100);
}
