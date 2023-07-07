#ifndef TILEGAME_H
#define TILEGAME_H
#include <iostream>
using std::ostream;

/*function for main:
TileGame game;
int choice, chances = 0;
do{
  system("cls");
  cout << game << "\n0. Quit\n1. Shift Right\n2. Shift Left\n3. Swap\n4. Rules\nChoose one: ";
  cin >> choice;
  switch(choice){
    case 1: game.moveRight(); break;
    case 2: game.moveLeft(); break;
    case 3: game.swap(); break;
    case 4: cout << rules; break;
  }
  chances++;
}while(!game.inOrder() && choice > 0 && chances < 50);
if(chances = 50){
  cout << "You ran out of chances\n" << endl;
}
if(game.inOrder() && chances < 5){
  system("cls");
  cout << game << "\nCongrats You Won!!!!!" << endl;
}
*/

class TileGame{
  public:
     TileGame();
     void moveRight();
     void moveLeft();
     void swap();
     bool inOrder();
     friend ostream &operator << (ostream&, const TileGame&);
  private:
     int tiles[10];
     int findZero();
};

TileGame::TileGame(){
    for(int i = 0; i < 10; i++){
      tiles[i] = i;
    }

    for(int i = 0; i < 10; i++){
      int blah = rand() % 10;
      int neat = tiles[i];
      tiles[i] = tiles  [blah];
      tiles[blah] = neat;
    }
}

int TileGame::findZero(){
    int location;
    for(int i = 0; i < 10; i++){
      if(tiles[i] == 0){
        location = i;
      }
    }
    return location;
}

void TileGame:: moveRight(){
  int zero = findZero(), left = zero-1;
  if(zero == 0){
    left = 9;
  }
  tiles[zero] = tiles[left];
  tiles[left] = 0;
}
void TileGame::moveLeft(){
  int zero = findZero(), right = zero+1;
  if(zero == 9){
    right = 0;
  }
  tiles[zero] = tiles[right];
  tiles[right] = 0;
}

void TileGame::swap(){
    int zero = findZero(), left = zero-1, right = zero+1;
    if(zero == 9){
      right = 0;
    }
    if(zero == 0){
      left = 9;
    }
    char temp = tiles[left];
    tiles[left] = tiles[right];
    tiles[right] = temp;
}

bool TileGame::inOrder(){
  int good = 0;
  for(int i = 0; i < 9; i++){
    if(tiles[i+1] - tiles[i] == 1){
      good++;
    }
  }
  if(good == 9){
    return true;
  }
  return false;
}

ostream &operator << (ostream &out, const TileGame &game){
  for(int i = 0; i < 10; i++){
    if(game.tiles[i]>0)
      out << "[" << game.tiles[i] << "]" << " ";
    else
      out << "[ ]" << " ";
  }
  return out;
}
#endif
