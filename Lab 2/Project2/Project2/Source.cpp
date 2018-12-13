#include <iostream>
#include <fstream>
#include <string>

/*
This program reads student names' and their corresponding grades from a file and outputs that information
in a tabular format
*/

using namespace std;

int main() {
	ifstream inFile;
	inFile.open("..//file.txt");
	string studentNames[7];
	int studentGrades[7][5];

	if (!inFile) { //if file isn't open properly, throw error
		cout << "File read error.";
		return 1;
	}
	
	for (int i = 0; i < 7; i++) {
		inFile >> studentNames[i];		//input student names into array
		for (int j = 0; j < 5; j++) {
			inFile >> studentGrades[i][j]; //input next five elements (grades) into grades array
		}
	}
		
	for (int i = 0; i < 7; i++) {
		cout << studentNames[i] << ": "; //output student names formatted
		for (int j = 0; j < 5; j++) {
			cout << studentGrades[i][j] << " "; //output grades
		}
		cout << endl; //output new line to create rows
	}

	inFile.close(); //close file

	system("pause");

	return 0;

}