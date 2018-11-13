cricket.out: main.o  CricketGame.o ScoreBoard.o Player.o
		g++ -g -std=c++14 -Wall -o cricket.out main.o CricketGame.o ScoreBoard.o Player.o

main.o: main.cpp cricketGame.h ScoreBoard.h Player.h
		g++ -g -std=c++14 -Wall -c -o main.o main.cpp

CricketGame.o: CricketGame.cpp CricketGame.h
		g++ -g -std=c++14 -Wall -c -o CricketGame.o CricketGame.cpp

ScoreBoard.o: ScoreBoard.cpp ScoreBoard.h
		g++ -g -std=c++14 -Wall -c -o ScoreBoard.o ScoreBoard.cpp

Player.o: Player.cpp Player.h
		g++ -g -std=c++14 -Wall -c -o Player.o Player.cpp

clean:
		rm -f *.o *.out
