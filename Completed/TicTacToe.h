#pragma once
#include <iostream>
using std::ostream;
using std::cout;

/*Function for main
char choice;
TicTacToe tic;
while(!tic.won()){
  tic.switchPlayer();
  system("cls");
  cout << tic;
  cin >> choice;
  tic.place(choice);
}
*/

enum {X = 'X', O = 'O'};

class TicTacToe{
  public:
    TicTacToe();
    void switchPlayer();
    void place(char);
    int won();
    char get();
    friend ostream &operator <<(ostream&, const TicTacToe &);
  private:
    char grid[3][3] = {
      {'1','2','3'},
      {'4','5','6'},
      {'7','8','9'}
    };
    char player;
};

TicTacToe::TicTacToe(){
  player = O;
}

void TicTacToe::switchPlayer(){
  if(player == X){
    player = O;
  }
  else{
    player = X;
  }
}

void TicTacToe::place(char choice){
  for(int r = 0; r < 3; r++){
    for(int c = 0; c < 3; c++){
      if(grid[r][c] == choice){
        grid[r][c] = player;
        return;
      }
    }
  }
  cout << "Invalid Move";
  switchPlayer();
}

int TicTacToe::won(){
  for(int r = 0; r < 3; r++){
    if(grid[r][0] == player && grid[r][1] == player && grid[r][2] == player){
      return 1;
    }
  }
  for(int c = 0; c < 3; c++){
    if(grid[0][c] == player && grid[1][c] == player && grid[2][c] == player){
      return 1;
    }
  }
  if(grid[0][0] == player && grid[1][1] == player && grid[2][2] == player){
    return 1;
  }
  if(grid[0][2] == player && grid[1][1] == player && grid[2][0] == player){
    return 1;
  }
  char loop = '1';
  int filled = 0;
  for(int r = 0; r < 3; r++){
    for(int c = 0; c < 3; c++){
      if(grid[r][c] != loop){
        filled++;
      }
      loop++;
    }
  }
  if(filled == 9){
    return 2;
  }
  return 0;
}

char TicTacToe::get(){
  return player;
}

ostream &operator <<(ostream & out, const TicTacToe &game){
  out << "\n  ";
  for(int r = 0; r < 3; r++){
    for(int c = 0; c < 3; c++){
      out << game.grid[r][c];
      if(c != 2){
        out << " | ";
      }
    }
    if(r != 2){
      out << "\n +-+-+-+-+-+\n  ";
    }
  }
  return out;
}
