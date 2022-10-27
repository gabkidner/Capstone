#pragma once
#include <ostream>
using std::cout;
using std::endl;

class Twenty48{
  public:
    Twenty48();
    int charToInt(char);
    void move(int);
    bool doneMoving(int);
    friend ostream &operator <<(ostream&, const Twenty48 &);
  private:
    int grid[4][4] = {{0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}};
};

Twenty48::Twenty48(){
  int numbers = 0;
  srand(time(NULL));
  for(int r = 0; r < 4; r++){
    for(int c = 0; c < 4; c++){
      int blah = rand() % 4;
      if(rand() % 2 == 1 && numbers != 2){
        if(blah == 0){
          grid[r][c] = 4;
        }
        else{
          grid[r][c] = 2;
        }
        numbers++;
      }
      else{
        grid[r][c] = 0;
      }
    }
  }
}

int Twenty48::charToInt(char choice){
  int input = choice;
  switch(choice){
    case 'w': return 1; break;
    case 'a': return 2; break;
    case 's': return 3; break;
    case 'd': return 4; break;
  }
  switch(input){
    case 72: return 1; break;
    case 75: return 2; break;
    case 80: return 3; break;
    case 77: return 4; break;
  }
}

void Twenty48::move(int choice){
  for(int r = 0; r < 4; r++){
    for(int c = 0; c < 4; c++){
      if(choice == 1){
        if(grid[r-1][c] == 0 && r-1 >= 0){
          grid[r-1][c] = grid[r][c];
          grid[r][c] = 0;
        }
        else if(grid[r-1][c] == grid[r][c]){
          grid[r-1][c] += grid[r][c];
          grid[r][c] = 0;
        }
      }
      else if(choice == 2){
        if(grid[r][c-1] == 0 && c-1 >= 0){
          grid[r][c-1] = grid[r][c];
          grid[r][c] = 0;
        }
        else if(grid[r][c-1] == grid[r][c]){
          grid[r][c-1] += grid[r][c];
          grid[r][c] = 0;
        }
      }
      else if(choice == 3){
        if(grid[r+1][c] == 0 && r+1 < 4){
          grid[r+1][c] = grid[r][c];
          grid[r][c] = 0;
        }
        else if(grid[r+1][c] == grid[r][c]){
          grid[r+1][c] += grid[r][c];
          grid[r][c] = 0;
        }
      }
      else if(choice == 4){
        if(grid[r][c+1] == 0 && c+1 < 4){
          grid[r][c+1] = grid[r][c];
          grid[r][c] = 0;
          break;
        }
        else if(grid[r][c+1] == grid[r][c]){
          grid[r][c+1] += grid[r][c];
          grid[r][c] = 0;
        }
      }
    }
  }
}

bool Twenty48::doneMoving(int choice){
  int numbers;
  for(int r = 0; r < 3; r++){
    for(int c = 0; c < 3; c++){
      if(choice == 1){
        if(grid[r][c] == 0 && grid[r][c+1] != 0){
          return false;
        }
      }
    }
  }
  return true;
}

ostream &operator <<(ostream & out, const Twenty48 &game){
  for(int r = 0; r < 4; r++){
    for(int c = 0; c < 4; c++){
      out << " | ";
      if(game.grid[r][c] == 0){
        out << " ";
      }
      else{
        out << game.grid[r][c];
      }
    }
    out << " | \n -----------------" << endl;
  }
  return out;
}
