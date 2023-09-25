#include "TicTacToe.h"
#include <iostream>
using namespace std;

main(){
  char choice;
  TicTacToe tic;
  while(!tic.won()){
    tic.switchPlayer();
    system("cls");
    cout << tic;
    cin >> choice;
    tic.place(choice);
}
