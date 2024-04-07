#ifndef SCALAR_CONVERTER_HPP
# define SCALAR CONVERTER_HPP

#include <iostream>
#include <cstdlib>
#include <limits>
#include <cmath>


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
