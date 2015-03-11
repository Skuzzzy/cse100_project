all:
	g++ -Wall -fexceptions -g -I include -c ./src/human.cpp -o obj/human.o
	g++ -Wall -fexceptions -g -I include -c ./src/player.cpp -o obj/player.o
	g++ -Wall -fexceptions -g -I include -c ./src/hand.cpp -o obj/hand.o
	g++ -Wall -fexceptions -g -I include -c ./src/card.cpp -o obj/card.o
	g++ -Wall -fexceptions -g -I include -c ./src/main.cpp -o obj/main.o
	g++ -o blackjackGame obj/*
clean:
	rm ./obj/*
	rm blackjackGame
run:
	make all
	clear
	./blackjackGame