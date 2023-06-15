#include "map.hpp"
#include "food.hpp"
#include <iostream>
#include <string>

int main(int argc, char** argv) 
{
Food food1(6,"rice",1);
Food food2(7,"Jasimin",1.5);
std::vector<Food> speisen ; 
speisen.push_back(food1);
speisen.push_back(food2);
//speichern("food.csv", speisen) ;
laden("food.csv", speisen);
system("pause");
return 0;
}
