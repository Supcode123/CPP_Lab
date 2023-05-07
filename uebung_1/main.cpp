#include <iostream>
#include "rational.h"
using namespace std;

int main(int argc, char** argv)
{
//1.1a&1.1b
Rational b;
Rational a(1,4);
Rational r3(a);
//1.1c
Rational c = a + b;
Rational d= b - a;
Rational e= a * b;
Rational f= b / a;
cout << "c=" << c << endl;
cout << "d=" << d << endl;
cout << "e=" << e << endl;
cout << "f=" << f << endl;
//overload of "<"
Rational arr[]={c,d,e,f};
Rational min;
for(int i =0 ;i<3 ; i++)
    {
     min = arr[i] < arr[i+1];
    }

cout << "the minimun is"<<" "<< min <<endl;
//simplify
for(int i=0 ; i<4 ; i++)
    {
    simplify(arr[i]);
    switch(i)
    {
        case 0:
        cout << "simplify c=" << arr[i] << endl;
        break;
        case 1:
        cout << "simplify d=" << arr[i] << endl;
        break;
        case 2:
        cout << "simplify e=" << arr[i] << endl;
        break;
        default:
        cout << "simplify f=" << arr[i] << endl;
 }
    }
system("pause");
	return 0;
}
