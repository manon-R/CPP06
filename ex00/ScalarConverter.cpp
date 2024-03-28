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

void ScalarConverter::impossibleCase(){
	cout << "char: impossible\nint: impossible\nfloat: impossible\ndouble: impossible\n";
}

void ScalarConverter::convert(const string& param){
	ScalarConverter sc;
	if (param.empty())
	{
		sc.impossibleCase();
		return ;
	}
	if (param.length() == 1 && (param[0] < '0' || param[0] > '9')){ // Char type
		char c  = param[0];
		cout << "char: " << c << endl;
		int i = static_cast<int>(c);
		cout << "int: " << i << endl;
		float f = static_cast<float>(i);
		cout << "float: " << f << ".0f"<< endl;
		double d = static_cast<double>(i);
		cout << "double: " << d << ".0"<< endl;
		return ;
	}
	if (is_all_digit(param)) // Int type but still need to check for INT_MIN and INT_MAX
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
		else if (i > 126)
			cout << "char: impossible" << endl;
		else
		{
			char c = static_cast<char>(i);
			cout << "char: " << c << endl;
		}
		float f = static_cast<float>(i); // Need to check FLOAT MAX - FLOAT MIN?
		cout << "float: " << f << ".0f" << endl;
		double d = static_cast<double>(i); // Need to check double MAX - double MIN?
		cout << "double: " << d << ".0" << endl;

	}
	else if(is_float(param))
	{
		float f = atof(param.c_str());
		cout << "float: " << f << "f" <<  endl;
		double d = static_cast<double>(f);
		cout << "double: " << d << endl;
	}

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


/*
char // Non displayable [0, 31] + 127 => display "Non displayable"

int

float // -inf, +inf and nanf

double // -inf, +inf, nan
*/