#ifndef CHOOSEADVENTURE_H
#define CHOOSEADVENTURE_H
#include <fstream>
#include <sstream>
#include <conio.h>
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
    int printStory();
    void reset();
    void advancePhase(char);
    bool stop();
    void pressEnter();
  private:
    string storyOutput = "";
    string phase = "s";
    char result;
    bool breakLoop = false;
};

int ChooseAdventure::printStory(){
  string temp, phas;
  ifstream fout("story.txt", ios::in);
  while(phas != phase){
    getline(fout, phas, ',');
    getline(fout, storyOutput, '\n');
    if(phas == "exit"){
      return 0;
    }
  }
  for(char i : storyOutput){
    if(i == '*'){
      result = i;
    }
    else if(i == '@'){
      pressEnter();
    }
    else if(i == '|'){
      reset();
      pressEnter();
      return 0;
    }
    else if(i == '%'){
      cout << "\nType 10 and press Enter\n";
      breakLoop = true;
    }
    else if(i != '\\'){
      cout << i;
    }
    else{
      cout << endl;
    }
  }
  cout << endl;
  return 1;
}

void ChooseAdventure::reset(){
  phase = "s";
  ofstream fin;
  fin.open("inventory.txt");
  fin << "";
  fin.close();
}

void ChooseAdventure::advancePhase(char user){
  if(breakLoop){
    return;
  }
  switch(user){
    case '1': phase += ".a"; break;
    case '2': phase += ".b"; break;
    case '3': phase += ".c"; break;
    case '0': break;
  }
}

bool ChooseAdventure::stop(){
  if(breakLoop){
    return true;
  }
  return false;
}

void ChooseAdventure::pressEnter(){
  cout << "\nPress Enter to Continue..." << endl;
  int user = 0; 
  while(user != 13){
    user = _getch();
  }
}
#endif
