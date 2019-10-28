## Building

### Deps

Needs some arduino libs to work:

- "Adafruit Unified Sensor"
- "DHT sensor library"

`make PORT=/dev/ttyXYZ123` to build & upload

`make PORT=/dev/ttyACM0 && python serial/prettyMonitor.py /dev/ttyACM0 ` to test