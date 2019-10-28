#include "src/sensor.hpp"
#include "src/sensorArray.hpp"
#include "src/sensor/lm35.hpp"
#include "src/sensor/dht11.hpp"

Lm35 lm35_0 = Lm35(14);
Lm35 lm35_1 = Lm35(15);
Lm35 lm35_2 = Lm35(16);
Lm35 lm35_3 = Lm35(17);
Lm35 lm35_4 = Lm35(18);
Dht11 dht11_0 = Dht11(2);
Sensor* sensors[] = {&lm35_0, &lm35_1, &lm35_2, &lm35_3, &lm35_4, &dht11_0};
SensorArray ary = SensorArray(sensors, 6);

void setup() {
    pinMode(13, OUTPUT);
    Serial.begin(9600);
    delay(1000);
}

void loop() {
	ary.sample();
	ary.transmit();
	delay(1000);
}
