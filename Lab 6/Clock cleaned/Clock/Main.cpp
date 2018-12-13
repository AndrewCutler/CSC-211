#include <iostream>
#include "ClockClass.h"

using namespace std;

int main()
{
	//declare two clocks
	clockType clockOne, clockTwo;

	//create variables for 2:15:25
	int hours = 2, minutes = 15, seconds = 25;

	cout << "Setting time for clock 1 to 02:15:25.\n";
	clockOne.setTime(hours, minutes, seconds);	//sets time on clockOne to 2:15:25
	clockOne.printTime();					//output time
	cout << "\nIncrementing seconds, minutes, and hours.\n";		//increment all values
	clockOne.incrementSeconds();
	clockOne.incrementMinutes();
	clockOne.incrementHours();
	clockOne.printTime();				//output time again
	clockOne.getTime(hours, minutes, seconds);

	cout << endl;

	hours = 15, minutes = 35, seconds = 0;
	cout << "\nSetting time for clock 2 to 15:35:0.\n";
	clockTwo.setTime(hours, minutes, seconds);		//sets time on clockTwo to 15:35:00
	clockTwo.printTime();		//output time
	cout << "\nIncrementing seconds, minutes, and hours.\n";		//increment all values
	clockTwo.incrementSeconds();
	clockTwo.incrementMinutes();
	clockTwo.incrementHours();
	clockTwo.printTime();			//output time again
	clockTwo.getTime(hours, minutes, seconds);

	cout << "\nInvoking method to check if they're equal: ";
	cout << clockOne.equalTime(clockTwo);	//check if clockOne and clockTwo are equal and output 0 for false

	system("pause");

	return 0;
}