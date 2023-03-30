<<<<<<< HEAD
#pragma once
#include <iostream>
#include <ctime>
using std::ostream;
using std::endl;
using std::cout;

class TwentyFortyEight{
  public:
    TwentyFortyEight();
    friend ostream &operator <<(ostream&, const TwentyFortyEight &);
  private:
    int grid[4][4];
};

TwentyFortyEight::TwentyFortyEight(){
  srand(time(NULL));
  int done = 0;
  for(int r = 0; r < 4; r++){
    for(int c = 0; c < 4; c++){
      if(done == 1){
        int found = 0;
        for(int t = 0; t < 4; t++){
          for(int v = 0; v < 4; v++){
            if(grid[t][v] != 2 && grid[t][v] != 4){
              grid[t][v] = 0;
              found++;
            }
          }
        }
        return;
      }
      int number = rand() % 2;
      if(number == 1){
        int num = rand() % 4;
        cout << "Num: " << num << endl;
        if(num == 3){
          grid[r][c] = 4;
          done++;
        }
        else{
          grid[r][c] = 2;
          done++;
        }
      }
      else{
        grid[r][c] = 0;
      }
    }
  }
}

ostream &operator <<(ostream & out, const TwentyFortyEight &game){
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
=======
#pragma once
#include <iostream>
#include <ctime>
using std::ostream;
using std::endl;
using std::cout;

class TwentyFortyEight{
  public:
    TwentyFortyEight();
    friend ostream &operator <<(ostream&, const TwentyFortyEight &);
  private:
    int grid[4][4];
};

TwentyFortyEight::TwentyFortyEight(){
  srand(time(NULL));
  int done = 0;
  for(int r = 0; r < 4; r++){
    for(int c = 0; c < 4; c++){
      if(done == 1){
        int found = 0;
        for(int t = 0; t < 4; t++){
          for(int v = 0; v < 4; v++){
            if(grid[t][v] != 2 && grid[t][v] != 4){
              grid[t][v] = 0;
              found++;
            }
          }
        }
        return;
      }
      int number = rand() % 2;
      if(number == 1){
        int num = rand() % 4;
        cout << "Num: " << num << endl;
        if(num == 3){
          grid[r][c] = 4;
          done++;
        }
        else{
          grid[r][c] = 2;
          done++;
        }
      }
      else{
        grid[r][c] = 0;
      }
    }
  }
}

ostream &operator <<(ostream & out, const TwentyFortyEight &game){
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
>>>>>>> 57b225d3ff40f36f930dd6732954b3286e890a16
