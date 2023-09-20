/* 
*	Yelredda
*	C867 Scripting and Programming - Applications
*	student.h
* 
*	Header file containing definitions for the Student class implemented in student.cpp
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
*
*/

#pragma once
#include <string>
#include "degree.h"

class Student {
	private:
		// Private variables, to be accessed by set/get functions
		const static int daysArraySize = 5; // Assign to const to avoid rewriting everywhere
		std::string studentID, firstName, lastName, emailAddress;
		int age, daysInCourse[daysArraySize];
		DegreeProgram degreeProgram;

	public:
		// Constructor 
		Student(std::string studentID, std::string firstName, std::string lastName, std::string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram);
		~Student();

		// Accessor functions
		std::string getStudentID();
		std::string getFirstName();
		std::string getLastName();
		std::string getEmailAddress();
		int getAge();
		int* getDaysInCourse(); 
		DegreeProgram getDegreeProgram();

		// Mutator functions
		void setStudentID(std::string studentID);
		void setFirstName(std::string firstName);
		void setLastName(std::string lastName);
		void setEmailAddress(std::string emailAddress);
		void setAge(int age);
		void setDaysInCourse(int daysInCourse1, int daysInCourse2, int daysInCourse3);
		void setDegreeProgram(DegreeProgram degreeProgram);

		// Class operations
		void print();
};