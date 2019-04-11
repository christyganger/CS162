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

    friend ostream & operator<<(ostream & out, Example & ex)
    {
        out << ex.getValue();
        return out;
    }
};

int main()
{
        // test basic class methods
    Example ex1(3);
    Example ex2(5);

        // show two ways of doing output
    cout << "ex1 is " << ex1.getValue() << " ex2 is "  << ex2.getValue() << endl;

    cout << "ex1 is " << ex1 << " ex2 is "  << ex2 << endl;

    return 0;
}
