#pragma once
#include <bits/stdc++.h>
#include <ctime>
#include <iostream>
using std::string;
using std::sort;
using std::cout;
using std::endl;

class CharacterCreator{
  public:
    int genStat();
    void setStats();
  private:
    string classOptions[4];
    string raceOptions[4];
    string playClass;
    string race;
    int stats[6]; //[stren, dex, con, int, wis, char];
    int mods[6]; //[stren, dex, con, int, wis, char];
};

int CharacterCreator::genStat(){
  srand(time(NULL));
  int stat = 0;
  int rolls[4];
  for(int i = 0; i < 4; i++){
    rolls[i] = rand() % 6 + 1;
  }
  sort(rolls, rolls+4);
  rolls[0] = 0;
  for(int i : rolls){
    stat += i;
  }
  return stat;
}

void CharacterCreator::setStats(){
  int temp[6] = {genStat(), genStat(), genStat(), genStat(), genStat(), genStat()};
  for(int i : temp){
    cout << i << "   ";
  }
  cout << "\nSten  Dex  Con  Int  Wis  Char" << endl;
  cout << "Type Nuber of what you want to switch" << endl;
}
