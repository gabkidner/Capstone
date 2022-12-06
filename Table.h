#pragma once
#include <iostream>
#include <sstream>
#include <fstream>
using std::ostream;
using std::string;
using std::endl;
using std::ifstream;
using std::ios;

struct Element{
  string abrev;
  string name;
  string weight;
  string number;
};

class Table{
  public:
    void lookUp(string);
    friend ostream &operator << (ostream&, const Table&);
  private:
    Element elem;
};

void Table::lookUp(string user){
  ifstream fin("elements.csv", ios::in);
  while(elem.abrev != user && !fin.eof()){
    getline(fin, elem.number, ',');
    getline(fin, elem.name, ',');
    getline(fin, elem.abrev, ',');
    getline(fin, elem.weight, '\n');
  }
  while(elem.number != user && !fin.eof()){
    getline(fin, elem.number, ',');
    getline(fin, elem.name, ',');
    getline(fin, elem.abrev, ',');
    getline(fin, elem.weight, '\n');
  }

  fin.close();
}

ostream &operator << (ostream &out, const Table &table){
  Element element = table.elem;
  out << "\nNumber: " << table.elem.number << "\nName: " << element.name << "\nSymbol: " << element.abrev << "\nMass: " << element.weight << "\n" << endl;
  return out;
}
