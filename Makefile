default: upload
build: clean
	arduino-cli compile -b arduino:avr:uno . -o build/HyTeSense
upload: build
	arduino-cli upload -b arduino:avr:uno -i build/HyTeSense -p $(PORT)
clean:
	rm -rf build/*
