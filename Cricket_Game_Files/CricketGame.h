#ifndef CRICKETGAME_H
#define CRICKETGAME_H

#include<vector>
#include"Player.h"
#include"ScoreBoard.h"

namespace T20Game{
  class GameState{
    public:
      GameState(std::string file_name);
      void readPlayerStats(std::string file_name);
      void assignPlayersinTeams();
      void printingSquads(const int team1,const int team2)const;
      int findMaxLength_ofPlayer(const int team1)const;
      int tossCalculate()const;
      std::vector<Player> findBowlers(const int team2);
      std::vector<Player> getUserTeamPlayers(const int team1);

      void gamePlay(int team1, int team2, int numOvers_in_game);

    private:
      std::vector<Player>listPlayers;
      std::vector<std::vector<Player>>playersOfTeams;

      //int a = 0;

};

}

#endif
