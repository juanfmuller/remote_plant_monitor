#include <iostream>
#include <fstream>
#include <thread>
#include <chrono>
using namespace std;

int main(int argc, char **argv)
{
	ofstream file; // out file stream
	file.open("temp_values.txt");

	while(1){
		file << "73";
		file << endl;
		this_thread::sleep_for(chrono::milliseconds(2000));
	}

	file.close();
}
