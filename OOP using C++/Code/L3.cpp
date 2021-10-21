#include <iostream>

using namespace std;



// class Date {
//     // Each Date value is a past, present, or, future date.
//     private:

//     public:
//         Date (int y, int m, int d);
//         // Construct a date with year y, month m, and day-in-month d.

//         int compareTo(Date that);
//         // Return -1 if this date is earlier than that or 0 if this date is equal to that
//         // or +1 if this date is later than that

//         StringtoString();
//         // Return this date rendered in ISO format

//         void advance(int n);
//         // Advance this date by n days (where n >= 0)
// }


// class Date {
//     // Each Date value is a past, present, or, future date.
//     // This date is represented by a year-number year, month-number month, and a day-in-month-number day

//     private:
//         int year, month, day;
    
//     public:
//         Date(int y, int m, int d)
//         {
//             // Construct a date with year y, month m, and day-in-month d
//             year = y;
//             month = m;
//             day = d;
//         }

//         int compareTo (Date that)
//         {
//             // Return -1 if this date is earlier than that or 0 if this date is equal to that
//             // Or +1 if this date is later than that
//             return(year < that.year ? -1:
//                     year > that.year ? +1:
//                     month < that.month ? -1:
//                     month > that.month ? +1:
//                     day < that.day ? -1:
//                     day > that.day ? +1: 0);
//         }

//         String toString ()
//         {
//             // Return this date in ISO format i.e. year-month-day
//             return newFormatDate;
//         }

//         void advance (int n)
//         {
//             // Advance this date by n days (where n >= 0)
//             ...
//         }
// };


// class Date
// {
//     private:

//     public:
//         Date (int y, int m, int d);

//         int compareTo (Date that);
//         String toString ();
//         void advance (int n);
// }



// class Date
// {
//     private:

//     public:
//         Date (int y, int m, int d);

//         int compareTo (Date that);
//         String toString ();
//         void advance (int n);
//         void advance1Day ();
// }



class Date
{
	// Each Date past, present, or future date, is represented by year, month & a day
	private :
		 int day, month, year;

	public :
		Date (int d, int m, int y)
        {
		    // Construct a date with year y, month m, and day-in-month d
		    // Throw an exception if they constitute an improper date
		    if (d < 1 || d > 31 || m < 1 || m > 12)
		    {  
                cout << "badly formed date" << endl;
            }

		    day = d;
            month = m;
            year = y;
		}

		int isLeap (int y) {
		    // Return true if and only if y is a leap year
		    return (y%4 == 0 && (y%100 != 0 || y%400 == 0));
	    }

        int equals (Date that)
        {
	        // Return true if this date equal to that, or false otherwise
		    return (year == that.year && month == that.month && day == that.day);
	    }

	    int compareTo (Date that)
        {
	        // Return -1 if this date comes before that or 0 if this date is equal to that,
	        // or +1 if this date come after that
		    return  (	year    < that.year ? -1 :
					    year    > that.year ? +1 :
					    month < that. month ? -1 :
					    month < that. month ? +1 :
					    day     < that.day ? -1 :
					    day     > that.day ? +1 : 0);
	    }

        int length (int m, int y)
        {   // Return the number of days in month m in year y
		    switch (m) {
				case 1: case 3: case 5: case 7:
				case 8: case 10: case 12:
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
            // Advance this date by n days (where n >= 0)
            int d = day + n, m = month, y = year;
            int last = length(m, y);

            while (d > (last)) 
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

        void showDate () 
        {
	        // Return this date's ISO string representation as day-month-year
	        cout << day << "-" << month << "-" << year << endl << endl;
	    }
}

// End of class Date

int main ()
{
    // Given a date and number of days advanced, shows new advanced date
  
    Date date1(17, 1, 1960);

    date1.showDate();
    date1.advance (2000);
    date1.showDate();
    return 0;
}








