#include <iostream>

using namespace std;

class A
{
    private:
        int x;

    public:
        A (int i)
        {
            x = i;
        }

        void operator+(A a)
        {
            int m = x + a.x;
            cout << "The result of the addition of two objects is : " << m << endl;
        }

        void operator-(A a)
        {
            int m = x - a.x;
            cout << "The result of the subtraction process is : " << m << endl;
        }

        void operator*(A a)
        {
            int m = x * a.x;
            cout << "The result of the multiplication process is : " << m << endl;
        }

        void operator/(A a)
        {
            int m = x / a.x;
            cout << "The result of the division process is : " << m << endl;
        }



};

int main(void)
{
    int num1, num2;

    cout << "Enter number 1 : ";
    cin >> num1;

    cout << "Enter number 2 : ";
    cin >> num2;

    A a1(num1);
    A a2(num2);

    a1 + a2;
    a1 - a2;
    a1 * a2;

    if (num2 != 0)
        a1 / a2;
    else
        cout << "Division by is not allowed, num2 cannot be zero." << endl;

    return 0;
}
