#include"ScoreBoard.h"
#include"Player.h"

#include<iostream>
#include<string>
using namespace T20Game;


ScoreBoard::ScoreBoard(Player openingBowler, Player openingBatsmanOnStrike, Player openingBatsmanOnNonStrike):battingTeamName(openingBatsmanOnStrike.getTeamName()),bowlingTeamName(openingBowler.getTeamName()), total_score(0),numWicketsFallen(0),batsmanOnStrike(openingBatsmanOnStrike.getPlayerName()),batsmanNonStrike(openingBatsmanOnNonStrike.getPlayerName()), currentBowler(openingBowler.getPlayerName())
{}

void ScoreBoard::printScoreBoard(){
std::cout<<std::endl;
std::cout<<battingTeamName<<" Total Score :"<<total_score<<std::string(10,' ')<<" NumWickets Fallen :"<<numWicketsFallen<<std::endl;
std::cout<<"Batsmen currently Batting: "<<std::endl;
std::cout<<"Batsman on Strike :"<<batsmanOnStrike<<std::endl;
std::cout<<"Batsman on Non-Strike :"<<batsmanNonStrike<<std::endl;
std::cout<<std::endl;

std::cout<<bowlingTeamName<<std::endl;
std::cout<<"Current Bowler: "<<currentBowler<<std::endl;




return;
}
