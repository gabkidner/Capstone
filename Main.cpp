#include <iostream>
#include <conio.h>
#include "Memory.h"
using namespace std;


main(){
  Memory game;
  cout << game;
  cout << "Welcome to x games in one.\nPress enter to continue\n";
  int user;
  do{
    user = getch();
  }while(user != 13);
  cout << "Selet Your Game and Press Enter\n\nTo Exit Type \"-1\"\n\n1 = blank" << endl;
  cin >> user;
  cout << "porque" << endl;
  game.flip(4);
  cout << "Halp " << endl;
  game.flip(5);
}
