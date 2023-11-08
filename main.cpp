#include "TicTacToe.h"
#include <iostream>
using namespace std;

main(){
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
  system("cls");
  cout << tic << endl;
  if(tic.won() == 1){
    cout << tic.get() << "'s win";
  }
  else{
    cout << "Neither of you won, you are equals" << endl;
  }
}
