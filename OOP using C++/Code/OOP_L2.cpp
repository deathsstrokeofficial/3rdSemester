#include <iostream>

using namespace std;

class constructor_1
{
    private:
        int x;
    public:
        constructor_1()
        {
            x = 5;
            cout << "x = " << x;
        }
};

int main()
{
    constructor_1 con_1;

    return 0;
}