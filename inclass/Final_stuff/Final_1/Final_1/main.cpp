#include <iostream>

using namespace std;

class Animal {
private:
    string name;
    int numLegs;

public:
    Animal(){}; // 5. Needs {} for inline.
    Animal(string n, int l) {name = n; numLegs = l;}
    ~Animal(){}; // 6. added deconstructor


    string getName() {return name;}
    int getLegs() {return numLegs;}
    void setLegs(int l) {numLegs = l;}
    void setName(string name) {name = name;}
};

class Deer : public Animal{ // `.changed from ; to :
public:
    Deer() { setName("Deer"); setLegs(4);} // 3. name is private. used setter instead 4. numlegs is private using setter instead.

    string eats() {return "Grass";}
};

int main()
{
    Animal alpha;
    Animal beta("horse", 4);

    Deer gamma;

    alpha.setName("Frog");

    cout << alpha.getName() << endl;
    cout << beta.getName() << endl;
    cout << gamma.getName() << " " << gamma.eats() << endl; // 2. changed eats() to gamma.eats()

    return 0;
}
