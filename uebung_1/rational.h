#include <iostream>
using namespace std;


class Rational{
public:
  int counter;//numerator
  int denominator;//denominator
    
   //normal construct func
   Rational();
   //construct func with paramaters
   Rational(int counter,int denominator);
   //copy construct func 
   Rational(const Rational &r);
   //deconstruct func 
   ~Rational();
} ;

Rational operator+(Rational &r1,Rational &r2);

Rational operator-(Rational &r1,Rational &r2);

Rational operator*(Rational &r1,Rational &r2);

Rational operator/(Rational &r1,Rational &r2);

ostream & operator<<(ostream &cout,Rational &r);

Rational operator<(Rational,Rational);

Rational simplify(Rational &r);