#include <iostream>
#include <fstream>

using namespace std;

int main() {

  fstream myfile;
  myfile.open("chris.txt", ios::out | ios::in);
  // myfile << "chklkjkistian";
  // if(!myfile) {
  //   myfile.open("text.txt", ios::app);
  // }

  if(myfile) {
    cout << "file";
  }
  
}