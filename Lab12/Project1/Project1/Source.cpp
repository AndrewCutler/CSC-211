/* This program creates a 2D dynamic array and populates it with data read from a file */

#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

int main() {
	ifstream inFile;
	inFile.open("file.txt");	//open file

	int row = 7, col = 5;	//set size of 2D array based on number of elements in file

	double** numbers = new double*[row];	//create array of double pointers
	for (int i = 0; i < row; i++) {
		numbers[i] = new double[col];		//create new array of doubles for each pointer in original array
	}

	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			inFile >> numbers[i][j];		//read each number from file into 2D dynamic array
		}
	}

	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {		//output array contents formatted to 2 decimal places
			cout << fixed << setprecision(2) << numbers[i][j] << " ";
		}
		cout << endl;
	}

	system("pause");

	return 0;
} 
