#pragma once
#include <iomanip>
using std::ostream;
using std::endl;
using std::cout;

class Twenty48{
  public:
    Twenty48();
    int realDirection(int);
    void movement(int);
    friend ostream &operator <<(ostream&, const Twenty48 &);
  private:
    int grid[4][4];
};

Twenty48::Twenty48(){
  srand(time(NULL));
  int done = 0;
  while(done < 3){
    for(int r = 0; r < 4; r++){
      for(int c = 0; c < 4; c++){
        int number = rand() % 2;
        if(number == 1){
          int num = rand() % 4;
          if(number == 3){
            grid[r][c] = 4;
          }
          else{
            grid[r][c] = 2;
          }
        }
        else{
          grid[r][c] = 0;
        }
      }
    }
    done++;
  }
}

int Twenty48::realDirection(int user){
  switch(user){
    case 119: return 1; break;
    case 72: return 1; break;
    case 97: return 2; break;
    case 75: return 2; break;
    case 115: return 3; break;
    case 80: return 3; break;
    case 100: return 4; break;
    case 77: return 4; break;
  }
}

void Twenty48::movement(int user){
  for(int r = 0; r < 4; r++){
    for(int c = 0; c < 4; c++){
      if(user == 1){
        //up
        if(grid[r-1][c] == 0 && r-1 >= 0){
          grid[r-1][c] = grid[r][c];
          grid[r][c] = 0;
        }
        else if(grid[r+1][c] == grid[r][c] && r-1 >= 0){
          grid[r-1][c] *= 2;
          grid[r][c] = 0;
        }
      }
      else if(user == 2){
        if(grid[r][c-1] == 0 && c-1 >= 0){
          grid[r][c-1] = grid[r][c];
          grid[r][c] = 0;
        }
        else if(grid[r][c-1] == grid[r][c] && c-1 >= 0){
          grid[r][c-1] *= 2;
          grid[r][c] = 0;
        }
      }
      else if(user == 3){
        if(grid[r+1][c] == 0 && r+1 < 4){
          grid[r+1][c] = grid[r][c];
          grid[r][c] = 0;
        }
        else if(grid[r+1][c] == grid[r][c] && r+1 < 4){
          grid[r+1][c] *= 2;
          grid[r][c] = 0;
        }
      }
      else if(user == 4){
        if(grid[r][c+1] == 0 && c+1 < 4){
          grid[r][c+1] = grid[r][c];
          grid[r][c] = 0;
        }
        else if(grid[r][c+1] == grid[r][c] && c+1 < 4){
          grid[r][c+1] *= 2;
          grid[r][c] = 0;
        }
      }
    }
  }
}

ostream &operator <<(ostream & out, const Twenty48 &game){
  for(int r = 0; r < 4; r++){
    out << "---------------" << endl;
    for(int c = 0; c < 4; c++){
      out << " | ";
      out << game.grid[r][c];
    }
    cout << endl;
  }
  return out;
}
