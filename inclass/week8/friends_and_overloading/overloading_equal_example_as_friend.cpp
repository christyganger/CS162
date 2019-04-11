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

            // equals operator as friend
        friend bool operator==(Example & left, Example & right)
        {
            return *(left.value) == *(right.value);
        }
};

int main()
{
        // test basic class methods
    Example ex1(3);
    Example ex2(5);

        // show initial compare
    if (ex1 == ex2 )
        cout << "Equal" << endl;
    else
        cout << "Not Equal" << endl;

        // set them to same value
    ex1.setValue(ex2.getValue());
    if (ex1 == ex2 )
        cout << "Equal" << endl;
    else
        cout << "Not Equal" << endl;

    return 0;
}
