#include<Wire.h>

void setup() {
  // put your setup code here, to run once:
  Wire.begin(); // join i2c bus (address optional for master)
  Wire.beginTransmission(0x68);
  Wire.write(0x6B); // PWR_MGMT_1 register
  Wire.write(0);    // set to zero (wakes up the MPU-6050)
  Wire.endTransmission(true);
  Serial.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly:
  Wire.beginTransmission(0x68);
  Wire.write(0x3B); // starting with register 0x3B (ACCEL_XOUT_H)
  Wire.endTransmission();
  Wire.beginTransmission(0x68);
  Wire.requestFrom(0x68, 6); // request a total of 6 registers
  int accX = Wire.read() << 8 | Wire.read();
  int accY = Wire.read() << 8 | Wire.read();
  int accZ = Wire.read() << 8 | Wire.read();

  if (accX < -32768)
    accX += 65536;
  if (accY > 32768)
    accY -= 65536;

  accX /= 100;
  accY /= 100;

  accX = map(accX, -163, 163, -90, 90);
  accY = map(accY, -163, 163, -90, 90);

  int threshold = accX + accY;
  if (threshold > 40){
    Serial.println("Person has fallen");
    delay(1000);
  }
  delay(9);
}
