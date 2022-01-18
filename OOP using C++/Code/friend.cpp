/*#include <iostream>

using namespace std;

class Calculator
{
    private:
        int x,y;
    public:
        Calculator()
        {
            x=5;
            y=10;
        }
        friend int sum(Calculator);
};

int sum(Calculator obj)
{
    return(obj.x+obj.y);
}

int main()
{
    Calculator c;
    cout<<"Sum of X & Y: "<<sum(c)<<endl;
    return 0;
}

*/

//Implementing Global Function as Friend Function

/*
#include <iostream>

using namespace std;

class B;

class A
{
    private:
        int x;
    public:
        A()
        {
            x=5;
        }
        friend int sum(A,B);
};

class B
{
    private:
        int y;
    public:
        B()
        {
            y=10;
        }
    friend int sum(A,B);
};

int sum(A a1, B b1)
{
    return(a1.x +b1.y);
}

int main()
{
    A a;
    B b;
    cout<< "Sum of x & y: "<<sum(a,b)<<endl;
    return 0;
}
*/
//Implementing friend function as a member of another class

/*#include <iostream>

using namespace std;

class B;

class A
{
    public:
        void display(B b);
};

class B
{
    private:
        int x;
    public:
        B()
        {
            x=4;
        }
        friend void A::display(B);
};

void A :: display(B b1)
{
    cout<<b1.x<<endl;
}

int main()
{
    A a;
    B b;
    a.display(b);

    return 0;
}*/


//Friend class

#include <iostream>

using namespace std;

class B;

class A
{
    private:
        int x;
    public:
        A()
        {
            x=4;
        }

        friend class B;

};

class B
{
    private:
        int y;
    public:
        B()
        {
            y=2;
        }
        void print(A &a1, B &b1)
        {
            cout<<a1.x - b1.y <<endl;
        }
};

int main()
{
    A a;
    B b;
    b.print(a,b);
    return 0;
}