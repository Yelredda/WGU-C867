/*
*	Yelredda
*	C867 Scripting and Programming - Applications
*	main.cpp
*
*	Demonstrate the program’s required functionality by adding a main() function in main.cpp, which will contain the required function calls to achieve the following results:
*
*	Print out to the screen, via your application, the course title, the programming language used, your WGU student ID, and your name.
*
*	Create an instance of the Roster class called classRoster.
*
*	Add each student to classRoster.
* 
*	Convert the following pseudo code to complete the rest of the  main() function:
* 		classRoster.printAll();
* 		classRoster.printInvalidEmails();
*
*	Loop through classRosterArray and for each element:
* 		classRoster.printAverageDaysInCourse(**current_object's student id**);
*		Note: For the current_object's student id, use an accessor (i.e., getter) for the classRosterArray to access the student id.
*
*	classRoster.printByDegreeProgram(SOFTWARE);
*
*	classRoster.remove("A3");
*
*	classRoster.printAll();
*
*	classRoster.remove("A3");
*		//expected: the above line should print a message saying such a student with this ID was not found.
*
*   Implement the destructor to release the memory that was allocated dynamically in Roster.
*
*
*/

#include <iostream>
#include <string>
#include "roster.h"
#include "student.h"
#include "degree.h"


/*** Beginning of main() program logic ***/

int main() {

	const std::string studentData[] =
	{ "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
	"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
	"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
	"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
	"A5,Mr,Yelredda,Yelredda@Yelredda.org,37,21,22,23,SOFTWARE" };

	const int numStudents = 5;

	std::cout << "C867: Scripting & Programming - Applications \n" << "Programming language: C++ \n" << "Yelredda" << std::endl << std::endl;

	Roster classRoster;

	// Parse data in studentData array, adds each Student record to classRoster
	for (int i = 0; i < numStudents; i++) {
		classRoster.parseData(studentData[i]);
	}

	// Print the entire class roster and invalid emails
	classRoster.printAll();
	classRoster.printInvalidEmails();

	// Average function call
	std::cout << "\nCalculating average days in course for each student: " << std::endl;
	for (int i = 0; i < numStudents; i++) {
		classRoster.printAverageDaysInCourse( classRoster.classRosterArray[i]->getStudentID() );
	}

	// Print by degree function
	classRoster.printByDegreeProgram(SOFTWARE);

	// Remove A3, print the entire class again to confirm A3 has been removed, retry remove A3 to confirm that it's not found
	std::cout << "\nAttempting to remove A3: " << std::endl;
	classRoster.remove("A3");

	std::cout << "\nPrinting roster to confirm A3 has been removed: " << std::endl;
	classRoster.printAll();

	std::cout << "\nAttempting to remove A3 again: " << std::endl;
	classRoster.remove("A3");

	return 0;
 }

/*** End of main() program logic ***/