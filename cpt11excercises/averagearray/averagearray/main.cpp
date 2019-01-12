#include <iostream>
#include <limits>
using namespace std;

int main()
{
   int ArraySize = 100;
   int x = 0;
   int sum = 0;
   int ArrayStore[ArraySize];
   bool done = false;
   cout << "Please enter up to 100 numbers" << "\n";
   do
   {

        if(x < ArraySize)
        {
            cin >> ArrayStore[x];
            if (cin.fail())
            {
                cin.clear();
                cin.ignore(std::numeric_limits<streamsize>::max(), '\n' );

                cout << "invalid input try again" << "\n";
                continue;
            }
            if (ArrayStore[x] == 0 || ArrayStore[x] < 0)
            {
                for(int i =0; i < x; i++)
                {sum = sum + ArrayStore[i];}
                cout << "total numbers entered is " << x << "\n";
                cout << "total sum of the numbers is " << sum << "\n";
                cout << "Your average is " << sum/x << "\n";
                cout << "These numbers where entered... " << "\n";

                for(int j =0; j< x; j++ )
                {
                    if (j % 5== 0)
                    {
                        cout << "\n";
                    }
                    cout << ArrayStore[j] << " ";

                }

                done = true;
                continue;
            }
            cout << "array number " << x+1 << " stored as value " << ArrayStore[x] << "\n";
            x++;
        }
        else
        {
            for(int i =0; i < x; i++)
                sum = sum + ArrayStore[i];
                cout << "total numbers entered is " << x << "\n";
                cout << "total sum of the numbers is " << sum << "\n";
                cout << "Your average is " << sum/x << "\n";
            done = true;
        }

   }while(!done);
    return 0;
}
