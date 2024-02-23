optkit_vis: optkit_vis.cc
	g++ optkit_vis_bar.cc -o optkit_vis_bar -I/usr/local/include/optkit/ -I/usr/local/include/spdlog -loptkit -lGLEW -lglfw3 -lGL -lspdlog -lpfm -ldl -lpthread

run: optkit_vis
	./optkit_vis_bar ./

clean:
	rm ./optkit_vis_bar