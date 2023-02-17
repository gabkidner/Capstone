#include <iostream>
#include <conio.h>
#include "Twenty48.h"
using namespace std;

main(){
  Twenty48 game;
  int user = 0, blah;
  system("cls");
  while(true){
    blah = game.realDirection(user);
    cout << game << endl;
    game.movement(blah);
    user = getch();
    system("cls");
  }
}
