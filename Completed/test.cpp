#include "Die.h"
#include <iostream>
using namespace std;

void die();

main(){
  string temp;
  int input;
  cout << "Welcome to my Capstone Project\n[Blank] games in one\nMade by Gabe Kidner\n" << endl;
  cout << "Select Game and Press Enter\n0 - Exit\n1 - Dice" << endl << endl;
  cin >> input;
  system("clear");
  switch(input){
    case 0: return 0; break;
    case 1: die(); break;
  }
}

void die(){
  int sides, rolls;
  cout << "How many sides should this die/coin have?\n";
  cin >> sides;
  cout << "\nHow many times should I roll this " << sides << " sided die?" << endl;
  cin >> rolls;
  Die die(sides, rolls);
  die.roll();
  system("clear");
  cout << die << endl;
}
