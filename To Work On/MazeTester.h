#pragma once
#include<iostream>
using namespace std;

class MazeTester{
  public:
    MazeTester();
    MazeTester(char [12][12]);
    bool solvable();
    bool solve(int currR, int currC);
    bool isEmpty(int r, int c);
    void printMaze();
  private:
    int startRow = 2;
    int startCol = 0;
    int endRow = 4;
    int endCol = 11;
    char maze[ 12 ][ 12 ] =
      { {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
      {  '#', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', ' ', '#'},
      {  ' ', ' ', '#', ' ', '#', ' ', '#', '#', '#', '#', ' ', '#'},
      {  '#', '#', '#', ' ', '#', ' ', ' ', ' ', ' ', '#', ' ', '#'},
      {  '#', ' ', ' ', ' ', ' ', '#', '#', '#', ' ', '#', ' ', ' '},
      {  '#', '#', '#', '#', ' ', '#', ' ', '#', ' ', '#', ' ', '#'},
      {  '#', ' ', ' ', '#', ' ', '#', ' ', '#', ' ', '#', ' ', '#'},
      {  '#', '#', ' ', '#', ' ', '#', ' ', '#', ' ', '#', ' ', '#'},
      {  '#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#', ' ', '#'},
      {  '#', '#', '#', '#', '#', '#', ' ', '#', '#', '#', ' ', '#'},
      {  '#', ' ', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', '#'},
      {  '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#'} };
};

MazeTester::MazeTester(){
  startCol = 2;
}

MazeTester::MazeTester(char maz[12][12]){
  for(int r = 0; r < 12; r++){
    for(int c = 0; c < 12; c++){
      maze[r][c] = maz[r][c];
    }
  }
}

bool MazeTester::solvable(){
  if(solve(startRow, startCol)){
    return true;
  }
  else{
    return false;
  }
}

bool MazeTester::solve(int currR, int currC){
  if(currR == endRow && currC == endCol){
    maze[currR][currC] = '.';
    return true;
  }
  if(isEmpty(currR, currC)){
    maze[currR][currC] = '.';
    if(solve(currR-1, currC) || solve(currR+1, currC) || solve(currR, currC+1) || solve(currR, currC-1)){
      return true;
    }
    else{
      maze[currR][currC] = ' ';
      return false;
    }
  }
  return false;
}

bool MazeTester::isEmpty(int r, int c){
  if(r >= 0 && c >= 0 && r < 12 && c < 12){
    if(maze[r][c] == ' '){
      return true;
    }
  }
  return false;
}

void MazeTester::printMaze(){
  for ( int r = 0; r < 12; r++ ){
    for ( int c = 0; c < 12; c++ ){
      cout << maze[r][c] << ' ';
    }
    cout << '\n';
  }
}
