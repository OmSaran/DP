#include "Exceptions.hpp"

const char * ResourceNotFoundException::what() const throw()
{
    return "The requested resouce unavailable";
}