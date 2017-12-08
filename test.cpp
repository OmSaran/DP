#include <iostream>
using namespace std;

int main()
{
    enum color { red, gree, blue };
    color c = color::red;

    if(c == color::red)
        cout << "Color is red" << endl;
}