#ifndef CHOOSEADVENTURE_H
#define CHOOSEADVENTURE_H
#include <fstream>
#include <sstream>
#include <iostream>
using std::ofstream;
using std::string;

//* = continue, | = reset, @ = press Enter to continue, % = broke cycle;

class ChooseAdventure{
  public:
    ChooseAdventure(string);
    void clearInventory();
    void reset();
  private:
    string name;
    string storyOutput = "";
    string phase = " ";
    bool breakLoop = false;
};

ChooseAdventure::ChooseAdventure(string input){
  name = input;
  ofstream fout;
  fout.open("inventory.txt");
  fout << "Please Work";
  fout.close();
}

void ChooseAdventure::reset(){
  ofstream fout;
  fout.open("inventory.txt");
  fout << "";
  fout.close();
}
#endif
