#ifndef CHOOSEADVENTURE_H
#define CHOOSEADVENTURE_H
#include <fstream>
#include <sstream>
#include <iostream>
using std::ofstream;
using std::ifstream;
using std::string;
using std::cout;
using std::endl;
using std::ios;
//* = continue, | = reset, @ = press Enter to continue, % = broke \ = enter

class ChooseAdventure{
  public:
    void printStory();
    void reset();
    void advancePhase(int);
    bool stop();
  private:
    string storyOutput = "";
    string phase = "s";
    char result;
    bool breakLoop = false;
};

void ChooseAdventure::printStory(){
  string temp, phas;
  ifstream fout("story.txt", ios::in);
  while(phas != phase){
    getline(fout, phas, ',');
    getline(fout, storyOutput, '\n');
  }
  for(char i : storyOutput){
    if(i == '*' || i == '@'){
      result = i;
    }
    else if(i == '|'){
      reset();
      cout << "\nType 10 and press Enter\n";
    }
    else if(i == '%'){
      cout << "\nType 10 and press Enter\n";
      breakLoop = true;
      return;
    }
    else if(i != '\\'){
      cout << i;
    }
    else{
      cout << endl;
    }
  }
  cout << endl;
}

void ChooseAdventure::reset(){
  phase = "s";
  ofstream fin;
  fin.open("inventory.txt");
  fin << "";
  fin.close();
}

void ChooseAdventure::advancePhase(int user){
  if(breakLoop){
    return;
  }
  switch(user){
    case 1: phase += ".a"; break;
    case 2: phase += ".b"; break;
    case 3: phase += ".c"; break;
    case 10: break;
  }
  cout << phase << endl;
}

bool ChooseAdventure::stop(){
  if(breakLoop){
    return true;
  }
  return false;
}
#endif
