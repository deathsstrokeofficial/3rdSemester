
#include <iostream>

using namespace std;


class Shape                     // Interface class
{
    public:
        virtual void getDimension() = 0;
        virtual float calculateArea() = 0;
};

class Square : public Shape     // Derived class
{
    private:
        float dimension;
    public:
        void getDimension()
        {
            cin >> dimension;
        }

        float calculateArea()
        {
            return dimension * dimension;
        }
};


class Circle : public Shape      // Derived class
{
    private:
        float dimension;
    public:
        void getDimension()
        {
            cin >> dimension;
        }
        float calculateArea()
        {
            return 3.14 * dimension * dimension;
        }
};






int main()
{
    Shape *s;
    Square square;
    Circle circle;

    s = &square;

    cout << "Enter the length of the square: ";
    s->getDimension();
    cout << "Area of square: " << s->calculateArea() << endl;

    s = &circle;
    cout << "\nEnter radius of the circle: ";
    s->getDimension();
    cout << "Area of circle: " << s->calculateArea() << endl;

    return 0;
}



// class InterfaceClass
// { 
//     public: 
//         virtual  ~InterfaceClass();
//         virtual void method_first() = 0; 
//         virtual void method_second() = 0;
        
//         ...............
//         ...............
//         ...............
// };



