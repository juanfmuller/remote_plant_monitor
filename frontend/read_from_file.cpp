#include <iostream>
#include <fstream>
#include <string>
#include <thread>
#include <chrono>
#include <vector>

using namespace std;

int main(){
  ifstream file;
  file.open("C:/Users/JFMuller/Documents/software_final/server/temp_values.txt");
  vector<string> vect;
  string line;
  int i = 0;
  while(getline(file, line)){
    vect.push_back(line);
    cout<< "1." << vect[i] << "\n";
    ++i;
    this_thread::sleep_for(chrono::milliseconds(1000));
  }
}