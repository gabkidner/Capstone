#include "GuessNumber.h"
#include <iostream>
using namespace std;

main(){   //Print, solve and show the maze
  GuessNumber game;
  int user, result;
  cout << "Welcome to Guess My Number where your pitiful human mind\nmust guess what number I am thinking of in 15 tries or less.\n\nType you're first guess" << endl;
  do{
    cout << game.getNumber();
    cin >> user;
    result = game.result(user);
    game.add(user);
    if(result == 3){
      cout << "Lower" << endl;
    }
    else if(result == 2){
      cout << "Higher" << endl;
    }
  }while(result != 0 && result != 1);
  if(result == 1 && game.getRounds() != 0){
    cout << "It took you " << game.getRounds() << " to guess my number, good job.";
  }
  if(result == 1 && game.getRounds() == 0){
    cout << "You got it first try!!!!!!!!!! IMPOSIBLE!!!!!\n";
    cin >> user;
    system("clear");
  }
}
