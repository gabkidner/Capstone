#pragma once
#include <ostream>
using std::string;

class Nim{
  public:
    Nim();
    void switchPlayer();
    bool isValid(int);
    void take(int);
    bool win();
    friend ostream &operator <<(ostream&, const TicTacToe &);
    int stones;
  private:
    string player1;
    string player2;
    string curPlayer;
};

Nim::Nim(){
  player1 = "Player 1";
  player2 = "Player 2";
  stones = rand()%30 + 10;
  curPlayer = "Player 1";
}

void Nim::switchPlayer(){
  if(curPlayer == player1){
    curPlayer.erase();
    curPlayer = player2;
  }
  else{
    curPlayer.erase();
    curPlayer = player1;
  }
}

bool Nim::isValid(int amount){
  if(amount < 1||amount > 3||amount > stones){
  return false;
  }
  else{
    return true;
  }
}

void Nim::take(int choice){
  stones -= choice;
}

bool Nim::win(){
  if(stones == 0){
    return true;
  }
  return false;
}

ostream &operator <<(ostream & out, const Nim &game){
  int bob = game.stones;
  for(int i = 0; i < bob; i++){
    out << "@";
  }
  return out;
}
