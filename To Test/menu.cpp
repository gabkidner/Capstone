//WORK IN PROGRESS
#include "Connect4.h"
#include <iostream>
using namespace std;

void pressEnter(){
  int user = 0;
  cout << "Press Enter...";
  while(user != 10){
    user = cin.get();
  }
  system("clear");
  cout << endl;
}

void connect(){
  int choice;
  Connect4 c4;
  cout << "TEST" << endl;
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

main(){
  system("clear");
  int user = -2;
  cout << "\nWelcome to my senior capstone project!\n";
  pressEnter();
  cout << "My name is Gabe Kidner and I am a senior at NUAMES\nMy Capstone was a collection of Coding projects that I Have Created\n";
  pressEnter();
  while(user != 0){
    cout << "Select an option...\n";
    cout << "1.Connect 4\n 2.Die\n3.Guess Your Number\n4.Guess My Number\n0.Exit\n";
    cin >> user;
    switch(user){
      case 1: connect(); break;
      case 0: break;
    }
  }
}
