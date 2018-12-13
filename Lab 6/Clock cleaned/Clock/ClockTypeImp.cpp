#include "ClockClass.h"
#include <iostream>

using namespace std;

void clockType::setTime(int hours, int minutes, int seconds)
{
	if (0 <= hours && hours <= 23)
		hr = hours;
	else hr = 0;
	if (0 <= minutes && minutes <= 23)
		min = minutes;
	else min = 0;
	if (0 <= seconds && seconds <= 23)
		sec = seconds;
	else sec = 0;
}

void clockType::getTime(int & hours, int & minutes, int & seconds) const
{
	hours = hr;
	minutes = min;
	seconds = sec;
}

void clockType::printTime() const
{
	if (hr < 10)
		cout << "0";
	cout << hr << ":";
	if (min < 10)
		cout << "0";
	cout << min << ":";
	if (sec < 10)
		cout << "0";
	cout << sec;
}

void clockType::incrementSeconds()
{
	sec++;
	if (sec > 59)
		sec = 0;
}

void clockType::incrementMinutes()
{
	min++;
	if (min > 59)
		min = 0;
}

void clockType::incrementHours()
{
	hr++;
	if (hr > 23)
		hr = 0;
}

bool clockType::equalTime(const clockType & otherClock) const
{
	return (hr == otherClock.hr
		&& min == otherClock.min
		&& sec == otherClock.sec);
}

clockType::clockType()
{
	hr = 0;
	min = 0;
	sec = 0;
}

clockType::clockType(int hours)
{
	hr = hours;
}

clockType::clockType(int hours, int minutes, int seconds)
{
	setTime(hours, minutes, seconds);
}
