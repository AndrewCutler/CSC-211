/*
	This program converts a a decimal input to its representation in a specified base, up
	to base 16.
*/

#include <iostream>

using namespace std;

void baseConverter(int, int);
char numToAlpha(int,int);

int main() {
	int input;
	cout << "Enter a decimal number to convert: ";
	cin >> input;

	int base;
	cout << "Enter the base to convert to: ";
	cin >> base;

	baseConverter(input, base);

	system("pause");
}

//recursively converts each digit in the input to its corresponding representation in the given base
void baseConverter(int in, int b) {

	if (in > (b - 1)) {
		baseConverter(in/b, b);
		cout << numToAlpha(in,b);
	}

	else
		cout << numToAlpha(in, b);
}

//accepts an integer and its desired base as inputs and outputs the conversion as a char
char numToAlpha(int number, int base) {
	switch (number % base) {
	case 0:
		return '0';
		break;
	case 1:
		return '1';
		break;
	case 2:
		return '2';
		break;
	case 3:
		return '3';
		break;
	case 4:
		return '4';
		break;
	case 5:
		return '5';
		break;
	case 6:
		return '6';
		break;
	case 7:
		return '7';
		break;
	case 8:
		return '8';
		break;
	case 9:
		return '9';
		break;
	case 10:
		return 'A';
		break;
	case 11:
		return 'B';
		break;
	case 12:
		return 'C';
		break;
	case 13:
		return 'D';
		break;
	case 14:
		return 'E';
		break;
	case 15:
		return 'F';
		break;
	}
}

