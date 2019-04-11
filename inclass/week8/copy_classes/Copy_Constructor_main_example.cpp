#include <iostream>

using namespace std;

    // simple class that uses memory on the heap
class Example{
    private:
        int * value;
    public:
            // basic methods
        Example() { value = new int(0); }
        Example(int v) { value = new int(v); }
        int getValue() { return *value; }
        void setValue(int v) {*value = v; }
            // copy constructor
            // comment and comment to see
            // problem and how it is solved
//#define copy
#ifdef copy
        Example(Example & ex)
        {
            value = new int(ex.getValue());
        }
#endif // copy
};

int main()
{
        // test basic class methods
    Example ex1;
    Example ex2(5);
    cout << ex1.getValue() << " "  << ex2.getValue() << endl;
    ex1.setValue(3);
    cout << ex1.getValue() << " "  << ex2.getValue() << endl;

        // example of why you need a copy constructor
        // creating a new object that is a copy of existing one
    Example ex3 = ex2;
        // initially they have the same value
    cout << "ex3 is " << ex3.getValue() << " ex2 is " << ex2.getValue() << endl;
        // now change the copy
    ex3.setValue(10);
        // you wantthem to be different, not the same any more
        // to see the problem, comment out the define for copy in the class
    cout << "ex3 is " << ex3.getValue() << " ex2 is " << ex2.getValue() << endl;

    return 0;
}
