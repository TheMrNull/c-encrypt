#include "header.h"
#include<iostream>
#include<chrono>
#include<fstream>
#include<cstring>
using namespace std;
using namespace std::chrono;


void readFromFileEncrypt(){
  auto start = high_resolution_clock::now();
  string inFilePath;

  cout << "Please input file to open: ";
  cin >> inFilePath;
  string outFilePath = inFilePath + ".enc";
  ifstream fileIn(inFilePath, ios::binary);
  ofstream fileOut(outFilePath, ios::binary);

  if(!fileIn.is_open()){
    cerr << "An error occured while opening " << inFilePath << endl;
    return;
  }
  if(!fileOut.is_open()){
    cerr << "An error occured while opening " << outFilePath << endl;
    return;
  }

  string key;
  cout << "Please input encryption key.\nMAKE SURE TO REMEBER IT FOR DECRYPTION: ";
  cin >> key;

  int keyLength = key.length();
  int keyIndex = 0;
  char c;

  while(fileIn.get(c)){
    char processed = c ^ key[keyIndex&keyLength];
    fileOut.put(processed);
    keyIndex++;
  }


  auto end = high_resolution_clock::now();
  auto duration = duration_cast<seconds>(end - start);

  cout << inFilePath << " was encrypted with success in " << duration.count() << " seconds!" << endl;
}




void readFromFileDecrypt(){
  auto start = high_resolution_clock::now();
  string inFilePath;
  string enc = ".enc";

  cout << "Please input file to open: ";
  cin >> inFilePath;
  string outFilePath = inFilePath.erase(inFilePath.length()- enc.length());
  ifstream fileIn(inFilePath, ios::binary);
  ofstream fileOut(outFilePath, ios::binary);

  if(!fileIn.is_open()){
    cerr << "An error occured while opening " << inFilePath << endl;
    return;
  }
  if(!fileOut.is_open()){
    cerr << "An error occured while opening " << outFilePath << endl;
    return;
  }

  string key;
  cout << "Please input decryption key: ";
  cin >> key;

  int keyLength = key.length();
  int keyIndex = 0;
  char c;

  while(fileIn.get(c)){
    char processed = c ^ key[keyIndex&keyLength];
    fileOut.put(processed);
    keyIndex++;
  }


  auto end = high_resolution_clock::now();
  auto duration = duration_cast<seconds>(end - start);

  cout << inFilePath << " was decrypted in " << duration.count() << " seconds!" << endl;
}
