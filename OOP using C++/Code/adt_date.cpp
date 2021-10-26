#include <iostream>

using namespace std;

class Date
{
    private:
        int day, month, year;

    public:
        Date(int d, int m, int y)
        {
            if (d < 1 || d > 31 || m < 1 || m > 12)
            {
                cout << "Badly formed date" << endl;
            }

            day = d;
            month = m;
            year = y;
        }

        int isLeap (int y)
        {
            return (y%4 == 0 && (y%100 != 0 || y%400 == 0));
        }

        int equals (Date that)
        {
            return (year == that.year && month == that.month && day == that.day);
        }

        int compareTo (Date that)
        {
            return (    year < that.year ? -1 :
                        year > that.year ? +1 :
                        month < that.month ? -1 :
                        month > that.month ? +1 :
                        day < that.day ? -1 :
                        day > that.day ? +1 : 0);
        }

        int length (int m, int y)
        {
            switch (m)
            {
            case 1: case 3: case 5: case 7: case 8: case 10: case 12:
                return 31;
            case 4: case 6: case 9: case 11:
                return 30;
            case 2:
                return (isLeap(y) ? 29 : 28);
            default:
                return -1;
            }
        }

        void advance (int n)
        {
            int d = day + n, m = month, y = year;
            int last = length(m, y);

            while (d > last)
            {
                d -= last;
                if (m < 12)
                    m++;
                else
                {
                    m = 1;
                    y++;
                }
            }

            day = d;
            month = m;
            year = y;
        }

        void showDate()
        {
            cout << day << "-" << month << "-" << year << endl << endl;
        }
};




int main()
{
    Date date1(17, 1, 1960);

    date1.showDate();
    date1.advance(2000);
    date1.showDate();

    return 0;
}

