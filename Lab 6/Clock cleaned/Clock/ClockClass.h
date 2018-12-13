#pragma once
#ifndef CLOCKCLASS_H
#define CLOCKCLASS_H

class clockType {
public:
	void setTime(int, int, int);	//sets time for clock object
	void getTime(int&, int&, int&) const;	//returns time that is set on clock object
	void printTime() const;		//outputs time on clock
								//increment s, m, h by 1
	void incrementSeconds();
	void incrementMinutes();
	void incrementHours();

	bool equalTime(const clockType&) const;		//checks if two clocks have the same time
	clockType();		//default constructor
	clockType(int);		//constructor that sets hour only to 0
	clockType(int, int, int);	//constructor that sets hour, minute and second to 0

private:
	int hr;		//hour value
	int min;	//minute value
	int sec;	//second value
};

#endif