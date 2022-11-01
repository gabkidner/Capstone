#include <iostream>
#include <conio.h>
#include "Connect4.h"
#include "TicTacToe.h"
#include "Nim.h"
#include "Simon.h"
#include "Twenty48.h"
#include "GuessNumber.h"
using namespace std;

void connect();
void ttt();
void nim();
void sim();
void twenty();
void guess();

main(){//Only for navigating menu
  int choice = 100;
  do{

    cout << "Menu:\n1 = Connect 4\n2 = TicTacToe\n3 = Nim\n4 = Simon Says\n5 = 2048\n";
    cin >> choice;
    switch(choice){
      case 1: connect(); break;
      case 2: ttt(); break;
      case 3: nim(); break;
      case 4: sim(); break;
      case 5: twenty(); break;
    }
  }while(choice != 0);
}

void connect(){//Connect 4 game
  int choice;
  Connect4 c4;
  cin >> choice;
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

void sim(){
  int game = 0;
  string choice;
  Simon s;
  do{
    int loop = 50;
    if(game != 0){
      s.newPattern();
    }
    while(loop != 0){
      system("cls");
      cout << s;
      loop--;
    }
    system("cls");
    cin >> choice;
    game++;
  }while(!s.done(choice));
}

void twenty(){
  Twenty48 game;
  int input, inputt;
  do{
    system("cls");
    cout << game << "\n" << inputt;
    inputt = getch();
    input = game.realInput(inputt);
    game.move(input);
    game.addNums();
  }while(!game.hasWon() && !game.hasLost());
}

void guess(){
  GuessNumber game;
  int user;
  do{

  }while(!correct())
}
