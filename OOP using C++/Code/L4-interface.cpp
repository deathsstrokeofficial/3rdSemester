
#include <iostream>

using namespace std;

class Shape             // Abstract Class
{
    protected:
        float dimension;
    
    public:
        void getDimension()
        {
            cin >> dimension;
        }

        // Pure virtual function
        virtual float calculateArea() = 0;
};


// Derived class Square
class Square : public Shape
{
    public:
        float calculateArea()
        {
            return dimension*dimension;
        }
};

// Derived class Circle
class Circle : public Shape
{
    public:
        float calculateArea()
        {
            return 3.14*dimension*dimension;
        }
};





int main (void)
{
    Square square;
    Circle circle;

    cout << "Enter the length of the square: ";
    square.getDimension();
    cout << "Area of square: " << square.calculateArea() << endl;

    cout << "\nEnter radius of the circle: ";
    circle.getDimension();
    cout << "Area of circle: " << circle.calculateArea() << endl;

    return 0;
}
















class AbstractClass
{
    private:
        int a, b;
    
    public:
        virtual void AbstractMemberFunction() = 0;   // Pure virtual function makes this Abstract Class

        virtual void NonAbstractMemberFunction()    // Virtual Function
        {
            ........
        }

        void NonAbstractMemberFunction2()
        {
            ........
        }
};







