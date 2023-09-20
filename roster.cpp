/*
*	Yelredda
*	C867 Scripting and Programming - Applications
*	roster.h
*
*	Code file implementing Roster class defined in roster.h
*
*	Create an array of pointers, classRosterArray, to hold the data provided in the “studentData Table.”
*
*	Create a student object for each student in the data table and populate classRosterArray.
*		Parse each set of data identified in the “studentData Table.”
*		Add each student object to classRosterArray.
*
*	Define the following functions:
*
*		public void add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeprogram)
* 			that sets the instance variables from part D1 (student.cpp) and updates the roster.
*
*		public void remove(string studentID)
*			that removes students from the roster by student ID. If the student ID does not exist, the function prints an error message indicating that the student was not found.
*
*		public void printAll()
* 			that prints a complete tab-separated list of student data in the provided format: A1 [tab] First Name: John [tab] Last Name: Smith [tab] Age: 20 [tab]daysInCourse: {35, 40, 55} Degree Program: Security. The printAll() function should loop through all the students in classRosterArray and call the print() function for each student.
*
*		public void printAverageDaysInCourse(string studentID)
* 			that correctly prints a student’s average number of days in the three courses. The student is identified by the studentID parameter.
*
*		public void printInvalidEmails()
*			that verifies student email addresses and displays all invalid email addresses to the user.
*			Note: A valid email should include an at sign ('@') and period ('.') and should not include a space (' ').
*
*		public void printByDegreeProgram(DegreeProgram degreeProgram)
* 			that prints out student information for a degree program specified by an enumerated type.
*
*
*/

#include "roster.h"
#include "student.h"
#include "degree.h"
#include <string>
#include <iostream>	
#include <iomanip>

// Roster class constructor
Roster::Roster() {
	for (int i = 0; i < rosterArraySize; i++) {
		classRosterArray[i] = NULL;
	}
}

// Roster class deconstructor
Roster::~Roster() {
	for (int i = 0; i < rosterArraySize; i++) {
		delete classRosterArray[i];
		classRosterArray[i] = NULL;
	}
}

// Needed to parse the original student strings into useful data for initializing the Student class instances
void Roster::parseData(std::string studentData) {

	int stringCommaIndex, stringIndex;

	stringCommaIndex = studentData.find(",");
	std::string studentID = studentData.substr(0, stringCommaIndex);

	stringIndex = stringCommaIndex + 1;
	stringCommaIndex = studentData.find(",", stringIndex);
	std::string firstName = studentData.substr(stringIndex, stringCommaIndex - stringIndex);

	stringIndex = stringCommaIndex + 1;
	stringCommaIndex = studentData.find(",", stringIndex);
	std::string lastName = studentData.substr(stringIndex, stringCommaIndex - stringIndex);

	stringIndex = stringCommaIndex + 1;
	stringCommaIndex = studentData.find(",", stringIndex);
	std::string emailAddress = studentData.substr(stringIndex, stringCommaIndex - stringIndex);

	stringIndex = stringCommaIndex + 1;
	stringCommaIndex = studentData.find(",", stringIndex);
	int age = std::stoi(studentData.substr(stringIndex, stringCommaIndex - stringIndex));

	stringIndex = stringCommaIndex + 1;
	stringCommaIndex = studentData.find(",", stringIndex);
	int daysInCourse1 = std::stoi(studentData.substr(stringIndex, stringCommaIndex - stringIndex));

	stringIndex = stringCommaIndex + 1;
	stringCommaIndex = studentData.find(",", stringIndex);
	int daysInCourse2 = std::stoi(studentData.substr(stringIndex, stringCommaIndex - stringIndex));

	stringIndex = stringCommaIndex + 1;
	stringCommaIndex = studentData.find(",", stringIndex);
	int daysInCourse3 = std::stoi(studentData.substr(stringIndex, stringCommaIndex - stringIndex));

	stringIndex = stringCommaIndex + 1;
	std::string degree = studentData.substr(stringIndex, studentData.length() - stringIndex);

	DegreeProgram degreeProgram;

	if (degree == "SECURITY") { degreeProgram = SECURITY; }
	else if (degree == "NETWORK") { degreeProgram = NETWORK; }
	else if (degree == "SOFTWARE") { degreeProgram = SOFTWARE; }

	add(studentID, firstName, lastName, emailAddress, age, daysInCourse1, daysInCourse2, daysInCourse3, degreeProgram);
}

// Replacement for having to write this line repeatedly, decided to make a more formal header:
//	std::cout << "Student ID \t First Nam \t Last Name \t Email \t Age \t Days in Course \t Degree Program" << std::endl;
void Roster::printHeader() {

	std::cout << std::setw(5) << std::left << "ID " << std::setw(15) << std::left << "| First Name "
		<< std::setw(20) << std::left << "| Last Name " << std::setw(27) << std::left << "| Email Address "
		<< std::setw(12) << std::left << "| Age " << std::setw(20) << std::left << "| Days in Courses "
		<< std::setw(20) << std::left << "| Degree Program " << std::endl;
	std::cout << "------------------------------------------------------------------------------------------------------------------------" << std::endl << std::endl;
}

//	public void add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeprogram)
//		sets the instance variables from part D1(student.cpp) and updates the roster.
//
//	Current logic finds the first NULL pointer and adds the student record there.
void Roster::add(std::string studentID, std::string firstName, std::string lastName, std::string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram) {

	bool studentAdded = false; 
	int i = 0;

	do {
		if (classRosterArray[i] == NULL) {
			classRosterArray[i] = new Student(studentID, firstName, lastName, emailAddress, age, daysInCourse1, daysInCourse2, daysInCourse3, degreeProgram);
			studentAdded = true;
		}

		i++;

	} while (studentAdded == false && i < rosterArraySize );

	if (!studentAdded) { std::cout << "ERROR adding student to roster. \n"; }
}

//	public void remove(string studentID)
//		removes students from the roster by student ID.If the student ID does not exist, the function prints an error message indicating that the student was not found.
//	
//	Assumes studentID doesn't exist
//	Current logic finds the student, removes the entry, and then moves the remaining students up one index.
void Roster::remove(std::string studentID) {

	bool studentIDFound = false;

	for (int i = 0; i < rosterArraySize; i++) {
		if (classRosterArray[i] != NULL) {
			if (classRosterArray[i]->getStudentID() == studentID) {
				studentIDFound = true;

				// Delete the pointer for the entry
				// delete classRosterArray[i];
				classRosterArray[i] = NULL;

				
				for (int j = i; j < rosterArraySize - 1; j++) {
					classRosterArray[j] = classRosterArray[j + 1]; // Move each entry into the previous entry; for condition should prevent index OOB issues
				}

				// Final cleanup; at this point there should be duplicate values at classRosterArray[rosterArraySize-1] and classRosterArray[rosterArraySize-2]
				// from the shift. Setting classRosterArray[rosterArraySize-1] = NULL removes the old Student instance.

				classRosterArray[rosterArraySize - 1] = NULL; 

				std::cout << "Student " << studentID << " successfully removed." << std::endl;
			}
		}
	}

	if (!studentIDFound) { std::cout << "Student ID " << studentID << " not found." << std::endl; }
}

//	public void Roster::printAll()
//		that prints a complete tab - separated list of student data in the provided format : 
//		A1[tab] First Name : John[tab] Last Name : Smith[tab] Age : 20[tab]daysInCourse : {35, 40, 55} Degree Program : Security
// 
//	The printAll() function loops through all the students in classRosterArray and call the print() function for each student.
void Roster::printAll() {
	
	printHeader(); 

	for (int i = 0; i < rosterArraySize; i++) {
		if (classRosterArray[i] != NULL) { classRosterArray[i]->print(); }
	}
}

//	public void printAverageDaysInCourse(string studentID)
//		prints a student’s average number of days in the three courses. The student is identified by the studentID parameter.
// 
//	Assumes studentID doesn't exist
void Roster::printAverageDaysInCourse(std::string studentID) {

	bool studentIDFound = false;

	for (int i = 0; i < rosterArraySize; i++) {
		if (classRosterArray[i] != NULL) {
			if (classRosterArray[i]->getStudentID() == studentID) {

				studentIDFound = true;

				double average = (classRosterArray[i]->getDaysInCourse()[0] + classRosterArray[i]->getDaysInCourse()[1] + classRosterArray[i]->getDaysInCourse()[2]) / 3.0;

				std::cout << studentID << " average days in courses: " << average << " days." << std::endl;
			}
		}
	}

	if (!studentIDFound) { std::cout << "Student ID " << studentID << " not found." << std::endl; }

}

//	public void printInvalidEmails()
//		verifies student email addresses and displays all invalid email addresses to the user.
//		Note: A valid email should include an at sign('@') and period('.') and should not include a space(' ').
void Roster::printInvalidEmails() {

	std::cout << "\nInvalid email addresses:" << std::endl;

	bool invalidEmailFound = false;

	for (int i = 0; i < rosterArraySize; i++) {
		if (classRosterArray[i] != NULL) {
			std::string studentEmail = classRosterArray[i]->getEmailAddress();

			// Find chars '@' '.' and ' '; if '@' or '.' don't exist, invalid. if ' ' exists, invalid. 
			// Default assumption is that all email addresses are valid; conditionals disprove
			if (studentEmail.find('@') == std::string::npos) {
				invalidEmailFound = true;
				std::cout << classRosterArray[i]->getStudentID() << " : " << classRosterArray[i]->getEmailAddress() << " is invalid (missing @)." << std::endl;
			}
			else if (studentEmail.find('.') == std::string::npos) {
				invalidEmailFound = true;
				std::cout << classRosterArray[i]->getStudentID() << " : " << classRosterArray[i]->getEmailAddress() << " is invalid (missing .)." << std::endl;
			}
			else if (studentEmail.find(' ') != std::string::npos) {
				invalidEmailFound = true;
				std::cout << classRosterArray[i]->getStudentID() << " : " << classRosterArray[i]->getEmailAddress() << " is invalid (has a space)." << std::endl;
			}
		}
	}

	if (!invalidEmailFound) { std::cout << "No invalid email addresses found."; };
}

//	public void printByDegreeProgram(DegreeProgram degreeProgram)
//	that prints out student information for a degree program specified by an enumerated type.
void Roster::printByDegreeProgram(DegreeProgram degreeProgram) {

	std::cout << "\nStudents in the " << degreeProgramName[degreeProgram] << " degree program: " << std::endl;

	printHeader();
	
	for (int i = 0; i < rosterArraySize; i++) {
		if (classRosterArray[i] != NULL) {
			if (classRosterArray[i]->getDegreeProgram() == degreeProgram) {
				classRosterArray[i]->print();
			}
		}
	}
}