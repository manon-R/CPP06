#ifndef SCALAR_CONVERTER_HPP
# define SCALAR CONVERTER_HPP

#include <iostream>
#include <cstdlib>
#include <climits>
#include <cmath>

//INT_MIN INT_MAX
//-std::numeric_limits<float>::min() std::numeric_limits<float>::max()
//-std::numeric_limits<double>::min() std::numeric_limits<double>::max()

using std::string;

class ScalarConverter{

public:

	static void convert(const string & param);

private:

	ScalarConverter();
	ScalarConverter(const ScalarConverter& other);
	~ScalarConverter();
	ScalarConverter& operator=(const ScalarConverter& other);

	void impossibleCase(void);

};

bool is_all_digit(const string & param);
bool is_float(const string & param);

#endif
