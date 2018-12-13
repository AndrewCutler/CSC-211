#include <iostream>
#include <fstream>

using namespace std;

int main() {
	ifstream inFile;
	inFile.open("temp.txt");		//open file with temperatures

	if (!inFile.is_open()) {		//make sure file is read properly
		cout << "Error reading file.";
		return 1;
	}

	double averageTemp = 0;				//create variable for average temperature

	int numDays;					//read first line of file to determine array size
	inFile >> numDays;

	int* Temperature = new int(numDays);		//create dynamic array of proper size

	for (int i = 0; i < numDays; i++) {			//populate array with values
		inFile >> *Temperature;
		averageTemp += *Temperature;			//add temps to averageTemp variable
		Temperature++;							//increment pointer
	}

	Temperature -= numDays;						//return pointer to its original location

	averageTemp = averageTemp / numDays;		//divide sum of temps by number of temps to find avg

	cout << averageTemp << "\n";				//output average temperature

	//delete Temperature;						//causes error?

	system("pause");

	return 0;
}