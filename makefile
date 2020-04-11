final: UtPodDriver.o UtPod.o Song.o
	g++ -o test  go_fish.o player.o deck.o card.o
go_fish.o: go_fish.cpp player.h deck.h card.h
	g++ -c go_fish.cpp
player.o: player.cpp player.h deck.h card.h
	g++ -c player.cpp
deck.o: deck.cpp deck.h card.h
	g++ -c deck.cpp
card.o: card.cpp card.h
	g++ -c card.cpp
