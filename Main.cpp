#include <iostream>
#include "Connect4.h"
#include "TicTacToe.h"
#include "Nim.h"
using namespace std;

void connect();
void ttt();
void nim();

main(){//Only for navigating menu
  int menu = -1;
  system("cls");
  do{
    cout << "\ninput choice: \n";
    cin >> menu;
    if(menu == 1){
      connect();
    }
    else if(menu == 2){
      ttt();
    }
    else if(menu == 3){
      nim();
    }
  }while(menu != 0);
}

void connect(){//Connect 4 game
  int choice;
  Connect4 c4;
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
  int choice;
  TicTacToe game;
  while(!game.won()){
    cout << "\n" << game.get();
    system("cls");
    cout << game;
    cin >> choice;
    game.place(choice);
    game.switchPlayer();
  }
  system("cls");
  cout << game;
  cout << game.get() << " has won" << endl;
}

void nim(){
  int choice;
  Nim game;
  while(!game.win()){
    do{
      system("cls");
      cout << game;
      cin >> choice;
    }while(!game.isValid(choice));
    game.take(choice);
  }
}
