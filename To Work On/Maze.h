#pragma once
#include "MazeTester.h"
#include <ctime>
#include <iostream>
using namespace std;

class Maze{
  public:
    Maze();
    void print();
  private:
    char maze[ 12 ][ 12 ];
};

Maze::Maze(){
  srand(time(NULL));
  bool test;
  do{
    for(int r = 0; r < 12; r++){
      for(int c = 0; c < 12; c++){
        int temp = rand() % 2;
        if(temp = 0){
          maze[r][c] = 'a';
        }
        else{
          maze[r][c] = ' ';
        }
      }
    }
    MazeTester mt(maze);
    if(mt.solvable()){
      test = true;
    }
    else{
      test = false;
    }
  }while(!test);
}

void Maze::print(){
  for(int i = 0; i < 12; i++){
    for(int o = 0; o < 12; o++){
      cout << maze[i][o];
    }
    cout << endl;
  }
}
