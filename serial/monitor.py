import serial
import argparse
import datetime

parser = argparse.ArgumentParser(description='Monitor serial output of Arduino')
parser.add_argument('device', help='Path to serial device')
args = parser.parse_args()
with serial.Serial(args.device, 9600, timeout=1) as tty:
	while True:
		try:
			data = tty.readline()
			if not data: continue
			line = data.decode("utf-8")
			print(f"[{datetime.datetime.now()}] {line}", end="")
		except KeyboardInterrupt:
			print("Exit")
			break