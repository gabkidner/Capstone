#pragma once
using std::ostream;
using std::endl;
using std::cout;

enum {R = 'R', Y = 'Y'};

class Connect4{
  public:
    Connect4();
    void place(int);
    void switchPlayer();
    bool won();
    char getPlayer();
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
  bool done = false;
  c--;
  for(int r = 5; r >= 0; r--){
    if(grid[r][c] == ' ' && !done){
      grid[r][c] = color;
      done = true;
    }
  }

}

ostream &operator <<(ostream & out, const Connect4 &game){
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
  //Row chec
 for(int r = 0; r < 6; r++){
    for(int i = 6; i > 2; i--){
      if(grid[r][i] == color && grid[r][i-1] == color && grid[r][i-2] == color && grid[r][i-3] == color){
        return true;
      }
    }
  }
  //Column check
  for(int c = 0; c < 7; c++){
    for(int i = 5; i > 0; i--){
      if(grid[i][c] == color && grid[i-1][c] == color && grid[i-2][c] == color && grid[i-3][c] == color){
        return true;
      }
    }
  }
  //for(int )
  //diaganal
  /*for(int i = 0; i <=2; i++){
    if(grid[i][i] == color && grid[i+1][i+1] == color && grid[i+2][i+2] == color && grid[i+3][i+3] == color){
      return true;
    }
  }
  for(int i = 5; i >=3; i--){
    if(grid[i][i+1] == color && grid[i-1][i] == color && grid[i-2][i-1] == color && grid[i-3][i-2] == color){
      return true;
    }
    if(grid[i][i+2] == color && grid[i-1][i+1] == color && grid[i-2][i] == color && grid[i-3][i-1] == color){
      return true;
    }
    if(grid[i][i+3] == color && grid[i-1][i+2] == color && grid[i-2][i+1] == color && grid[i-3][i] == color){
      return true;
    }
  }
  /*for(int i = 6; i >=5; i--){
    if(grid[i-2][i] == color && grid[i-3][i-1] == color && grid[i-4][i-2] == color && grid[i-5][i-3] == color){
      return true;
    }
  }
  for(int i = 6; i>=5; i--){
    if(grid[i][i-2] == color && grid[i-1][i-3] == color && grid[i-2][i-4] == color && grid[i-3][i-5] == color){
      return true;
    }
  }*/
  return false;
}

char Connect4::getPlayer(){
  return color;
}
