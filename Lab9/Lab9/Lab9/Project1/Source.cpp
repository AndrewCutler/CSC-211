/*
	recFun accepts an int and an int pointer as inputs, then outputs each digit of that int on a newline
	while summing each digit into the pointer variable. recFun is wrapped by startRec which calls recFun
	and then outputs the sum of those digits.
*/

#include <fstream>
#include <iostream>

using namespace std;

void recFun(int,int*);
void startRec(int, int*);

int main() {
	int sum = 0;	//store sum of digits of input
	int input;		//hold input read from file
	int* p;			//pointer to update sum from within recursive function
	p = &sum;

	//open input file
	fstream inFile;
	inFile.open("numbers.txt");

	//make sure file is readable
	if (!inFile.is_open()) {
		cout << "Cannot read file.";
		return 1;
	}

	//iterate over numbers in file
	while (!inFile.eof()) {
		inFile >> input;
		startRec(input, p);
		cout << endl;
		*p = 0;			//clear sum variable after each number
	}

	system("pause");

	return 0;
}

//recursive function to print each digit of input on a new line and sum all digits
void recFun(int x, int* y) {

	if (x >= 10) {
		recFun((x / 10),y);
		cout << x % 10 << endl;
		*y += x % 10;	
	}

	else {
		*y += x;
		cout << x << endl;
	}

}

//function that calls recursive function and outputs sum just once, at the end of recursive function call
void startRec(int x, int* y) {
	recFun(x, y);

	cout << *y << endl;
}
