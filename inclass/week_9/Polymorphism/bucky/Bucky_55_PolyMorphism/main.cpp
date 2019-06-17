#include <iostream>

using namespace std;

class Enemy
{
protected:
    int attackPower;
public:
    void setAttackPower(int a)
    {
    attackPower = a;
    }
};

class Ninja: public Enemy
{
public:
    void attack()
    {
    cout << "I am a ninja, ninja chop! -" << attackPower << "\n";
    }
};

class Monster: public Enemy
{
public:
    void attack()
    {
    cout << "Monster must eat you!! -" << attackPower << "\n";
    }
};

int main()
{
    Ninja n;
    Monster m;
    Enemy *enemy1 = &n;
    Enemy *enemy2 = &m;

    enemy1->setAttackPower(50);
    enemy2->setAttackPower(99);

    n.attack();
    m.attack();



    return 0;
}
