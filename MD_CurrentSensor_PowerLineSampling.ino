/*
  Test Current Sensor
  Reads the sensor at integrals of power line frequency
  to smooth output values.

  Hardware: Modern Device Current Sensor Output on pin A0
  Arduino ground Modern Device Current Sensor ground
  Arduino +5V to Modern Device Current Sensor +5 volts
*/

void setup() {
  delay(1500); // let serial monitor open
  Serial.begin(9600);
  Serial.print("Current Sensor Test");
}

void loop() {

  float total = 0;
  long reads = 0;  // just to monitor performance
  //               // feel free to delete  unsigned long start = millis();

   
  // read four power cycles
  const unsigned long PowerLineIntegralDelayMS = (4 * 1000/60);
  //const unsigned long EU_PowerLineIntegralDelayMS = (4 * 1000/50); // use in EU
  
  unsigned long start = millis();
  while  (millis() - start < PowerLineIntegralDelayMS) {
    total = total + analogRead(A0);
    reads++;
    delayMicroseconds(100);
  }

  total = total / reads;

  Serial.print("ADC: ");
  Serial.print(total, 0);
  Serial.print("\t ");
  Serial.print("volts: ");
  Serial.print(int(total * 5.0 / 1024.0));
  Serial.print("\treads: ");
  Serial.println(reads);
}

