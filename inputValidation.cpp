/*
-----------------------------------------------------------------------------------
File name     : inputValidation.cpp
Authors       : Leandro Saraiva Maia
Creation date : 22.11.2021

Description   : See header comment of the .h file
Remark(s)     :

Compiler      : Mingw-w64 g++ 11.1.0
-----------------------------------------------------------------------------------
*/

#include <iostream> // required for cout
#include <limits>   // used to empty the buffer (<streamsize>::max())

using namespace std;

unsigned getInput(const unsigned min, const unsigned max) {
	bool     error;
	unsigned userInput;

	do {
		cin >> userInput;

		error = cin.fail() || userInput < min || userInput > max;
		if (error) {
			cout << "Please only enter a number between "
			     << min << " and " << max << endl;
			cin.clear();
		}

		cin.ignore(numeric_limits<streamsize>::max(), '\n'); // empty buffer

	} while(error);

	return userInput;
}