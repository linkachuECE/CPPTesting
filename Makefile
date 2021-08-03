all:
	g++ -std=c++2a -fconcepts -g *.cpp -o ./bin/exec

clean:
	rm bin/*