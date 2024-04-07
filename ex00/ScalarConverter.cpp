#include "ScalarConverter.hpp"

using std::cout;
using std::endl;

ScalarConverter::ScalarConverter(){}

ScalarConverter::ScalarConverter(const ScalarConverter& other){
	*this = other;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other){
	if (this == &other)
		return *this;
	return *this;
}

ScalarConverter::~ScalarConverter(){}


//getType functions

static bool is_all_digit(const string & param){
	int size = param.length();
	int minus = 0;
	for (int i = 0; i < size; i++)
	{
		if (param[i] == '-')
			minus++;
		else if ((param[i] < '0' || param[i] > '9'))
			return false;
	}
	return (minus <= 1);
}

static bool is_float(const string & param){
	int nb_f = 0;
	int nb_p = 0;
	int nb_m = 0;
	int size = param.length();

	if (param[ size - 1] != 'f')
		return false;
	for (int i = 0; i < size; i++)
	{
		if (param[i] == '-')
			nb_m++;
		else if (param[i] == '.')
			nb_p++;
		else if (param[i] == 'f')
			nb_f++;
		else if (param[i] < '0' || param[i] > '9')
			return false;
	}
	return (nb_f == 1 && nb_p == 1 && nb_m <= 1);
}

static bool is_double(const string & param){
	int nb_p = 0;
	int nb_m = 0;
	int size = param.length();

	for (int i = 0; i < size; i++)
	{
		if (param[i] == '-')
			nb_m++;
		else if (param[i] == '.')
			nb_p++;
		else if (param[i] < '0' || param[i] > '9')
			return false;
	}
	return (nb_p == 1 && nb_m <= 1);
}


//Cast and Display functions

static void charCase(char c){
	cout << "char: '" << c << "'"<< endl;
	cout << "int: " << static_cast<int>(c) << endl;
	cout << "float: " << static_cast<float>(c) << ".0f"<< endl;
	cout << "double: " << static_cast<double>(c) << ".0"<< endl;
}

static void intCase(const string& param)
{
	int i = std::atoi(param.c_str());
	if ((i >= 0 && i < 32) || i == 127)
		cout << "char: Non displayable" << endl;
	else if (i > 126 || i < 0)
		cout << "char: impossible" << endl;
	else
		cout << "char: '" << static_cast<char>(i) << "'"<< endl;
	cout << "int: " << i << endl;
	cout << "float: " << static_cast<float>(i) << ".0f" << endl;
	cout << "double: " << static_cast<double>(i) << ".0" << endl;
}

static void floatCase(float f)
{
	char sign = '\0';
	if (std::isinf(f) && f > 0)
		sign = '+';
	double d = static_cast<double>(f);
	int i = static_cast<int>(f);
	if (f != i || i > 126 || i < 0)
		cout << "char: impossible" << endl;
	else if ((i >= 0 && i < 32) || i == 127)
		cout << "char: Non displayable" << endl;
	else
		cout << "char: '" << static_cast<char>(i) << "'"<< endl;
	if (f > std::numeric_limits<int>::max() || f < std::numeric_limits<int>::min())
		cout << "int: impossible" << endl;
	else
		cout << "int: " << i << endl;
	if (i == f)
		cout << "float: " << sign << f << ".0f" <<  endl;
	else
		cout << "float: " << sign << f << "f" <<  endl;
	if (i == d)
		cout << "double: " << sign << d << ".0" << endl;
	else
		cout << "double: " << sign << d << endl;
}

static void doubleCase(double d)
{
	char sign = '\0';
	if (std::isinf(d) && d > 0)
		sign = '+';
	float f = static_cast<float>(d);
	int i = static_cast<int>(d);
	if (d != i || i > 126 || i < 0)
		cout << "char: impossible" << endl;
	else if ((i >= 0 && i < 32) || i == 127)
		cout << "char: Non displayable" << endl;
	else
		cout << "char: '" << static_cast<char>(i) << "'"<< endl;
	if (f > std::numeric_limits<int>::max() || f < std::numeric_limits<int>::min())
		cout << "int: impossible" << endl;
	else
		cout << "int: " << i << endl;
	if (i == f)
		cout << "float: " << sign << f << ".0f" <<  endl;
	else if (std::isinf(static_cast<float>(d)))
	{
		char sign = (d > 0) ? '+' : '-';
		cout << "float: " << sign << static_cast<float>(d) << endl;
	}
	else
		cout << "float: " << sign << f << "f" <<  endl;
	if (i == d)
		cout << "double: " << sign << d << ".0" << endl;
	else
		cout << "double: " << sign << d << endl;
}

static void specialCase(const string & param){
	cout << "char: impossible\nint: impossible" << endl;
	if (param == "+inf" || param == "-inf" || param == "nan")
	{
		cout << "float: " << param << "f" << endl;
		cout << "double: " << param << endl;
		return ;
	}
	cout << "float: " << param << endl;
	cout << "double: ";
	if (param == "+inff")
		cout << "+inf" << endl;
	else if (param == "-inff")
		cout << "-inf" << endl;
	else
		cout << "nan" << endl;
}

static void impossibleCase(){
	cout << "char: impossible\nint: impossible\nfloat: impossible\ndouble: impossible\n";
}



void ScalarConverter::convert(const string& param){
	if (param.empty())
		return impossibleCase();
	if (param == "nan" || param == "nanf" || param == "+inf" || param == "-inf" || param == "+inff" || param == "-inff")
		return (specialCase(param));
	else if (param.length() == 1 && param[0] > 31 && (param[0] < 48 || param[0] > 57))
		return charCase(param[0]);
	if (is_all_digit(param))
	{
 		char* endptr;
		long l = strtoll(param.c_str(), &endptr, 10);
		if (l > std::numeric_limits<int>::max() || l < std::numeric_limits<int>::min())
			return doubleCase(std::strtod(param.c_str(), &endptr));
		return intCase(param);
	}
	else if(is_float(param))
	{
		char* endptr;
		long l = strtoll(param.c_str(), &endptr, 10);
		if (l > std::numeric_limits<int>::max() || l < std::numeric_limits<int>::min())
			return doubleCase(std::strtod(param.c_str(), &endptr));
		return floatCase(atof(param.c_str()));
	}
	else if (is_double(param))
	{
		char *endptr;
		return doubleCase(std::strtod(param.c_str(), &endptr));
	}
	else
		impossibleCase();
}
