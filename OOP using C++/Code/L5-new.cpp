
#include <iostream>

using namespace std;

class New_Delete
{
    private:
        int value;
    public:
        New_Delete()
        {
            cout << "Enter Value: ";
            cin >> value;
        }
        void display()
        {
            cout << "\n value = " << value;
        }
};

int main()
{
    New_Delete* nd;

    nd = new New_Delete[3];

    for(int i=0; i< 3; i++)
    {
        nd[i].display();
    }
        
    delete[] nd;

    return 0;
}


// #include <iostream>

// using namespace std;

// class New_Delete
// {
//     private:
//         int value;
//     public:
//         New_Delete()
//         {
//             value = 5;
//         }
//         void display()
//         {
//             cout << "\n value = " << value;
//         }
// };

// int main()
// {
//     New_Delete *nd;

//     nd = new New_Delete();

//     nd->display();

//     delete nd;

//     return 0;
// }



// #include <iostream>

// using namespace std;

// int main()
// {
//     int num, *value;

//     cout << "Enter total number of values to store: ";
//     cin >> num;

//     value = new int[num];              // Memory is allocated the integer variable 'value'
//     for (int i = 0; i < num; ++i)
//     {
//         cout << "Value " << i + 1 << ": ";
//         cin >> *(value + i);
//     }

//     cout << "\n\nStored Values..." << endl;
//     for (int i = 0; i < num; ++i)
//     {
//         cout << "Value " << i + 1 << " :" << *(value + i) << endl;
//     }

//     delete[] value;                   // Memory is deallocated for the integer variable 'value'

//     return 0;
// }










// #include <iostream>

// using namespace std;

// int main()
// {
//     int *value;

//     value = new int;
//     cout << "\n Memory is allocated the variable 'value'..";

//     *value = 5;

//     cout << "\n\nStored Value..." ;
//     cout << *value << endl;

//     delete value;
//     cout << "\n Memory is deallocated for the variable 'value'..\n\n";

//     return 0;
// }




