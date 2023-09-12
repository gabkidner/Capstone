#include "Die.h"
#include <iostream>
using namespace std;

void die();

main(){
  string temp;
  int input;
  cout << "Welcome to my Capstone Project\n[Blank] games in one\n" << endl;
  do{
    system("cls");
    cout << "Select Game and Press Enter\n0 - Exit\n1 - Dice" << endl << endl;
    cin >> input;
    switch(input){
      case 0: break;
      case 1: die(); break;
    }
  }while(input != 0);
  system("cls");
  cout << "\nMade by Gabe Kidner.\n\nPress enter to close\n";
  cin >> input;
}

void die(){
  int sides, rolls;
  cout << "How many sides should this die/coin have?\n";
  cin >> sides;
  cout << "\nHow many times should I roll this " << sides << " sided die?" << endl;
  cin >> rolls;
  Die die(sides, rolls);
  die.roll();
  system("cls");
  cout << die << endl;
}
