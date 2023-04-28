#pragma once
#include <iostream>
#include <conio.h>
using std::ostream;
using std::endl;
using std::cout;

/*Function for main
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
*/
enum {R = 'R', Y = 'Y'};

class Connect4{
  public:
    Connect4();
    void place(int);
    void switchPlayer();
    bool won();
    char getPlayer();
    void pressEnter();
    friend ostream &operator <<(ostream&, const Connect4 &);
  private:
    char grid[6][7] = {
      {' ', ' ', ' ', ' ', ' ', ' ', ' '},
      {' ', ' ', ' ', ' ', ' ', ' ', ' '},
      {' ', ' ', ' ', ' ', ' ', ' ', ' '},
      {' ', ' ', ' ', ' ', ' ', ' ', ' '},
      {' ', ' ', ' ', ' ', ' ', ' ', ' '},
      {' ', ' ', ' ', ' ', ' ', ' ', ' '},
    };
    char color;
};

Connect4::Connect4(){
  color = Y;
}

void Connect4::switchPlayer(){
  if(color == R){
    color = Y;
  }
  else{
    color = R;
  }
}

void Connect4::place(int c){
  if(c > 0 && c < 8){
    bool done = false;
    c--;
    for(int r = 5; r >= 0; r--){
      if(grid[r][c] == ' ' && !done){
        grid[r][c] = color;
        done = true;
      }
    }
  }
}

ostream &operator <<(ostream & out, const Connect4 &game){
  system("cls");
  out << "  1 | 2 | 3 | 4 | 5 | 6 | 7\n +-+-+-+-+-+-+-+-+-+-+-+-+-+\n  ";
  for(int r = 0; r < 6; r++){
    for(int c = 0; c < 7; c++){
      out << game.grid[r][c];
      if(c != 6){
        out << " | ";
      }
    }
    if(r != 5){
      out << "\n +-+-+-+-+-+-+-+-+-+-+-+-+-+\n  ";
    }
  }
  return out;
}

bool Connect4::won(){
  //[5][3]--[2][6]
  if(grid[5][3] == color && grid[4][4] == color && grid[3][5] == color && grid[2][6]){
    return true;
  }
  //[0][3] [3][0]
  if(grid[0][3] == color && grid[1][2] == color && grid[2][1] == color && grid[3][0] == color){
    return true;
  }
  //[0][3] -- [3][6]
  if(grid[0][3] == color && grid[1][4] == color && grid[2][5] == color && grid[3][6] == color){
    return true;
  }
  //Diagonal [2][0] -- [5][3]
  if(grid[2][0] == color && grid[3][1] == color && grid[4][2] == color && grid[5][3] == color){
    return true;
  }
  for(int i = 0; i < 3; i++){
    int neg = 0 - i;
    //[4][0] [3][1] [2][2] [1][3] [0][4]
    if(grid[i][neg+4] == color && grid[i+1][neg+3] == color && grid[i+2][neg+2] == color && grid[i+3][neg+1] == color){
      return true;
    }
    //Diagonal [5][2] -- [1][6]
    if(grid[i+1][neg+6] == color && grid[i+2][neg+5] == color && grid[i+3][neg+4] == color && grid[i+4][neg+3] == color){
      return true;
    }
    //Diagonal [5][1] -- [0][6]
    if(grid[i][neg+6] == color && grid[i+1][neg+5] == color && grid[i+2][neg+4] == color && grid[i+3][neg+3] == color){
      return true;
    }
    //Diagonal [5][0] [4][1] [3][2] [2][3] [1][4] [0][5]
    if(grid[i][neg+5] == color && grid[i+1][neg+4] == color && grid[i+2][neg+3] && grid[i+3][neg+2] == color){
      return true;
    }
  }
  for(int r = 0; r < 6; r++){
    for(int i = 6; i > 2; i--){
      //Row Test
      if(grid[r][i] == color && grid[r][i-1] == color && grid[r][i-2] == color && grid[r][i-3] == color){
        return true;
        for(int c = 0; c < 7; c++){
          //Diagonal [0][0] - [5][5]
          if(grid[r][c] == color && grid[r+1][c+1] == color && grid[r+2][r+2] == color && grid[r+3][r+3] == color){
            return true;
          }
          for(int i = 5; i > 3; i--){
            //Diagonal [0][2] -- [4][6]
            if(grid[i-1][i+1] == color && grid[i-2][i] == color && grid[i-3][i-1] == color && grid[i-4][i-2] == color){
              return true;
            }
            //Diagonal [1][0] --[5][4]
            if(grid[i][i-1] == color && grid[i-1][i-2] == color && grid[i-2][i-3] == color && grid[i-3][i-4] == color){
              return true;
            }
            //Diagonal [0][1] -- [5][6]
            if(grid[i][i+1] == color && grid[i-1][i] == color && grid[i-2][i-1] == color && grid[i-3][i-2] == color){
              return true;
            }
            //Collumn Testc <
            if(grid[i][c] == color && grid[i-1][c] == color && grid[i-2][c] == color && grid[i-3][c] == color){
              return true;
            }
          }
        }
      }
    }
  }
  int right = 0;
  for(int c = 0; c < 7; c++){
    for(int i = 5; i >= 0; i--){
      if(grid[i][c] == color){
        right++;
      }
    }
  }
  if(right == 4){
    return true;
  }
  return false;
}

char Connect4::getPlayer(){
  return color;
}
