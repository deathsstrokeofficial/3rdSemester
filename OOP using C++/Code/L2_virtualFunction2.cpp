
#include <iostream>
using namespace std;

class A
{
    public:
        virtual void display()  // Declaring a virtual function
        {
            cout << "\nBase class function invoked" << endl;
        }
};

class B: public A
{
    public:
        void display()
        {
            cout << "\nDerived class function invoked" << endl;
        }
};

int main()
{
    A *a;
    B b;

    a = &b;

    a->display();

    return 0;
}



