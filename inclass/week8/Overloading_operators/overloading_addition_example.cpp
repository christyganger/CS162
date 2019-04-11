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

            // addition operator
            // need to create new example
            // so will not modify self or parameter
        Example & operator+(const Example & ex)
        {
            Example temp;
            *temp.value = *this->value + *ex.value;
            return (temp);
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
            // add ex2 to ex1 and save in ex3, show nothing changes but ex3
    Example ex3;
    ex3 = ex1 + ex2;
    cout << "ex1 is " << ex1.getValue() << " ex2 is "  << ex2.getValue() << " ex3 is "  << ex3.getValue() << endl;

    return 0;
}
