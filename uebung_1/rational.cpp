#include <iostream>
#include "rational.h"
using namespace std;

Rational::Rational():counter(1),denominator(2){
    cout<<"Rational"<<"("<<counter<<"/"<<denominator<<")"<<"created"<<endl;
}
Rational::Rational(int counter,int denominator):counter(counter),denominator(denominator)
{   if (denominator == 0){
    cout<<"denomiator should not be 0"<<endl;
    }
    cout<<"Rational"<<"("<<counter<<"/"<<denominator<<")"<<"created"<<endl;
 }
Rational::Rational(const Rational & rational)
{
    this ->counter=rational.counter;
    this ->denominator=rational.denominator;
    cout<<"Rational copied"<<endl;
    }
Rational::~Rational(){
    cout<<"delete Rational"<<endl;}
    
ostream & operator<<(ostream &cout,Rational &r)
{
    if(r.denominator==1)
        {
    cout<<r.counter<<endl;    
    }
    else
        {cout<<r.counter<<"/"<<r.denominator<<endl;}
    return cout;
    }
    
Rational operator+(Rational &r1,Rational &r2)
{
    Rational temp;
    temp.counter=r1.counter*r2.denominator+r2.counter*r1.denominator;
    temp.denominator=r1.denominator*r2.denominator;
    return temp;
    }
    
Rational operator-(Rational &r1,Rational &r2)
{
    Rational temp;
    temp.counter=r1.counter*r2.denominator-r2.counter*r1.denominator;
    temp.denominator=r1.denominator*r2.denominator;
    return temp;
    }
    
Rational operator*(Rational &r1,Rational &r2)
{
    Rational temp;
    temp.counter=r1.counter*r2.counter;
    temp.denominator=r1.denominator*r2.denominator;
    return temp;
    }
    
Rational operator/(Rational &r1,Rational &r2)
{
    Rational temp;
    temp.counter=r1.counter*r2.denominator;
    temp.denominator=r1.denominator*r2.counter;
    return temp;
    }
    
Rational operator<(Rational r1,Rational r2)
{
    
    Rational temp;
    temp=r1 / r2;
    if(temp.counter<=temp.denominator){
        return r1;
        }
    return r2;
    }
    
Rational simplify(Rational &r)
{int n=r.counter,m=r.denominator;
 int a=(m<n)?m:n;
 while(1)
{
    if(m%a==0&&n%a==0)break;
    a--;
}
    r.denominator = m/a;
    r.counter = n/a;
    return r ;
    }    
    