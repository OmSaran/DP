#include "Exceptions.hpp"
#include <iostream>
using namespace std;
const char* ResourceNotFoundException::what() const throw()
{
    cout << "In the what implementation" << endl;
    return "The requested resouce unavailable";
}