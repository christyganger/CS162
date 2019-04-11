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
            // assignment operator
        Example & operator=(Example & ex)
        {
                // this is the left side of equals
                // so set our value to be the same as its
            *value = ex.getValue();
                // return our address
            return *this;
        }

            // addition operator as friend
        friend Example & operator+(Example & left, Example & right)
        {
                // need to create new Example
                // so will not modify either left or right
            Example temp;
            *temp.value = *left.value + *right.value;
            return *temp;
        }

};

int main()
{
        // test basic class methods
    Example ex1(3);
    Example ex2(5);

        // show initial values
    cout << "ex1 is " << ex1.getValue() << " ex2 is "  << ex2.getValue() << endl;
        // add ex2 to ex1
    ex1 = ex1 + ex2;
    cout << "ex1 is " << ex1.getValue() << " ex2 is "  << ex2.getValue() << endl;
    Example ex3;
    ex3 = ex1 + ex2;
    cout << "ex1 is " << ex1.getValue() << " ex2 is "  << ex2.getValue()<< " ex3 is "  << ex3.getValue() << endl;


    return 0;
}
