#ifndef HYTE_SENSOR_HPP
#define HYTE_SENSOR_HPP

typedef unsigned long time_t;

class Sensor {
public:
	virtual void sample() = 0;
	virtual void read(char* buffer) = 0;
	Sensor(byte pin) {
		_pin = pin;
		_sampleTime = 0;
	}
	byte getPin() {
		return _pin;
	}
	time_t getSampleTime() {
		return _sampleTime;
	}
protected:
	byte _pin;
	time_t _sampleTime;
};

#endif