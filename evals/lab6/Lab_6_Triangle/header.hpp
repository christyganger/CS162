#ifndef HEADER_HPP_INCLUDED
#define HEADER_HPP_INCLUDED

/*******************************
 *
 * Triangle Class
 *
 * Finished Code By Lawrence Warner
 * CS 162 C++
 * Last Modified: 2/21/19
 *
 *******************************/

class Triangle
{

  private:
    int A, B, C;

  public:
    //setters
    Triangle(int set_A = 3, int set_B = 4, int set_C = 5){A = set_A; B = set_B; C = set_C;}
    void setA(int set_A);
    void setB(int set_B);
    void setC(int set_C);

    //getters

    int getA();
    int getB();
    int getC();

    bool isEquilateral();
    bool isScalene();
    bool isIsosceles();
    bool isRight();
};

#endif // HEADER_HPP_INCLUDED
