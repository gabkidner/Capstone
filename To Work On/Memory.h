#pragma once
#include <ctime>
using std::ostream;
using std::cout;
using std::endl;

class Memory{
  public:
    Memory();
    void flip(int);
    bool correct(int, int);
    void flipBack();
    int result();
    friend ostream &operator <<(ostream&, const Memory &);
  private:
    bool blankGrid[36] = {false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false};
    bool flipGrid[36] = {false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false};
    int grid[36] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
};

Memory::Memory(){
  int distance, index, otherIndex;
  srand(time(NULL));
  for(int i = 0; i < 20; i++){
    do{
      index = rand() % 36;
    }while(grid[index] != 0);
    do{
      distance = rand() % 71 - 35;
      otherIndex = index - distance;
    }while(otherIndex > 35 || otherIndex < 0 || grid[otherIndex] != 0);
    grid[index] = i+1;
    grid[otherIndex] = i+1;
  }
}

void Memory::flip(int choice){
  for(int i = 0; i < 36; i++){
    if(i = choice){
      flipGrid[i] == true;
    }
  }
}

bool Memory::correct(int choice1, int choice2){
  if(grid[choice1] == grid[choice2]){
    blankGrid[choice1] = true;
    blankGrid[choice2] = true;
    return true;
  }
  return false;
}

void Memory::flipBack(){
  for(int i = 0; i < 36; i++){
    flipGrid[i] == false;
  }
}

ostream &operator <<(ostream & out, const Memory &game){
  for(int i = 0; i < 36; i++){
    out << " | ";
    if(game.blankGrid[i]){
      out << " ";
    }
    else if(game.flipGrid[i]){
      out << game.grid[i];
    }
    else{
      int b = i + 1;
      out << b;
    }
    if(i % 4 == 0){
      out << endl;
    }
  return out;
}
