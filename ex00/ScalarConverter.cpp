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

void impossibleCase(){
	cout << "char: impossible\nint: impossible\nfloat: impossible\ndouble: impossible\n";
}

void ScalarConverter::convert(const string& param){
	if (param.empty())
	{
		impossibleCase();
		return ;
	}
	if (param.length() == 1 && (param[0] < '0' || param[0] > '9')) // Char type
	{
		char c  = param[0];
		cout << "char: '" << c << "'"<< endl;
		int i = static_cast<int>(c);
		cout << "int: " << i << endl;
		float f = static_cast<float>(i);
		cout << "float: " << f << ".0f"<< endl;
		double d = static_cast<double>(i);
		cout << "double: " << d << ".0"<< endl;
		return ;
	}
	if (is_all_digit(param)) // Int type 
	{
		// INT conversion part
		char* endptr;
		int i = 0;
		long l = strtol(param.c_str(), &endptr, 10);
		if (l > INT_MAX || l < INT_MIN)
			cout << "int: impossible" << endl;
		else
		{
			i = static_cast<int>(l);
			cout << "int: " << i << endl;
		}
		//Char conversion part SHOULD BE DISPLAY BEFORE int
		if ((i >= 0 && i < 32) || i == 127)
			cout << "char: Non displayable" << endl;
		else if (i > 126 || i < 0)
			cout << "char: impossible" << endl;
		else
		{
			char c = static_cast<char>(i);
			cout << "char: '" << c << "'"<< endl;
		}
		float f = static_cast<float>(i); // Need to check FLOAT MAX - FLOAT MIN?
		cout << "float: " << f << ".0f" << endl;
		double d = static_cast<double>(i); // Need to check double MAX - double MIN?
		cout << "double: " << d << ".0" << endl;

	}
	else if(is_float(param)) //Float type
	{
		char sign = '\0';
		float f = atof(param.c_str());
		if (std::isinf(f) && f > 0)
			sign = '+';
		double d = static_cast<double>(f);
		int i = static_cast<int>(f);
		if (f != i || i > 126 || i < 0)
			cout << "char: impossible" << endl;
		else if ((i >= 0 && i < 32) || i == 127)
			cout << "char: Non displayable" << endl;
		else
		{
			char c = static_cast<char>(i);
			cout << "char: '" << c << "'"<< endl;
		}
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
	else if (is_double(param))
	{
		char sign = '\0';
		char *endptr;
		double d = std::strtod(param.c_str(), &endptr);
		if (std::isinf(d) && d > 0)
			sign = '+';
		float f = static_cast<float>(d);
		int i = static_cast<int>(d);
		if (d != i || i > 126 || i < 0)
			cout << "char: impossible" << endl;
		else if ((i >= 0 && i < 32) || i == 127)
			cout << "char: Non displayable" << endl;
		else
		{
			char c = static_cast<char>(i);
			cout << "char: '" << c << "'"<< endl;
		}
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
	else if (param == "nan" || param == "nanf" || param == "+inf" || param == "-inf" || param == "+inff" || param == "-inff") //faire une fonction qui return un bool
	{
		cout << "Special case nan or inf" << endl;
	}
	else
		impossibleCase();
}

bool is_all_digit(const string & param){
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

bool is_float(const string & param){
	int nb_f = 0;
	int nb_p = 0;
	int nb_m = 0;
	int size = param.length();

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

bool is_double(const string & param){
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


/*
char // Non displayable [0, 31] + 127 => display "Non displayable"

int

float // -inf, +inf and nanf

double // -inf, +inf, nan
*/