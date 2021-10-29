#include <iostream>

using namespace std;

class New_Delete
{
    private:
        int value;
    
    public:
        New_Delete()
        {
            value = 5;
        }

        void display()
        {
            cout << "\n Value = " << value;
        }
};

int main()
{
    New_Delete *nd;

    nd = new New_Delete();

    nd->display();

    delete *nd;

    return 0;
}