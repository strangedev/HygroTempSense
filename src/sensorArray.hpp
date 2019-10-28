#ifndef HYTE_SENSORARRAY_HPP
#define HYTE_SENSORARRAY_HPP

#include "sensor.hpp"

class SensorArray {
public:
	void sample() {
		for (int i = 0; i < _sensorCnt; ++i)
			_sensors[i]->sample();
	}
	void transmit() {
		Serial.print("[");
		char sOut[256];
		for (int i = 0; i < _sensorCnt; ++i)
		{
			Sensor* sensor = _sensors[i];
			sensor->read(sOut);
			Serial.print(sOut);
			if(i == _sensorCnt - 1) continue;
			Serial.print(",");
		}
		Serial.println("]");
	}
	SensorArray(Sensor** sensors, byte sensorCnt) {
		_sensorCnt = sensorCnt;
		_sensors = sensors;
	}
protected:
	byte _sensorCnt;
	Sensor** _sensors;
};

#endif