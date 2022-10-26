#pragma once
#include <iomanip>
using std::ostream;
using std::endl;
using std::cout;

class Simon{
  public:
    Simon();
    void newPattern();
    string get();
    bool done(string);
    friend ostream &operator <<(ostream&, const TicTacToe &);
    string pattern;
  private:
    char colors[4] = {'g', 'r', 'y', 'b'};
    int round;
};

Simon::Simon(){
  srand(time(NULL));
  int blah = rand() % 4;
  switch(blah){
    case 0: pattern = "g";
    case 1: pattern = "r";
    case 2: pattern = "y";
    case 3: pattern = "b";
  }
}

void Simon::newPattern(){
  int blah = rand() % 4;
  switch(blah){
    case 0: pattern += "g"; break;
    case 1: pattern += "r"; break;
    case 2: pattern += "y"; break;
    case 3: pattern += 'b'; break;
  }
  round++;
}

string Simon::get(){
  return pattern;
}

bool Simon::done(string player){
  if(pattern != player){
    return true;
  }
  return false;
}

ostream &operator <<(ostream & out, const Simon &game){
  out << game.pattern << endl;
  return out;
}
