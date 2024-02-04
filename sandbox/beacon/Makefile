optkit_beacon: optkit_beacon.cc
	g++ optkit_beacon.cc -o optkit_beacon -I/usr/local/include/optkit/ -I/usr/local/include/spdlog -loptkit -lGLEW -lglfw3 -lGL -lspdlog -lpfm -ldl -lpthread

run: optkit_beacon
	./optkit_beacon 10

clean:
	rm ./optkit_beacon