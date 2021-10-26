#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

class Bank_Account {

    private:
        string name;
        int ac_num;
        string ac_type;
        float ac_balance;

    public:
        Bank_Account(string nme, int num, string type, float balance) {
            name = nme;
            ac_num = num;
            ac_type = type;
            ac_balance = balance;
        }

        void Deposit() {
            int amount;

            cout << endl << "Enter amount to deposit : ";
            cin >> amount;

            ac_balance += amount;
        }

        void Withdraw() {
            int amount;

            cout << endl << "Enter amount to withdraw : ";
            cin >> amount;

            if (amount > ac_balance) {
                cout << endl << "********************************" << endl << endl;
                cout << "Insufficient Funds" << endl;
                cout << endl << "********************************" << endl << endl;
            }
            else {
                ac_balance -= amount;
            }
        }

        void Display() {
            cout << endl << "********************************" << endl;
            cout << "Name : " << name << endl;
            cout << "Available Balance : " << ac_balance << endl;
            cout << "********************************" << endl << endl;
        }
};




int main(void) {

    Bank_Account ac1("Zubayer", 123, "Savings", 1000);

    while (1) {
        cout << endl << "*************** MENU *****************" << endl;
        cout << "Choose your option from the following list : " << endl;
        cout << "1. Display your name and current balance." << endl;
        cout << "2. Deposit Money to your Account." << endl;
        cout << "3. Withdraw Money from your Account." << endl;
        cout << "4. Exit" << endl;

        int n;
        cout << endl << "Your choice : ";
        cin >> n;

        if (n == 1)
            ac1.Display();
        else if (n == 2)
            ac1.Deposit();
        else if (n == 3)
            ac1.Withdraw();
        else
            exit(0);
    }

    return 0;
}