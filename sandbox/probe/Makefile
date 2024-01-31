

all:
	g++ probe.cc -o probe.out -I/usr/local/include/optkit/ -I/usr/local/include/spdlog -loptkit -lGLEW -lglfw3 -lGL -lspdlog -lpfm

run: all
	./probe.out

clean:
	rm ./probe.out