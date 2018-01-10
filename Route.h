#include<cmath>
#ifndef ROUTE_H
#define ROUTE_H
using namespace std;

/* Route is a struct that contains all the information of the route 
  from one square to an other 
*/
struct Route{
  // the difference to the y coordinate of the raget  
  int dx;
  
  // the difference to the x coordinate of the raget  
  int dy;
  
  // +1 up  o nothing -1 down
  int updown;
  
  // +1 right 0 nothing -1 left
  int lftrght;
  
  // the magnitude of the route "vector"
  int magnitute;
  
  // calculating the other parameters from x and y
  void setup(const int in_dx,const int in_dy);
  
  
};
#endif  
