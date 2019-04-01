#include <iostream>

using namespace std;

    // simple class that uses memory on the heap
class Example{
    private:
        static int myCount;
    public:
            // basic methods
        Example() { myCount++; }
        ~Example() { myCount--; }
        static int getCount(){return myCount;}
};
    // this must be somewhere outside of header
    // usually would be in .cpp file
int Example::myCount = 0;


int main()
{
    cout << "before creating any " << Example::getCount() << endl;
    Example ex1;
    cout << "after creating first " << Example::getCount() << endl;
    {
        cout << "before creating second " << Example::getCount() << endl;
        Example ex2;
        cout << "after creating second " << Example::getCount() << endl;
    }
    cout << "after scope of second " << Example::getCount() << endl;

    return 0;
}
