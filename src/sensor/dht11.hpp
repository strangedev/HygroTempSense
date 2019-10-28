#ifndef HYTE_DHT11_HPP
#define HYTE_DHT11_HPP

#include <DHT.h>
#include <string.h>
#include <math.h>
#include "../sensor.hpp"

class Dht11: public Sensor {
public:
	Dht11(byte pin): Sensor(pin), _dht(pin, DHT11) {
		_temperature = -1.0;
		_humidity = -1.0;
		_dht.begin();
	}
	getTemperature() {
		return _temperature;
	}
	void sample() {
		_temperature = _dht.readTemperature();
		_humidity = _dht.readHumidity();
		_sampleTime = millis();
	}
	void read(char* buffer) {
		sprintf(buffer, "bla");
		char tempBuf[10], humiBuf[10];
		if (isnan(_temperature)) {
			strcpy(tempBuf, "null");
		} else dtostrf(_temperature, 5, 2, tempBuf);
		if (isnan(_humidity)) {
			strcpy(humiBuf, "null");
		} else dtostrf(_humidity, 5, 2, humiBuf);
		sprintf(
			buffer, 
			"{\"type\": \"DHT11\", \"pin\":%i, \"temp\":%s, \"humi\":%s, \"t\":%lu}",
			_pin, tempBuf, humiBuf, _sampleTime
		);
	}
protected:
	float _temperature;
	float _humidity;
	DHT _dht;
};

#endif