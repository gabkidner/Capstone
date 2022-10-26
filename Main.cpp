#include <iostream>
#include "Connect4.h"
#include "TicTacToe.h"
#include "Nim.h"
#include "Simon.h"
using namespace std;

void connect(){//Connect 4 game
  int choice;
  Connect4 c4;
  Simon s1;
  cout << s1;
  while(!c4.won()){
    c4.switchPlayer();
    system("cls");
    cout << "\n" << c4 << "\n\n" << c4.getPlayer() << "\'s turn"<< endl;
    cin >> choice;
    while(choice > 7){
      cout << "That is an invalid move try again!" << endl;
      cin >> choice;
      system("cls");
      cout << c4 << "\n" << c4.getPlayer() << "\'s turn"<< endl;
    }
    c4.place(choice);
  }
  system("cls");
  cout << c4;
}

void ttt(){
  char choice;
  TicTacToe tic;
  while(!tic.won()){
    tic.switchPlayer();
    system("cls");
    cout << tic;
    cin >> choice;
    tic.place(choice);
  }
}

void nim(){
  int choice, bad = 2;
  Nim game;
  while(!game.win()){
    do{
      system("cls");
      if(bad = 0){
        cout << "Invalid" << endl;
        bad = 1;
      }
      cout << game;
      cin >> choice;
      if(game.isValid(choice)){
        break;
      }
      else{
        bad = 0;
      }
    }while(!game.isValid(choice));
    game.take(choice);
  }
}

main(){//Only for navigating menu
  int choice;
  cout << "Menu:\n";
  do{
    cin >> choice;
    switch(choice){
      case 1: connect(); break;
      case 2: ttt(); break;
      case 3: nim(); break;
    }
  }while(choice != 0);
}
