/******************************************************/
//       THIS IS A GENERATED FILE - DO NOT EDIT       //
/******************************************************/

#include "Particle.h"
#line 1 "c:/Users/hydrobenzene/Downloads/SummerClass/SpiSpi/SPI/src/SPI.ino"
void setup();
void loop();
#line 1 "c:/Users/hydrobenzene/Downloads/SummerClass/SpiSpi/SPI/src/SPI.ino"
SYSTEM_THREAD(ENABLED);
#include "blynk.h"
#include "LIS3DH.h"

LIS3DHSPI acrmtr(SPI, D3, WKP);
void setup() {
  pinMode(D3, INPUT);

  Blynk.begin("{TOKEN}", IPAddress(000, 000, 000, 000), 0000);
  Blynk.run();

  Serial.begin(9600);

  LIS3DHConfig cfg;
	cfg.setAccelMode(LIS3DH::RATE_100_HZ);
  Serial.println(acrmtr.setup(cfg))
}

// loop() runs over and over again, as quickly as it can execute.
void loop() {
  LIS3DHSample sample;
  acrmtr.getSample(instant);
  Serial.println(sample.x + ", " + sample.y + ", " + sample.z)
  Blynk.virtualWrite(V0, sample.x);
  Blynk.virtualWrite(V1, sample.y);
  Blynk.virtualWrite(V2, sample.z);
}