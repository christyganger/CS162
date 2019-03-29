#include <iostream>
#include <string>

using namespace std;

class BuckysClass{
private:
    string name;
public:
   void setName(string x){
    name = x;
   }
   string getName(){
   return name;
   }
};

int main()
{
   BuckysClass bo;
   bo.setName("sir bucky wallace");
   cout << bo.getName() << "\n";
    return 0;
}
