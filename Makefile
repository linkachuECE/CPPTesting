all:
	g++ -std=c++2a -fconcepts -g main.cpp -o ./bin/main

clean:
	rm bin/*

blackjack:
	g++ -std=c++2a -fconcepts -g blackjack.cpp -o ./bin/blackjack
