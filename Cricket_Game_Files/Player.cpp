#include"Player.h"
#include<string>
#include<sstream>

using namespace T20Game;

Player::Player(std::string line){
  std::string comma = ",";

  std::string token = line.substr(0,line.find(comma));
  this->playerName = token;
  line.erase(0, token.length()+1);

  token = line.substr(0,line.find(comma));
  this->playerType = token;
  line.erase(0, token.length()+1);

  token = line.substr(0,line.find(comma));
  this->teamName = token;
  line.erase(0, token.length()+1);

  token = line.substr(0,line.find(comma));
  std::istringstream buffer(token);
  buffer>>this->numRunsScored;
  line.erase(0, token.length()+1);

  token = line.substr(0,line.find(comma));
  std::istringstream buffer1(token);
  buffer1>>this->numWickets;
  line.erase(0, token.length()+1);

  token = line.substr(0,line.find(comma));
  std::istringstream buffer2(token);
  buffer2>>this->numOversBowled;
  line.erase(0, token.length()+1);

  this->numRunsConceded = 0;

}

std::string Player::getPlayerName()const{
  return playerName;
}

std::string Player::getPlayerType()const{
  return playerType;
}

std::string Player::getTeamName()const{
  return teamName;
}

int Player::getnumRunsScored(){
  return numRunsScored;
}

int Player::getnumWickets(){
  return numWickets;
}

int Player::getnumRunsConceded(){
  return numRunsConceded;
}

int Player::getnumOversBowled(){
  return numOversBowled;
}


void Player::setNumRunsScores(int runs){
  numRunsScored = runs;
  return;
}

void Player::setNumRunsConceded(int runsConceded){
  numRunsConceded = runsConceded;
  return;
}

void Player::setNumWickets(int num){
  numWickets = num;
  return;
}

void Player::setNumOversBowled(int numOvers){
  numOversBowled = numOvers;
  return;
}
