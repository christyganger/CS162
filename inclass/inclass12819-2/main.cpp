#include <iostream>

using namespace std;

int main()
{
    int x = 6;
    //int y = 10;
    int * p = &x;
    cout << "x " << x << "\n";
   //  cout << "y " << y << "\n";
      cout << "p " << p << "\n";
      // cout << "&y " << &y << "\n";
        cout << "&x " << &x << "\n";
         cout << "*p " << *p << "\n";
         p--;
         p--;
         cout << "*p " << *p << "\n";
          cout << "&p " << &p << "\n";
           cout << "*(&x) " << *(&x) << "\n";


    return 0;
}
