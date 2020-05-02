#include "Test.h"

std::ostream& operator<<(std::ostream& os, const Test& test)
{
    os << test.name;
    return os;
}

 bool Test::operator==(const Test& test) {
     return name == test.name;
 }

 void Test::speak() {
     std::cout << name << "s scream when you pull them from the ground!\n";
 }
