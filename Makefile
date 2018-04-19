antsim: ant.cpp board.cpp main.cpp
	g++ -std=c++11 ant.cpp board.cpp main.cpp -o antSim

clean: 
	rm antSim

