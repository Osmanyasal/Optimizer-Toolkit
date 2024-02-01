

all:
	g++ beacon.cc -o beacon.out -I/usr/local/include/optkit/ -I/usr/local/include/spdlog -loptkit -lGLEW -lglfw3 -lGL -lspdlog -lpfm -ldl -lpthread

run: all
	./beacon.out 10

clean:
	rm ./beacon.out