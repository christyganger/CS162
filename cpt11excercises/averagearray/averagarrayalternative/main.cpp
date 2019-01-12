/* this code is fracked */
#include <iostream>
#include <limits>
using namespace std;

int main()
{
   int Arrayrow = 20;
   int Arraycol = 5;
   int x = 0;
    int y =0;
   int sum = 0;
   int counter = 0;
   int ArrayStore[Arrayrow][Arraycol];
   bool enterdatadone = false;
   bool mathdone = false;
   bool printdatadone = false;
   cout << "Please enter up to 100 numbers" << "\n";

 while(!enterdatadone)

   {

       if (x < Arrayrow)
       {

           if (y < Arraycol)
           {
                cin >> ArrayStore[x][y];
                if (ArrayStore[x][y] == 0)
                {
                    enterdatadone = true;
                    continue;
                }
                cout << "You entered " << ArrayStore[x][y] << "\n";
                cout << "debug current y is " << y << "\n";
                counter++;
                y++;

           }

           x++;
       }
   }
   x = 0;
   y = 0;
   //math
   while(!mathdone)
   {

       if ( x < Arrayrow)
       {
           if (y < Arraycol)
           {
               sum = sum + ArrayStore[x][y];
               cout << "debug current y is " << y << "\n";
               y++;

           }

           x++;
       }
        else mathdone = true;
        continue;
        }

x = 0;
y = 0;
while (!printdatadone)
{
    cout << "You have entered " << counter << " numbers." << "\n";
    cout << "The sum of the numbers is " << sum << "\n";
    cout << "The average of the numbers is " << sum/counter << "\n";
    cout << "You entered these numbers :" << "\n";
    if (x < Arrayrow)
    {
        if (y < Arraycol)
        {
            cout << ArrayStore[x][y] << " ";
            cout << "debug current y is " << y << "\n";
            y++;

        }

        x++;
    }
    printdatadone = true;
}
    return 0;
}
