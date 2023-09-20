#include <iostream>
#include <iomanip>

int main() {

	const std::string studentData = "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY";


	std::cout << std::setw(10) << std::left << "ID " << std::setw(20) << std::left << "| First Name "
		<< std::setw(20) << std::left << "| Last Name " << std::setw(20) << std::left << "| Email Address "
		<< std::setw(10) << std::left << "| Age " << std::setw(20) << std::left << "| Days in Courses "
		<< std::setw(20) << std::left << "| Degree Program " << std::endl;
	std::cout << "------------------------------------------------------------------------------------------------------------------------\n";

}	