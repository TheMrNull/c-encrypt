#include "header.h"
#include<iostream>
using namespace std;

void title(){

cout << "                                                                                      ░██     "<< endl;
cout << "                                                                                      ░██     "<< endl;
cout << " ░███████           ░███████  ░████████   ░███████  ░██░████ ░██    ░██ ░████████  ░████████  "<< endl;
cout << "░██    ░██ ░██████ ░██    ░██ ░██    ░██ ░██    ░██ ░███     ░██    ░██ ░██    ░██    ░██     "<< endl;
cout << "░██                ░█████████ ░██    ░██ ░██        ░██      ░██    ░██ ░██    ░██    ░██     "<< endl;
cout << "░██    ░██         ░██        ░██    ░██ ░██    ░██ ░██      ░██   ░███ ░███   ░██    ░██     "<< endl;
cout << " ░███████           ░███████  ░██    ░██  ░███████  ░██       ░█████░██ ░██░█████      ░████  "<< endl;
cout << "                                                                    ░██ ░██                   "<< endl;
cout << "                                                             ░███████  ░██                   "<< endl;                                                                                           
}


void mainMenu(){
  title();
  cout << "| -- Menu -- |" << endl;
  int option = 0;
  printf("1) Encrypt file\n2) Decrypt file\n3) Command line usage\n4) Quit\n");
  cout << "Please, choose an option: ";
  cin >> option;

  while(cin.fail() || (option != 1 && option!=2 && option!= 3 && option !=4)){
    cout << "Error, " << option << " is not a valid option!\n";
    cout << "Please try again: ";
    cin.clear();
    cin.ignore(1000,'\n');
    cin >> option;
  }


  switch (option) {
    case 1:
      readFromFile();
      break;
    case 2:
      break;
    case 3:
      break;
    case 4:
      printf("Quitting...\nGoodbye ;)\n");
      break;
  }


}


