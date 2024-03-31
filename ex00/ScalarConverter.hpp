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

void impossibleCase(void);
void specialCase(const string & param);
void charCase(char c);
void intCase(long l);
void floatCase(float f);
void doubleCase(double d);

bool is_all_digit(const string & param);
bool is_float(const string & param);
bool is_double(const string & param);


#endif
