#ifndef PLAYER_H
#define PLAYER_H

#include<string>

namespace T20Game{
class Player{

public:

  Player(std::string line); //constructor


  std::string getPlayerName()const;
  std::string getPlayerType()const;
  std::string getTeamName()const;

  void setNumRunsScores(int runs);
  void setNumRunsConceded(int runsConceded);
  void setNumWickets(int numWickets);
  void setNumOversBowled(int numOvers);


  int getnumRunsScored();
  int getnumRunsConceded();
  int getnumWickets();
  int getnumOversBowled();


  void getPlayerStats();

private:
  std::string playerName;
  std::string playerType;
  std::string teamName;
  int numRunsScored;
  int numRunsConceded;
  int numWickets;
  int numOversBowled;
};

}
#endif
