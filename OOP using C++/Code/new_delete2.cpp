#include <iostream>

using namespace std;

int main()
{
    int num, *value;

    cout << "\n Enter the size of the array...";
    cin >> num;

    value = new int[num];

    for (int i = 0; i < num; i++)
    {
        cout << "Enter value for " << i+1 << " position of the array...";
        cin >> *(value + 1);
    }

    for (int i = 0; i < num; i++)
    {
        cout << "Value at " << (i+1) << " position = " << *(value + i);
    }

    delete value[];

    return 0;
}