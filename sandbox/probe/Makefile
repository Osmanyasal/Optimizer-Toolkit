optkit_probe: probe.cc
	g++ probe.cc -o optkit_probe -I/usr/local/include/optkit/ -I/usr/local/include/spdlog -loptkit -lGLEW -lglfw3 -lGL -lspdlog -lpfm -ldl -lpthread

run: optkit_probe
	./optkit_probe

clean:
	rm -f optkit_probe