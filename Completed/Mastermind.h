#pragma once
#include <cstdlib>
#include <iostream>
#include <time.h>
/*
Mastermind game;
cout << " __  __           _                      _           _ " << endl;
cout << "|  \\/  | __ _ ___| |_ ___ _ __ _ __ ___ (_)_ __   __| |"<< endl;
cout << "| |\\/| |/ _` / __| __/ _ \\ '__| '_ ` _ \\| | '_ \\ / _` |"<< endl;
cout << "| |  | | (_| \\__ \\ ||  __/ |  | | | | | | | | | | (_| |"<< endl;
cout << "|_|  |_|\\__,_|___/\\__\\___|_|  |_| |_| |_|_|_| |_|\\__,_|"<< endl;
cout << "\n\nEnter four letters to guess: (R)ed, (O)range, (Y)ellow, (G)reen, (B)lue, (P)urple\n\n";
string guess;
int i;
for(i = 10; i > 0; i--){
    cout << "\nGuess's left:  " << i << endl;
    cin >> guess;
    int pc = game.getPositionsCorrect(guess);
    int colors = game.getColorsCorrect(guess);
    if(pc==4){
           break;
    }
    cout << "\nPositions Correct:  " << pc << endl;
    cout << "Colors Correct: " << colors << endl;
}
if(i == 0){
    cout << "Sorry, the combination was: " << game.getSolution() << endl;
}
else{
    cout << "Great Job:  " << game.getSolution() << endl;
}
*/
using namespace std;


class Mastermind{
  public:
    Mastermind();
    char getRandomLetter();
    void setRandomColors();
    int getPositionsCorrect(string guess);
    int getColorsCorrect(string guess);
    void setSolution(string str);
    string getSolution();
  private:
    string colors;
};

Mastermind::Mastermind(){
    srand (time(NULL));
    //The following command sizes the string and also gives you a known value for testing purposes.
    //Do not remove it even when you get the secret combination working
    setRandomColors();
}

//1.  Use a switch statement to return a random letter to represent the colors red, orange, yellow, green, blue
//Generate a Random number and each case will return R, O, Y, G, B
char Mastermind::getRandomLetter(){
  int color = 0;
  for(int i = 0; i < 4; i++){
    color = rand() % 5 + 1;
  }
  switch(color){
    case 1: return 'R';
    case 2: return 'O';
    case 3: return 'Y';
    case 4: return 'G';
    case 5: return 'B';
  }
  cout << color << endl;
}

//2.  Modify the secret combination of colors to be random by calling the getRandomLetter()
//for each position in the string "colors"
void Mastermind::setRandomColors(){
    colors.erase();
    for(int i = 0; i < 4; i++){
      colors += getRandomLetter();
    }
}


//3.  Return the number of colors that are in the Correct position
//Compare the guess to the "secret" to "colors"
//Example  secret of "RBYG", and colors = "YBGO" would only return 1 since only blue is in the correct position
int Mastermind::getPositionsCorrect(string guess)
{
  int correct = 0;
    for(int i = 0; i < 4; i++){
      if(guess[i] == colors[i]){
        correct++;
      }
    }
    return correct;
}



/*4.  Returns the number of colors that are correct but not in the correct position
      You can assume that there are not any duplicate colors in the guess, or the colors.
      Example: guess = "ROYG" and colors = "RYOB" would return 1,
         Red doesn't count as it's in the correct position, Green is not a correct color, so only Orange and Yellow count

    Challenge: Get the logic for the colors correct to work for duplicate values...
        For example
        guess = "ROGR" colors = "ORYO" should only be 2 correct for 1 red, and 1 orange.

*/

int Mastermind::getColorsCorrect(string guess)
{
  int correct = 0;
  for(int g = 0; g < 4; g++){
    bool good = false;
    for(int c = 0; c < 4; c++){
      if(guess[g] == colors[c] && !good && g != c){
        good = true;
        correct++;
      }
    }
  }
  return correct;
}

void Mastermind::setSolution(string str){
   colors = str;
}

//This is an accessor method to allow you to display the solution
string Mastermind::getSolution()
{
    return colors;
}
