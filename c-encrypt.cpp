#include "header.h"
#include<iostream>
#include<chrono>
#include<fstream>
#include<cstring>
using namespace std;
using namespace std::chrono;


void readFromFile(){
  string inFilePath;
  string outFilePath;

  cout << "Please input path to file to open: ";
  cin >> inFilePath;
  cout << "Now input path where to save encrypted file: ";
  cin >> outFilePath;

  ifstream fileIn(inFilePath, ios::binary);
  ofstream fileOut(outFilePath, ios::binary);

  if(!fileIn.is_open()){
    cerr << "An error occured while opening " << inFilePath << endl;
    return;
  }
  if(!fileOut.is_open()){
    cerr << "An error occured while opening " << outFilePath << endl;
  }
}




