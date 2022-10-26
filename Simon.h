#pragma once
#include <ostream>
using std::cout;
using std::endl;

class Simon{
  public:
    Simon();
    newPattern();
    end();
    friend ostream &operator <<(ostream&, const TicTacToe &);
  private:
    char[4] colors;
    string pattern;
    int round;
}

Simon::Simon(){
  colors[] = {'g', 'r', 'y', 'b'};
  int blah = stones = rand() % 4;
  switch(blah){
    case 0: pattern = "g";
    case 1: pattern = "r";
    case 2: pattern = "y";
    case 3: pattern = "b";
  }
}

Simon::newPattern(){
  round++;
}


ostream &operator <<(ostream & out, const Simon &game){
  out << game.pattern << endl;
  return out;
}
