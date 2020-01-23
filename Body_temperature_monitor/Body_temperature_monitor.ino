const int lm35_pin = A0;  /* LM35 O/P pin */

void setup() {
  Serial.begin(115200);
}

void loop() {
  int temp_adc_val;
  float temp_val;
  temp_adc_val = analogRead(lm35_pin);  /* Read Temperature */
  temp_val = (temp_adc_val * 4.88); /* Convert adc value to equivalent voltage */
  temp_val = (temp_val / 10); /* LM35 gives output of 10mv/°C */

  if (temp_val > 40) {  // heat stroke typically happens on body temperatures of over 40 degrees celcius.
    Serial.println("Heat stroke detected");
    delay(1000);
  }
  delay(10);
}
