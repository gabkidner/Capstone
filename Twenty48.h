#pragma once
using std::cout;
using std::endl;

class Twenty48{
  public:
    Twenty48();
    int realInput(int);
    void move(int);
    bool doneMoving(int);
    void addNums();
    bool hasWon();
    bool hasLost();
    friend ostream &operator <<(ostream&, const Connect4 &);
  public:
    int grid[4][4] = {{0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}};
};


Twenty48::Twenty48(){
  int numbers = 0;
  srand(time(NULL));
  for(int r = 0; r < 4; r++){
    for(int c = 0; c < 4; c++){
      if(rand() % 2 == 1 && numbers != 2){
        if(rand() % 4 == 0){
          grid[r][c] = 4;
        }
        else{
          grid[r][c] = 2;
        }
        numbers++;
      }
    }
  }
}

int Twenty48::realInput(int direction){
  switch(direction){
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

void Twenty48::move(int direction){
  int number;
  for(int r = 0; r < 4; r++){
    for(int c = 0; c < 4; c++){
      if(direction == 1){
        number = r-1;
        if(grid[number][c] == grid[r][c] && r-1 >= 0){
          grid[number][c] *= 2;
          grid[r][c] = 0;
        }
        if(grid[number][c] == 0 && r-1 >= 0){
          grid[number][c] = grid[r][c];
          grid[r][c] = 0;
        }
      }
      else if(direction == 2){
        number = c-1;
        if(grid[r][number] == grid[r][c] && c-1 >= 0){
          grid[r][number] *= 2;
          grid[r][c] = 0;
        }
        if(grid[r][number] == 0 && c-1 >= 0){
          grid[r][number] = grid[r][c];
          grid[r][c] = 0;
        }
      }
      else if(direction == 3){
        number = r+1;
        if(grid[number][c] == grid[r][c] && r+1 < 4){
          grid[number][c] *= 2;
          grid[r][c] = 0;
        }
        if(grid[number][c] == 0 && r+1 < 4){
          grid[number][c] = grid[r][c];
          grid[r][c] = 0;
        }
      }
      else if(direction == 4){
        number = c+1;
        if(grid[r][number] == grid[r][c] && c+1 < 4){
          grid[r][number] *= 2;
          grid[r][c] = 0;
        }
        if(grid[r][number] == 0 && c+1 < 4){
          grid[r][number] = grid[r][c];
          grid[r][c] = 0;
        }
      }
    }
  }
}

bool Twenty48::doneMoving(int direction){
  if(direction == 1){
    for(int c = 3; c >= 0; c--){
      for(int r = 3; r > 0; r--){
        if(grid[r][c] != 0 && grid[r-1][c] == 0){
          return false;
        }
      }
    }
  }
}

void Twenty48::addNums(){
  srand(time(NULL));
  int blah, loop = 0;
  for(int r = 0; r < 4; r++){
    for(int c = 0; c < 4; c++){
      blah = rand() % 9;
      if(grid[r][c] == 0 && loop == 0){
        if(blah >= 0 && blah <= 5){
          grid[r][c] = 2;
        }
        else{
          grid[r][c] = 4;
        }
        loop++;
      }
    }
  }
}

bool Twenty48::hasWon(){
  for(int r = 0; r < 4; r++){
    for(int c = 0; c < 4; c++){
      if(grid[r][c] == 2048){
        return true;
      }
    }
  }
  return false;
}

bool Twenty48::hasLost(){
  for(int r = 0; r < 4; r++){
    for(int c = 0; c < 4; c++){
      if(grid[r][c] == 0){
        return false;
      }
    }
  }
  return true;
}

ostream &operator <<(ostream & out, const Twenty48 &game){
  for(int r = 0; r < 4; r++){
    out << " -----------------\n | ";
    for(int c = 0; c < 4; c++){
      if(game.grid[r][c] == 0){
        out << " ";
      }
      else{
        out << game.grid[r][c];
      }
      out << " | ";
    }
    out << endl;
  }
  out << " -----------------" << endl;
  return out;
}
