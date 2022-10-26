#pragma once
using std::ostream;
using std::endl;
using std::cout;

class Simon{
  public:
    Simon();
    void newPattern();
    string get();
    friend ostream &operator <<(ostream&, const TicTacToe &);
    string pattern;
  private:
    char colors[4] = {'g', 'r', 'y', 'b'};
    int round;
};

Simon::Simon(){
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
    case 0: pattern += "g";
    case 1: pattern += "r";
    case 2: pattern += "y";
    case 3: pattern += "b";
  }
  round++;
}

string Simon::get(){
  return pattern;
}

ostream &operator <<(ostream & out, const Simon &game){
  out << game.get() << endl;
  return out;
}
