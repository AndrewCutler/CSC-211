#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct studentType {
	char name[26];
	double gpa;
	int sID;
	char grade;
};

int main() {

	//declare and open files
	ifstream nameFile, gpaFile, sIDFile, gradeFile;

	nameFile.open("../name.txt");
	gpaFile.open("../gpa.txt");
	sIDFile.open("../sid.txt");
	gradeFile.open("../grade.txt");

	//verify all files open properly
	if (!nameFile.is_open()) {
		cout << "Error reading name file.\n";
		return 1;
	}
	if (!gpaFile.is_open()) {
		cout << "Error reading GPA file.\n";
		return 2;
	}
	if (!sIDFile.is_open()) {
		cout << "Error reading student ID file.\n";
		return 3;
	}
	if (!gradeFile.is_open()) {
		cout << "Error reading grade file.\n";
		return 3;
	}

	//initialize size of array
	int arraySize = 0;
	//dummy var
	string str;

	//prompt instructor for number of students in the class
	cout << "Please enter the number of students in the class: ";
	cin >> arraySize;

	//return to start of file after eof flag set
	nameFile.clear();
	nameFile.seekg(0, ios::beg);

	//declare array of studentType objects with proper size
	studentType* studentArray;
	studentArray = new studentType[arraySize];

	//populate each studentType with name from file
	for (int i = 0; i < arraySize; i++) {
		nameFile.getline(studentArray[i].name,26);
	}

	//populate each studentType with gpa from file
	for (int i = 0; i < arraySize; i++) {
		gpaFile >> studentArray[i].gpa;
	}

	//populate each studentType with name from file
	for (int i = 0; i < arraySize; i++) {
		sIDFile >> studentArray[i].sID;
	}

	//populate each studentType with name from file
	for (int i = 0; i < arraySize; i++) {
		gradeFile >> studentArray[i].grade;
	}

	//output all data collected from files
	for (int i = 0; i < arraySize; i++) {
		cout << "Student " << i + 1 << ":\n";
		cout << "Name: " << studentArray[i].name << "\n";
		cout << "GPA: " << studentArray[i].gpa << "\n";
		cout << "Student ID: " << studentArray[i].sID << "\n";
		cout << "Grade: " << studentArray[i].grade << "\n\n";
	}

	//output all data backwards
	for (int i = arraySize; i > 0; i--) {
		cout << "Student " << i << ":\n";
		cout << "Name: " << studentArray[i - 1].name << "\n";
		cout << "GPA: " << studentArray[i - 1].gpa << "\n";
		cout << "Student ID: " << studentArray[i - 1].sID << "\n";
		cout << "Grade: " << studentArray[i - 1].grade << "\n\n";
	}

	system("pause");

	return 0;
}