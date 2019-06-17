#include <iostream>

using namespace std;

class Enemy
{
public:
    virtual void attack(int){}

};

class Ninja: public Enemy
{
public:
    void attack(int red)
    {
        cout << "ninja attack!" << " Did " << red << " Damage!" << "\n";
    }
};

class Monster: public Enemy
{
public:

    void attack(int blue)
    {
        cout << "monster attack!" << " Did " << blue << " Damage!" << "\n";
    }
};

int main()
{
    Ninja n;
    Monster m;
    Enemy *enemy1 = &n;
    Enemy *enemy2 = &m;
    enemy1->attack(3);
    enemy2->attack(43);


    return 0;
}
