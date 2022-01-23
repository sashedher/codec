#include <iostream>
using namespace std;

const double pi = 3.14159; 

void calculate()
{
  double area, radius;

  cout<<"Enter Radius for circle: "<<endl; 
  cin>>radius;

  area = pi * radius * radius; 

  cout<<"area is of circle is: "<<area<<endl;
 }
 
int main()
{
  calculate(); 
  return 0;
}