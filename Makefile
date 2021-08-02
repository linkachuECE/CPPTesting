all:
	g++ -std=c++17 -g *.cpp -o ./bin/main

clean:
	rm bin/*