#include <iostream>
#include "Calculator.h"
#include "ChooseAdventure.h"
#include "Die.h"
using namespace std;

main(){
  int sides, rolls;
  cout << "How many sides should this die have?\n";
  cin >> sides;
  cout << "How many times should I roll this " << sides << " sided die?" << endl;
  cin >> rolls;
  Die die(sides, rolls);
  die.roll();
  system("cls");
  cout << die << endl;
}
