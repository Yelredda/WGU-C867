/*
*	Yelredda
*	C867 Scripting and Programming - Applications
*	student.cpp
*
*	Code file implementing Student class defined in student.h
* 
*	Create the class Student  in the files student.h and student.cpp, which includes each of the following variables:
* 		student ID
* 		first name
* 		last name
* 		email address
* 		age
* 		array of number of days to complete each course
* 		degree program
*
*	Create each of the following functions in the Student class:
* 		an accessor (i.e., getter) for each instance variable from part D1
* 		a mutator (i.e., setter) for each instance variable from part D1
* 		All external access and changes to any instance variables of the Student class must be done using accessor and mutator functions.
* 		constructor using all of the input parameters provided in the table
* 		print() to print specific student data
*
* Sample Line: 
* const string studentData[] = 
	{"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY", 
	"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK", 
	"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE", 
	"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY", 
	"A5,[firstname],[lastname],[emailaddress],[age], [numberofdaystocomplete3courses],SOFTWARE"} 
*
*/

#include "student.h"
#include "degree.h"
#include <string>
#include <iostream>
#include <iomanip>

// Accessor functions
std::string Student::getStudentID() { return this->studentID; };
std::string Student::getFirstName() { return this->firstName; };
std::string Student::getLastName() { return this->lastName; };
std::string Student::getEmailAddress() { return this->emailAddress; };
int Student::getAge() { return this->age; };
int* Student::getDaysInCourse() { return this->daysInCourse; };
DegreeProgram Student::getDegreeProgram() { return this->degreeProgram; };

// Mutator functions
void Student::setStudentID(std::string studentID) { this->studentID = studentID; };
void Student::setFirstName(std::string firstName) { this->firstName = firstName; };
void Student::setLastName(std::string lastName) { this->lastName = lastName; };
void Student::setEmailAddress(std::string emailAddress) { this->emailAddress = emailAddress; };
void Student::setAge(int age) { this->age = age; };
void Student::setDaysInCourse(int daysInCourse1, int daysInCourse2, int daysInCourse3) { this->daysInCourse[0] = daysInCourse1; this->daysInCourse[1] = daysInCourse2; this->daysInCourse[2] = daysInCourse3; }
void Student::setDegreeProgram(DegreeProgram degreeProgram) { this->degreeProgram = degreeProgram; };

// Constructor
Student::Student(std::string studentID, std::string firstName, std::string lastName, std::string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram) {
	this->studentID = studentID;
	this->firstName = firstName;
	this->lastName = lastName;
	this->emailAddress = emailAddress;
	this->age = age;
	this->daysInCourse[0] = daysInCourse1; 
	this->daysInCourse[1] = daysInCourse2; 
	this->daysInCourse[2] = daysInCourse3;
	this->degreeProgram = degreeProgram;
}

// Deconstructor... Empty because I don't think there's anything to clean up
Student::~Student() { }

// Prints information stored in class in a tab-separated line. 
void Student::print() {

	/* Original print statement, cleaning up to align with new printHeader function
	std::cout << this->studentID << "\t" << this->firstName << "\t" << this->lastName << "\t" << this->emailAddress << "\t" << 
		this->age << "\t" << this->daysInCourse[0] << "," << this->daysInCourse[1] << "," << this->daysInCourse[2] << "\t" << 
		degreeProgramName[this->degreeProgram] << std::endl;
	
		std::cout << std::setw(10) << std::left << "ID " << std::setw(20) << std::left << "| First Name "
		<< std::setw(20) << std::left << "| Last Name " << std::setw(20) << std::left << "| Email Address "
		<< std::setw(10) << std::left << "| Age " << std::setw(20) << std::left << "| Days in Courses "
		<< std::setw(20) << std::left << "| Degree Program " << std::endl;
	
	*/

	// Roundabout way to make outputting the days easier
	std::string courseDays = std::to_string(this->daysInCourse[0]) + " , " + std::to_string(this->daysInCourse[1]) + 
		" , " + std::to_string(this->daysInCourse[2]);

	std::cout << std::setw(5) << std::left << this->studentID << "| " << std::setw(13) << std::left << this->firstName
		<< "| " << std::setw(18) << std::left << this->lastName << "| " << std::setw(25) << std::left << this->emailAddress
		<< "| " << std::setw(10) << std::left << this->age << "| " << std::setw(18) << std::left << courseDays
		<< "| " << std::setw(15) << std::left << degreeProgramName[this->degreeProgram] << std::endl;

}
