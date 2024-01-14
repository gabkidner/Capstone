#include "Completed/Die.h"
#include "Completed/TicTacToe.h"
#include <iostream>
using namespace std;

void die();
void tictac();
void complete();
void incomplete();

main(){
  int input;
  string temp;
  cout << "Welcome to my Capstone Project\n[Blank] games in one\nThere are games I have completed and games I haven't" << endl;
  do{
    cout << "\nWould you like to do complete or incomplete games?\n0 - Exit\n1 - Complete\n2 - Incomplete" << endl << endl;
    cin >> input;
    switch(input){
      case 0: break;
      case 1: complete(); break;
      case 2: incomplete(); break;
    }
  }while(input != 0);
  system("cls");
}

void complete(){
  int input;
  string temp;
  system("cls");
  do{
    cout << "\nSelect Game and Press Enter\n0 - Exit\n1 - Dice\n2 - Tic Tac Toe" << endl << endl;
    cin >> input;
    switch(input){
      case 0: break;
      case 1: die(); break;
      case 2: tictac(); break;
    }
  }while(input != 0);
  system("cls");
}

void incomplete(){
  cout << "Goodbye" << endl;
}

void die(){
  int user = 99;
  do{
    int sides, rolls;
    cout << "How many sides should this die/coin have?\n";
    cin >> sides;
    cout << "\nHow many times should I roll this " << sides << " sided die?" << endl;
    cin >> rolls;
    Die die(sides, rolls);
    die.roll();
    system("cls");
    cout << die << "\nSelect an option and Press Enter\n0 - Main Menu\n1 - Roll Again" << endl;
    cin >> user;
  }while(user != 0);
  system("cls");
}

void tictac(){
  int choiceInt;
  char choiceChar;
  TicTacToe tic;
  while(tic.won() == 0){
    tic.switchPlayer();
    system("cls");
    cout << tic << "\n" << tic.get() << "'s turn\n";
    cin >> choiceInt;
    while(choiceInt > 9){
      cout << "Please enter a valid number\n";
      cin >> choiceInt;
    }
    choiceChar = choiceInt + 48;
    tic.place(choiceChar);
  }
  cout << tic << endl;
  if(tic.won() == 1){
    cout << tic.get() << "'s win";
  }
  else{
    cout << "Neither of you won, you are equals" << endl;
  }
}
