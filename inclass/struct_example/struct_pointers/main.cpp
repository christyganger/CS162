#include <iostream>
using namespace std;
 // global definition of rectangle for later use
struct t_rect {
 int width;
 int length;
};
 // function declarations, definitions below
t_rect getRectangle();
void showArea(t_rect aRect);
 // main program, does example work
int main()
{

 t_rect *myRects = new t_rect;
 const int SIZE = 10;
 for(int i = 0; i < SIZE; i++)
 myRects[i] = getRectangle();

 for(int i = 0; i < SIZE; i++)
 {
 int area = myRects[i].length * myRects[i].width;
 cout << "For rectangle " << i+1 << " the area is " << area << endl;
 }
 delete myRects;
 return 0;
}
 // get the length and width of a rectangle
t_rect getRectangle()
{
 t_rect data;
 cout << "Enter width: ";
 cin >> data.width;
 cout << "Enter length: ";
 cin >> data.length;

 return data;
}
