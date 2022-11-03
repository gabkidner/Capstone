#pragma once
using std::cout;
using std::endl;

class GuessYourNumber{
  public:
    GuessYourNumber();
    void guess();
  private:
    int guess;
    int high;
    int low;
};

GuessYourNumber::GuessYourNumber(){
  high = 100;
  low = 0;
  guess = -1;
}

void GuessYourNumber::guess(){
  srand(time(NULL));
  number = rand() % high + low;
}
