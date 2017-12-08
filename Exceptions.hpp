#include <exception>
class ResourceNotFoundException: public std::exception
{
    public:
    virtual const char* what() const throw();
};