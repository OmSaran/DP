#include <exception>
class ResourceNotFoundException: public std::exception
{
    virtual const char* what() const throw();
};