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
 t_rect aRectangle = getRectangle();

 showArea(aRectangle);

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
 // display the area of the passed rectangle
void showArea(t_rect aRect)
{
 int area = aRect.width * aRect.length;

 cout << "The area is " << area << endl;
}
