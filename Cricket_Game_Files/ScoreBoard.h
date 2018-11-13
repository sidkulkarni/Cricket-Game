#ifndef SCOREBOARD_H
#define SCOREBOARD_H

#include<string>
#include"Player.h"

namespace T20Game{
  class ScoreBoard{

  public:
    ScoreBoard(Player openingBowler, Player openingBatsmanOnStrike, Player openingBatsmanOnNonStrike);
    void printScoreBoard();
    //score board includes Total score of currentTeam, numWickets fallen,the two currentbatsman playing(NOT outs){their scores},
    // name of the bowlerCurrently bowling.{His bowling figures.}

    void printBattingTeamStatistics();//print the entire squad and the runs scored by each player of the team.
    void printBowlingTeamStatistics(); // print out the bowlers used during the game and their bowling figures.

    int getTotalScore();
    int getnumWicketsFallen();
    std::string getCurrentBowler();

  private:
    std::string battingTeamName;
    std::string bowlingTeamName;
    int total_score;
    int numWicketsFallen;
    std::string batsmanOnStrike;
    std::string batsmanNonStrike;
    std::string currentBowler;

    // double currentRunRate;
    // double requiredRunRate;


};
}
#endif
