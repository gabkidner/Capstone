#include <iostream>
#include <ctime>
#include <cstring>
#include "Table.h"
using namespace std;


main(){
  string user;
  Table table;
  Element elem;
  do{
    cout << "Input the abreviation, the atomic number or type 0 to quit\nType here: ";
    cin >> user;
    cout << table;
  }while(user != "0");
}
