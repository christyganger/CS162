#include <iostream>
#include <string>

using namespace std;

class BuckysClass{
private:
    string name;
public:
   BuckysClass(string z){
    setName(z);
   }

   void setName(string x){
    name = x;
   }
   string getName(){
   return name;
   }
};

int main()
{
    BuckysClass bo("lucky bucky roberts");
    cout << bo.getName() << "\n";

    BuckysClass bo2("derpy do new");
    cout << bo2.getName() << "\n";

    return 0;
}
