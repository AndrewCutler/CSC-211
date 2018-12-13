/*
This program accepts 4-digit hex numbers from a file and outputs their sum in base 10.
*/

#include <iostream>
#include <cmath>
#include <fstream>

using namespace std;

int hDigitToDec(char);

int main() {
	//open hex file to read numbers from
	ifstream inFile;
	inFile.open("hex.txt");

	if (!inFile.is_open()) {
		cout << "Error reading file.";
		return 1;
	}

	int const hexSize = 4; //sets size of hex number

	char hex[hexSize];
	int dec = 0, decSum = 0, exponent = 0;

	//pull each hex number from the file and convert to decimal, then sum them
	cout << "We will retrieve the values from the file and add them.\n";
	while (!inFile.eof()) {
		inFile >> hex; //grab each hex number
		//calculate value of hex numbers in decimal, working from most significant bit to least
		for (int i = hexSize - 1; i >= 0; i--) {
			dec += (hDigitToDec(hex[i]) * (pow(16, exponent)));	//add value of each hex digit in decimal
			exponent++;
		}

		decSum += dec;		//add decimal total value of each hex number to decimal total
		dec = 0, exponent = 0;		//reset dummy decimal variable and exponent

	}

	//output sum in decimal
	cout << "The sum of the hexadecimal numbers in the file in decimal form is " << decSum << "." << endl;

	system("pause");

	return 0;
}

//convert hex digit to its decimal value and output that value as an int
int hDigitToDec(char hexNum) {
	switch (hexNum) {
	case '0':
		return 0;
		break;
	case '1':
		return 1;
		break;
	case '2':
		return 2;
		break;
	case '3':
		return 3;
		break;
	case '4':
		return 4;
		break;
	case '5':
		return 5;
		break;
	case '6':
		return 6;
		break;
	case '7':
		return 7;
		break;
	case '8':
		return 8;
		break;
	case '9':
		return 9;
		break;
	case 'A':
		return 10;
		break;
	case 'B':
		return 11;
		break;
	case 'C':
		return 12;
		break;
	case 'D':
		return 13;
		break;
	case 'E':
		return 14;
		break;
	case 'F':
		return 15;
		break;
	case 'a':
		return 10;
		break;
	case 'b':
		return 11;
		break;
	case 'c':
		return 12;
		break;
	case 'd':
		return 13;
		break;
	case 'e':
		return 14;
			break;
	case 'f':
		return 15;
		break;
	default:
		break;
	}
}

