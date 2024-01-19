#pragma once
#include <ctime>
#include <iostream>
using std::cout;
using std::endl;

/*Function
GuessNumber game;
int user, result;
do{
  cin >> user;
  result = game.result(user);
  game.add(user);
  if(result == 3){
    cout << "Lower" << endl;
  }
  else if(result == 2){
    cout << "Higher" << endl;
  }
  cout << "Result" << result << endl;
}while(result != 0 && result != 1);
*/

class GuessNumber{
  public:
    GuessNumber();
    int result(int);
    int getNumber();
    int getRounds();
    void add(int);
  private:
    int number;
    int rounds;
};

GuessNumber::GuessNumber(){
  srand(time(NULL));
  number = rand() % 100 + 1;
  rounds = 0;
}

int GuessNumber::result(int user){
  //0 = dead 1 = won 2 = lower 3 = higher
  if(user == number){
    return 1;
  }
  else if(user != number && rounds == 15){
    return 0;
  }
  else if(user > number){
    return 3;
  }
  else if(user < number){
    return 2;
  }
  return -1;
}

int GuessNumber::getNumber(){
  return number;
}

int GuessNumber::getRounds(){
  return rounds;
}

void GuessNumber::add(int user){
  if(user != number){
    rounds++;
  }
}