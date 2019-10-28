import serial
import argparse
import datetime
import json

parser = argparse.ArgumentParser(description='Monitor serial output of Arduino')
parser.add_argument('device', help='Path to serial device')
args = parser.parse_args()
with serial.Serial(args.device, 9600, timeout=1) as tty:
	while True:
		try:
			data = tty.readline()
			if not data: continue
			line = data.decode("utf-8")
			parsed = json.loads(line);

			print(f"\nRx @ {datetime.datetime.now()}")
			headers = []
			fmt = ""
			for sensor in parsed:
				for key in sensor:
					if key not in headers:
						headers.append(key)
						fmt += "{:<10} "
			print(fmt.format(*headers))
			for sensor in parsed:
				values = []
				for h in headers:
					if h in sensor:
						values.append(sensor[h])
					else:
						values.append("-")
				print(fmt.format(*values))
			#print(f"[{datetime.datetime.now()}] {json.dumps(parsed, indent=4, sort_keys=True)}")
		except KeyboardInterrupt:
			print("Exit")
			break