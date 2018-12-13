/*
this program reads student names and their grades from a file and outputs the data in a specific format, including each grade, each student's average, and the class average
TO DO: generalize program for indeterminate number of students (arrays require const ints)
*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

const int numOfGrades = 4, numOfStudents = 7;							 //set number of grades for each student and number of total students

struct student {
	string studentName;			//student's name
	int studentGrades[numOfGrades];		//array containing each grade
	double studentAvg;			//student's average score
	int studentGradeSum = 0;		//cumulative total of student's grades added together (for calculating average)
};

int main() {
	int gradeCount = 0, classGradeSum = 0;								//variables for count of grades input and sum of all grades, respectively

	ifstream inFile;
	inFile.open("..//file.txt");										//open file

	student students[numOfStudents];									//declare array of students
			
	if (!inFile) {														//throw error if file doesn't open
		cout << "Error reading file.";
		return 1;
	}

	while (!inFile.eof()) {												//get student names and grades
		for (int i = 0; i < numOfStudents; i++) {	
			inFile >> students[i].studentName;						//input name for each student
			for (int j = 0; j < numOfGrades; j++) {
				inFile >> students[i].studentGrades[j];				//populate array for each student with each grade
				students[i].studentGradeSum += students[i].studentGrades[j];		//add that grade to student's cumulative total
				gradeCount++;				//increment counter for number of grades entered
				classGradeSum += students[i].studentGrades[j];			//add each grade to total for entire class
			}
			students[i].studentAvg = students[i].studentGradeSum / numOfGrades;		//calculate average grade for each student
		}
	}

	for (int i = 0; i < numOfStudents; i++) {							//output data
		cout << students[i].studentName << "'s grades:\n";			//student name
		for (int j = 0; j < numOfGrades; j++) {						//each grade
			cout << students[i].studentGrades[j] << " ";
		}
		//output average grade
		cout << "\n" << students[i].studentName << "'s average grade:\n" << students[i].studentAvg << "\n";
		cout << "\n";
	}

	double classAvg = classGradeSum / gradeCount;						//calculate class average

	cout << "Class average grade: " << classAvg << endl;				//output class average	

	system("pause");

	return 0;
}