#ifndef HYTE_LM35_HPP
#define HYTE_LM35_HPP

#include "../sensor.hpp"

class Lm35: public Sensor {
public:
	Lm35(byte pin): Sensor(pin) {
		_temperature = -1.0;
	}
	getTemperature() {
		return _temperature;
	}
	void sample() {
		_temperature = (analogRead(_pin) * 500.0) / 1024.0;
		_sampleTime = millis();
	}
	void read(char* buffer) {
		char tempBuf[8];
		dtostrf(_temperature, 5, 2, tempBuf);
		sprintf(
			buffer,
			"{\"type\": \"LM35\", \"pin\":%i, \"temp\":%s, \"t\":%lu}",
			_pin, tempBuf, _sampleTime
		);
	}
protected:
	float _temperature;
};

#endif