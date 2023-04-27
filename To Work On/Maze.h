#pragma once
#include<iostream>
using namespace std;

class Maze{
  public:
    void solve();
    void printMaze();
    friend ostream &operator <<(ostream & out, const Maze &m);
  private:
    int startRow = 2;
    int startCol = 0;
    int endRow = 4;
    int endCol = 11;
    //Maze # is a wall, space is empty, . is the path
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
      bool solve(int, int);
      bool isEmpty(int, int);
};

void Maze::solve(){
  if(solve(startRow, startCol)){
    cout << "Success" << endl;
  }
  else{
    cout << "Could not be solved." << endl;
  }
}

bool Maze::solve(int currR, int currC){
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

bool Maze::isEmpty(int r, int c){
  if(r >= 0 && c >= 0 && r < 12 && c < 12){
    if(maze[r][c] == ' ')
    return true;
  }
  return false;
}

ostream &operator <<(ostream & out, const Maze &m){
  for (int i = 0; i < 12; i++) {
    for (int j = 0; j < 12; j++){
      out << m.maze[ i ][ j ] << ' ';
    }
    out << '\n';
  }
  return out;
}
