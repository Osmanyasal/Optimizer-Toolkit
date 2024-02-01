probe.out: probe.cc
	g++ probe.cc -o probe.out -I/usr/local/include/optkit/ -I/usr/local/include/spdlog -loptkit -lGLEW -lglfw3 -lGL -lspdlog -lpfm -ldl -lpthread

run: probe.out
	./probe.out

clean:
	rm -f probe.out