#ifndef DIE_H
#define DIE_H
using std::endl;
using std::ostream;
using std::to_string;
using std::string;
/* function for main
int sides, rolls;
cout << "How many sides should this die/coin have?\n";
cin >> sides;
cout << "How many times should I roll this " << sides << " sided die?" << endl;
cin >> rolls;
Die die(sides, rolls);
die.roll();
system("cls");
cout << die << endl;
 
*/

class Die{
  public:
    Die(int, int);
    void roll();
    friend ostream &operator << (ostream&, const Die&);
  private:
    int sides;
    int rolls;
    int total;
    string result;
};

Die::Die(int numSides, int numRolls){
  sides = numSides;
  rolls = numRolls;
  total = 0;
  result = "";
}

void Die::roll(){
  int temp;
  srand(time(NULL));
  for(int i = 0; i < rolls; i++){
    temp = rand() % sides + 1;
    total += temp;
    string temper = to_string(temp);
    result += temper;
    result += '\n';
  }
}

ostream &operator << (ostream &out, const Die &die){
  string thing = "";
  string number = "";
  if(die.sides == 2){
    out << "You flipped a coin ";
    thing += "flipped";
  }
  else{
    out << "You rolled a " << die.sides << " sided die ";
    thing += "rolled";
  }
  if(die.rolls == 1){
    out << "once";
    number += "was";
  }
  else{
    out << die.rolls << " times";
    number += "were";
  }
  out << " and the number(s) " << thing << " " << number << endl;
  out << die.result << "The total of these number(s) is " << die.total << endl;
  return out;
}
#endif
