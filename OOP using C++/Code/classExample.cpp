
#include <iostream>

using namespace std;

class Test_2
{
    public:             // Public access specifier
        int x;          // Public attribute
    private:            // Private access specifier
        int y;          // Private attribute
};

int main()
{
    Test_2 myObj;
    myObj.x = 25;       // Allowed (public)
    myObj.y = 50;       // Not allowed (private)
    return 0;
}