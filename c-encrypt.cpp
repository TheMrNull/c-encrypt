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
    char processed = c ^ key[keyIndex % keyLength];  // core logic for encryption with XOR
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
  ifstream fileIn(inFilePath, ios::binary);

  if(!fileIn.is_open()){
    cerr << "An error occured while opening " << inFilePath << endl;
    return;
  }

  string outFilePath = inFilePath.erase(inFilePath.length()- enc.length());
  ofstream fileOut(outFilePath, ios::binary);
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
    char processed = c ^ key[keyIndex % keyLength];
    fileOut.put(processed);
    keyIndex++;
  }


  auto end = high_resolution_clock::now();
  auto duration = duration_cast<seconds>(end - start);

  cout << inFilePath << " was decrypted in " << duration.count() << " seconds!" << endl;
}




void usage(){
  printf("Usage is simple, just choose a mode when booting the program and follow the instructions.\n! PLEASE REMEMBER YOUR ENCRYPTION KEYS !\n");
  printf("Supported formats:\n- .txt\n- .png\n- .PDF\nOthers may be supported but I have not tried.\n");
  printf("The file passed must not contain spaces otherwise fstream won't be able to open it.\nIf no full path is given the file is assumed to be in the same directory as the program.");
  printf("\nNote that this is just a side project, if you choose to encrypt important documents that's on you mate!\n");
  printf("\n| Instagram: @modo_06 | GitHub: TheMrNull |\n");
}
