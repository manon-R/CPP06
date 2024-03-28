#include "ScalarConverter.hpp"
#include <iostream>

using std::string;
using std::cout;
using std::endl;

int main(int argc, char **argv){

	if (argc != 2)
	{
		cout << "A string representation of a C++ literal required" << endl;
		return 0;
	}

	ScalarConverter::convert(argv[1]);
}