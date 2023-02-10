#include <iostream>
#include <conio.h>
#include "Connect4.h"
#include "TicTacToe.h"
#include "Nim.h"
#include "Simon.h"
#include "GuessNumber.h"
#include "GuessYourNumber.h"
using namespace std;

void connect();
void ttt();
void nim();
void sim();
void guess();
void iGuess();
void master();

main(){//Only for navigating menu
  int choice = 100;
  do{
    cout << "Menu:\n1 = Connect 4\n2 = TicTacToe\n3 = Nim\n4 = Simon Says\n5 = 2048\n6 = Guess My NUmber\n7 = I Guess Your Number\n";
    cin >> choice;
    switch(choice){
      case 1: connect(); break;
      case 2: ttt(); break;
      case 3: nim(); break;
      case 4: sim(); break;
      case 6: guess(); break;
      case 7: iGuess(); break;
      case 8: master(); break;
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

void guess(){
  GuessNumber game;
  int user, result;
  do{
    cin >> user;
    result = game.result(user);
    game.add(user);
    if(result == 3){
      cout << "Lower" << endl;
    }
    else if(result == 2){
      cout << "Higher" << endl;
    }
    cout << "Result" << result << endl;
  }while(result != 0 && result != 1);
}

void iGuess(){
  GuessYourNumber game;
  string user;
  int result;
  do{
    game.guessing();
    cout << game;
    cin >> user;
    game.editGuess(user);
    result = game.complete(user);
    cout << result << endl;
  }while(result == 0);
}

void master(){
  Mastermind game;
  cout << " __  __           _                      _           _ " << endl;
  cout << "|  \\/  | __ _ ___| |_ ___ _ __ _ __ ___ (_)_ __   __| |"<< endl;
  cout << "| |\\/| |/ _` / __| __/ _ \\ '__| '_ ` _ \\| | '_ \\ / _` |"<< endl;
  cout << "| |  | | (_| \\__ \\ ||  __/ |  | | | | | | | | | | (_| |"<< endl;
  cout << "|_|  |_|\\__,_|___/\\__\\___|_|  |_| |_| |_|_|_| |_|\\__,_|"<< endl;
  cout << "\n\nEnter four letters to guess: (R)ed, (O)range, (Y)ellow, (G)reen, (B)lue, (P)urple\n\n";
  string guess;
  int i;
  for(i = 10; i > 0; i--){
      cout << "Guess " << i << ": ";
      cin >> guess;
      int pc = game.getPositionsCorrect(guess);
      int colors = game.getColorsCorrect(guess);
      if(pc==4){
             break;
      }
      cout << "Positions Correct:  " << pc << endl;
      cout << "Colors Correct: " << colors << endl;
  }
  if(i == 0){
      cout << "Sorry, the combination was: " << game.getSolution() << endl;
  }
  else{
      cout << "Great Job:  " << game.getSolution() << endl;
  }

}
