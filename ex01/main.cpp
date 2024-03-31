#include "Serializer.hpp"

using std::cout;
using std::endl;

// Macros pour les couleurs
# define RESET   "\033[0m"
# define CYAN    "\033[1;36m"
# define MAGENTA "\033[1;35m"


int main(void){

    Data test;
    test.name = "Norminette";
    test.age = 42;

    cout << "Data test address before serialize => " << CYAN <<  &test  << RESET << endl;
    cout << "Test name is " << CYAN << test.name << RESET << " and it is " << CYAN << test.age << RESET << " years old" << endl;

    cout << endl;
    uintptr_t test1 = Serializer::serialize(&test);
    cout << "New serialized variable test1 " << MAGENTA << test1 << RESET << endl;

    cout << endl;

    Data* test2 = Serializer::deserialize(test1);
    cout << "After deserialized test1, the address is => " << CYAN << test2 << RESET << endl;
    cout << "And test name is still " << CYAN << test2->name << RESET << " and it is still " << CYAN << test2->age << RESET << " years old" << endl;
}