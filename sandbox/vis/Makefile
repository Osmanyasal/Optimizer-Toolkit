optkit_vis: optkit_vis.cc
	g++ optkit_vis.cc -o optkit_vis -I/usr/local/include/optkit/ -I/usr/local/include/spdlog -loptkit -lGLEW -lglfw3 -lGL -lspdlog -lpfm -ldl -lpthread

run: optkit_vis
	./optkit_vis

clean:
	rm ./optkit_vis