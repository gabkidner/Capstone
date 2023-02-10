#pragma once
using std::cout;
using std::endl;

class GuessYourNumber{
  public:
    GuessYourNumber();
    void guessing();
    void editGuess(string);
    int complete(string);
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
  cout << "High: " << high << " LoW: " << low << endl;
  guess = rand() % high + low;
  cout << "Guess" << guess;
}

void GuessYourNumber::editGuess(string response){
  if(response == "high"){
    high = guess - 1;
  }
  else if(response == "low"){
    low = guess + 1;
  }
  tries++;
  cout << "High: " << high << " LoW: " << low << endl;
}

int GuessYourNumber::complete(string response){
  if(response == "correct"){
    return 1;
  }
  else if(tries == 15){
    return 2;
  }
  return 0;
}

ostream &operator <<(ostream & out, const GuessYourNumber &game){
  out << "I guess " << game.guess << " am I high, low, or correct?" << endl;
  return out;
}
