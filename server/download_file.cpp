#include <iostream>
#include <thread>
#include <chrono>

using namespace std;

int main(){
  while(1){
    system("pscp -pw \"raspberry\" pi@192.168.0.23:/home/pi/Desktop/software_final/temp_values.txt C:/Users/JFMuller/Documents/software_final");
    this_thread::sleep_for(chrono::milliseconds(5000));
  }
}