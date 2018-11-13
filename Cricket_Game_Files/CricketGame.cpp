#include"CricketGame.h"
#include"Player.h"
#include"ScoreBoard.h"

#include<fstream>
#include<string>
#include<iostream>
#include<vector>
#include<iomanip>
#include<cstdlib>
#include<ctime>

using namespace T20Game;


GameState::GameState(std::string file_name){
  int numOvers_in_game;
  readPlayerStats(file_name);
  assignPlayersinTeams();


  std::cout<<"Welcome to IPL Cricket Tournament 2018"<<std::endl;
  std::cout<<"How many overs would you like to play for?"<<std::endl;
  std::cin>>numOvers_in_game;

  int team1;
  int team2;
  std::cout<<"Choose your team from the following"<<std::endl;
  std::cout<<"0. CSK "<<std::endl;
  std::cout<<"1. MI "<<std::endl;
  std::cout<<"2. RCB "<<std::endl;
  std::cout<<"3. SRH "<<std::endl;
  std::cout<<"4. KKR "<<std::endl;
  std::cout<<"5. RR "<<std::endl;
  std::cout<<"6. KXIP "<<std::endl;
  std::cout<<"7. DD "<<std::endl;
  std::cin>> team1;

  std::cout<<"Choose which team would you like to play against "<<std::endl;
  std::cout<<"0. CSK "<<std::endl;
  std::cout<<"1. MI "<<std::endl;
  std::cout<<"2. RCB "<<std::endl;
  std::cout<<"3. SRH "<<std::endl;
  std::cout<<"4. KKR "<<std::endl;
  std::cout<<"5. RR "<<std::endl;
  std::cout<<"6. KXIP "<<std::endl;
  std::cout<<"7. DD "<<std::endl;
  std::cin>> team2;

  std::cout<<"Match Fixture: "<< playersOfTeams[team1][5].getTeamName()<<" VS "<< playersOfTeams[team2][5].getTeamName()<<std::endl;
  std::cout<<"Lets look at Squads of both the teams. "<<std::endl;
  printingSquads(team1,team2);
  std::cout<<std::endl;
  int tossResult;
  tossResult =  tossCalculate();
  if(tossResult ==1){
    int decision;
    std::cout<<"You have won the toss. What would you like to choose. "<<std::endl;
    std::cout<<"1. Bat"<<std::endl;
    std::cout<<"2. Bowl"<<std::endl;
    std::cin>>decision;
    if(decision == 1){
      std::cout<<playersOfTeams[team1][5].getTeamName()<<" has won the toss and has chosen to Bat first."<<std::endl;
      gamePlay(team1, team2, numOvers_in_game);//user batting first.
    }
    else{
      std::cout<<playersOfTeams[team1][5].getTeamName()<<" has won the toss and has chosen to Bowl first."<<std::endl;
      //gamePlay();//user bowling first.
    }
  }
  else{
    std::cout<<"Team "<<playersOfTeams[team2][5].getTeamName()<<" has won the toss and chosen to Bat first."<<std::endl;
    //  gamePlay();//User bowling first.
  }

}

void GameState::readPlayerStats(std::string file_name){
std::string playerInfo;
std::ifstream inFS(file_name);
  while(!inFS.eof()){
      playerInfo ="";
      getline(inFS,playerInfo);
      Player newPlayer(playerInfo);
      listPlayers.push_back(newPlayer);

  }
  listPlayers.pop_back();
return;
}

void GameState::assignPlayersinTeams(){
int k = 0;
for(int i = 0;i<8;++i){
  playersOfTeams.push_back(std::vector<Player>());
  for(int j = k;j<listPlayers.size();++j){
    playersOfTeams[i].push_back(listPlayers.at(j));
    if(playersOfTeams[i].size()==11){
      k = j+1;
      break;
    }
    else{
      continue;
    }
  }
}
  return;
}

void GameState::printingSquads(const int team1,const int team2)const{

   int maxSize = findMaxLength_ofPlayer(team1);

  for(int i = 0; i < 11;++i){
    int a = (maxSize-(playersOfTeams[team1][i].getPlayerName().length()));
    std::cout<<playersOfTeams[team1][i].getPlayerName()<<std::string(a+15,' ')<<playersOfTeams[team2][i].getPlayerName()<<std::endl;

  }
return;

}


int GameState::findMaxLength_ofPlayer(const int team1)const{

int max = (playersOfTeams[team1][0].getPlayerName().length());
  for (int i = 1; i <11;++i){
    if((playersOfTeams[team1][i].getPlayerName().length())>max){
      max = (playersOfTeams[team1][i].getPlayerName().length());
    }
    else{
      continue;
    }
  }
  return max;
}


int GameState::tossCalculate()const{

  int tossValue = 0;
  std::cout<<"It's TOSS time. "<<std::endl;
  std::cout<<"Choose :"<<std::endl;
  std::cout<<"1. Heads"<<std::endl;
  std::cout<<"2. Tails"<<std::endl;
  std::cin>>tossValue;

int tossOutcome = 0;

srand(time(NULL));
int k;
//k = rand()%2+1;
k=1;
  if(k == 1){
    tossOutcome = 1;
  }
  else{
  tossOutcome = 2;
  }

return tossOutcome;
}

std::vector<Player> GameState::findBowlers(const int team2){

  int count=0;
  for(int i = 0; i<playersOfTeams[team2].size();++i){

    if(playersOfTeams[team2][i].getPlayerType()== "Bowler"|| playersOfTeams[team2][i].getPlayerType()== "All-Rounder"){
      count++;
    }
  }
std::vector<Player>bowlersList;

  for(int i = 0; i<playersOfTeams[team2].size();++i){
    if(playersOfTeams[team2][i].getPlayerType()== "Bowler"|| playersOfTeams[team2][i].getPlayerType()== "All-Rounder"){
      bowlersList.push_back(playersOfTeams[team2][i]);
    }
  }

  return bowlersList;
}

std::vector<Player> GameState::getUserTeamPlayers(const int team1){

  std::vector<Player> myPlayers;
  for(int i = 0;i<playersOfTeams[team1].size();++i){
    myPlayers.push_back(playersOfTeams[team1][i]);
  }
return myPlayers;
}

void GameState::gamePlay(int team1, int team2, int numOvers_in_game){ // user batting first.

std::vector<Player> listOfBowlers; // list of bowlers in team2(opponent team)[AI]
std::vector<Player> userTeam;     // users Team (team1)

listOfBowlers = findBowlers(team2);
userTeam = getUserTeamPlayers(team1);

 ScoreBoard scoreCard = ScoreBoard(listOfBowlers.at(0),userTeam.at(0),userTeam.at(1));
 scoreCard.printScoreBoard();


// std::cout<<listPlayers.at(i)<<"is bowling the over."<<std::endl;
// std::cout<<


//   //example: 5 overs game per side
//   // step 1: bowler chosen - bowls
//   A bowler is chosen from the AI opponent team.
//   Two of users top two batsman of the battting line up are batting.
//   BigscoreBoard is printed.
//   (which includes 1> total score of team batting, 2>number of wickets fallen 3>currently batting batsman & their respective runs scored,
//   4> name of the bowler who is currently bowling that over and his bowling figures.)
//
//   MiniScoreBoardPrinted-->after every ball : Total Score of the team , numWicketsFallen, batsmanOnStrike and his score, non-striker and his score,
//   bowler currently bowling.
//
//   AI team bowler bowls. (based on whoever is chosen.)
//   bowls a legitimate delivery or an illegitimate delivery(no ball/ wideBall);
//   if(it is a legitimate delivery){
//     Batsman gets a choice to play shots:
//     (a)Drive Shot
//     if(Drive Shot){
//       batsman gets 1/2/4 runs / runOut (O runs)  [1 in 6]
//     }
//     (b)Loft Shot{
//       batsman gets 4/6/ caughtOut(0 runs)        [1 in 3]
//     }
//     (c)Defensive Shot                             [1 in 2]
//       batsman gets 0/1 run
//   }
//   Shot is chosen by the user based on the above options:
//
// if(drive shot )
//   playerXYZ plays (a/b/c/d/e/f){printed}[drive] shot to get 1/2/3/4 runs or /gets Run out.(0 runs)/ bowled(0 runs).
//
// else if (loft shot)
//   player plays (a/b/c/d/e/f){printed}[loft]shot to get 4/6/ caught out(o runs).
//
// else if(Defensive shot)
//   either dot ball (0 runs)/ 1 run taken
//
// --> for all of these scenarios :
// Changes taking place in :
// Batsman's (current batsman) numRuns keeps on changing  [individual player Changes]
// Bowler's figures keeps on changing. [Bowler's figures changing ]
// There is a change in ScoreBoard.
// [Change in the total score board.- numWickets].
//
// Keeps on Going on for the numBer of overs.
// After over is done.
// new bowler automatically chosen and starts to bowl.
// keeps on going for the total numOvers.
//
//


  return;
}
