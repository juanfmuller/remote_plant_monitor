#include <iostream>
#include <fstream>
#include <thread>
#include <chrono>
using namespace std;

int main(int argc, char **argv)
{
	ofstream file; // out file stream
	file.open("C:/Users/JFMuller/Documents/Projects/remote_plant_monitor/frontend/QTSource/temp_values.txt");
  ofstream file2; // out file stream
	file2.open("C:/Users/JFMuller/Documents/Projects/remote_plant_monitor/frontend/QTSource/humidity_values.txt");
  int counter = 70;
  int flag = 1;

  int counter2 = 40;
  int flag2 = 1;
	while(1){
    if(flag){
      counter++;
      if(counter == 90) flag = !flag;
    } else if (!flag){
      counter--;
      if(counter == 70) flag = !flag;
    }

    std::string s = std::to_string(counter);
		file << s;
		file << endl;

    if(flag2){
      counter2++;
      if(counter2 == 60) flag2 = !flag2;
    } else if (!flag){
      counter2--;
      if(counter2 == 40) flag2 = !flag2;
    }

    std::string ss = std::to_string(counter2);
		file2 << ss;
		file2 << endl;


		this_thread::sleep_for(chrono::milliseconds(2500));
	}

	file.close();
}
