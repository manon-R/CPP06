#include <iostream>
#include <cstdlib>
#include <stdexcept>
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"


// Macros pour les couleurs
# define RESET   "\033[0m"
# define GREEN   "\033[1;32m"
# define MAGENTA "\033[1;35m"
# define YELLOW  "\033[1;33m"
# define CYAN    "\033[1;36m"



using std::cout;
using std::endl;

Base* generate(void); // randomly generate A or B or C object type
void identify(Base* p); // display the type of p object
void identify(Base& p);


Base* generate(void){
	int randNumber = rand() % 3; // range [0, 2]
	switch (randNumber)
	{
		case 0:
			return (new A());

		case 1:
			return (new B());

		case 2:
			return (new C());

		default:
			cout << "Problem encounter with the random Number ?" << endl;
			return NULL;   
	}
}

void identify(Base* p){
	A* a = dynamic_cast<A *>(p);
	if (a != NULL)
	{
		cout << "The object pointed to by p is of type " << GREEN << "A" << RESET << endl;
		return;
	}
	B* b = dynamic_cast<B *>(p);
	if (b != NULL)
	{
		cout << "The object pointed to by p is of type " << YELLOW << "B" << RESET << endl;
		return;
	}
	C* c = dynamic_cast<C *>(p);
	if (c != NULL)
	{
		cout << "The object pointed to by p is of type " << MAGENTA << "C" << RESET << endl;
		return;
	}
	cout << "Type ERROR..." << endl;	
}

void identify(Base& p){
	try {
		A& a = dynamic_cast<A &>(p);
		cout << "The object pointed to by p is of type " << GREEN << "A" << RESET << endl;
		(void)a;
		return ;
	}
	catch (std::exception & e){
		(void)e; 
	}
	try {
		B& b = dynamic_cast<B &>(p);
		cout << "The object pointed to by p is of type " << YELLOW << "B" << RESET << endl;
		(void)b;
		return ;
	}
	catch (std::exception & e){
		(void)e;
	}
	try {
		C& c = dynamic_cast<C &>(p);
		cout << "The object pointed to by p is of type " << MAGENTA << "C" << RESET << endl;
		(void)c;
		return ;
	}
	catch (std::exception & e){
		cout << "Type error..." << endl;
	}
}


int main(void){
	srand(time(NULL));
	cout << CYAN << "***** Test dynamic cast on pointer *****\n" << RESET << endl;
	Base *test = generate();
	if (test)
		identify(test);
	Base *test1 = generate();
	if (test1)
		identify(test1);
	Base *test2 = generate();
	if (test2)
		identify(test2);
	Base *test3 = generate();
	if (test3)
		identify(test3);

	cout << CYAN << "\n***** Test dynamic cast on reference *****\n" << RESET << endl;
	
	identify(*test);
	identify(*test1);
	identify(*test2);
	identify(*test3);

	cout << endl;
	delete test;
	delete test1;
	delete test2;
	delete test3;
}
