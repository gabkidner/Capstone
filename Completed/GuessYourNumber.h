#pragma once
#include <iostream>
using std::cout;
using std::endl;
using std::ostream;
using std::string;

/*Function
GuessYourNumber game;
string user;
int result;
do{
  game.guessing();
  cout << game;
  cin >> user;
  game.editGuess(user);
  result = game.complete(user);
  cout << result << endl;
}while(result == 0);
*/

class GuessYourNumber{
  public:
    GuessYourNumber();
    void guessing();
    void editGuess(string);
    int complete(string);
    int getTries();
    friend ostream &operator <<(ostream&, const GuessYourNumber &);
  private:
    int high;
    int guess;
    int low;
    int tries;
};

GuessYourNumber::GuessYourNumber(){
  high = 100;
  low = 1;
  guess = -1;
  tries = 1;
}

void GuessYourNumber::guessing(){
  srand(time(NULL));
  guess = rand() % high;
  if (guess < low) {
      guess += low;
  }
  if (guess > high) {
      guess = high;
  }
}

void GuessYourNumber::editGuess(string response){
  if(response == "high"){
    high = guess - 1;
  }
  else if(response == "low"){
    low = guess + 1;
  }
  tries++;
}

int GuessYourNumber::complete(string response){
  if(response == "correct"){
      tries--;
      return 1;
  }
  else if(tries == 10){
    return 2;
  }
  return 0;
}

int GuessYourNumber::getTries() {
    return tries;
}

ostream &operator <<(ostream & out, const GuessYourNumber &game){
    out << "I guess " << game.guess << " am I high, low, or correct?" << endl;
  return out;
}
