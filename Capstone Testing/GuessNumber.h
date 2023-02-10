#pragma once
using std::cout;
using std::endl;

class GuessNumber{
  public:
    GuessNumber();
    int result(int);
    bool correct(int);
    bool outOTries();
    int getNumber();
    void add(int);
    int get();
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

void GuessNumber::add(int user){
  if(user != number){
    rounds++;
  }
}
