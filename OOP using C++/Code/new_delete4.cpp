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

    nd = new New_Delete[3];

    for (int i = 0; i < 3; i++)
    {
        nd[i].display();
    }

    delete nd[];

    return 0;
}