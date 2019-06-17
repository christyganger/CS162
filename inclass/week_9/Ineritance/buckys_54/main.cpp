#include <iostream>
#include "Mother.h"
#include "Daughter.h"


using namespace std;

int main()
{

    Mother mom;
    /*
    mom.sayName();

    cout << "Setting public value on mom " << "\n";
    mom.publicv = 32;
    cout << "The value is now: " << mom.publicv << "\n";

    mom.set_protectedv(32);
    cout << "protected is: ";
    mom.get_protectedv();

    cout << "\n\n\n\nStarting daughter class" << "\n";
    */
    Daughter tina;
    Daughter rena;
    /*tina.sayName();
    cout << "Setting public value on daughter" << "\n";
    tina.publicv = 40;
    cout << "The value is now: " << tina.publicv << "\n";

    cout << "Now setting protected to 40 " << "\n";
    tina.set_protectedv(40);
    cout << "protected is: ";
    tina.get_protectedv();

    cout << "\n\n\n\n Starting mom again" << "\n";

    mom.sayName();
    cout << "Setting public value on mom " << "\n";
    mom.publicv = 32;
    cout << "The value is now: " << mom.publicv << "\n";

    cout << "Now setting protected to 32 " << "\n";
    mom.set_protectedv(32);
    cout << "protected is: ";
    mom.get_protectedv();

    tina.doSomething();
*/
    return 0;
}
