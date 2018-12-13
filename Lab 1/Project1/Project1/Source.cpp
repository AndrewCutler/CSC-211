#include <iostream>
#include <fstream>

using namespace std;

int main() {
	int number, count = 1;
	int const arraySize = 35;
	int nums[arraySize]; //declare array of specified size

	//open text file
	ifstream inFile;
	inFile.open("file.txt");

	if (!inFile) { //verify file opened properly
		cout << "File read error.";
		return 1;
	}

	//input elements from file into array
	while (!inFile.eof()) {
		for (int i = 0; i < arraySize; i++) {
			inFile >> nums[i];
		}
	}

	//check array for duplicates
	for (int i = 0; i < arraySize; i++) {
		number = nums[i]; //set element to check
		for (int j = i + 1; j < arraySize; j++) { //start check at index after element
			if (number == nums[j]) { //if another element matches, increment counter
				count++;
			}
		}
		if (count > 1) { //if there is more than one instance, output element and number of instances
			cout << nums[i] << " occurs " << count << " times.\n";
		}
		count = 1; //reset counter
	}

	//output array
	for (int i = 0; i < arraySize; i++) {
		cout << nums[i] << " ";
	}

	system("pause");

	return 0;
}
