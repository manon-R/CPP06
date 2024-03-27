#ifndef SCALAR_CONVERTER_HPP
# define SCALAR CONVERTER_HPP

#include <iostream>

using std::string;

class ScalarConverter{

public:

	static void convert(const string & param);

private:

	ScalarConverter();
	ScalarConverter(const ScalarConverter& other);
	~ScalarConverter();
	ScalarConverter& operator=(const ScalarConverter& other);

};

#endif

/*
char // Non displayable [0, 31] + 127 => display "Non displayable"

int

float // -inf, +inf and nanf

double // -inf, +inf, nan
*/