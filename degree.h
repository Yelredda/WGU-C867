/*
* Yelredda
* C867 Scripting and Programming - Applications
* degree.h
*
*	Define an enumerated data type DegreeProgram for the degree programs containing the data type values SECURITY, NETWORK, and SOFTWARE.
*		Note: This information should be included in the degree.h file.
* 
* 
*/

#pragma once
#include <string>

enum DegreeProgram { SECURITY, NETWORK, SOFTWARE };

// enum outputs 0-2; string type to translate that to a string value
static const std::string degreeProgramName[] = { "SECURITY", "NETWORK", "SOFTWARE" }; 