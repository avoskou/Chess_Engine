#include"Route.h"


void Route::setup(const int DX,const int DY){
  dx=DX;
  dy=DY;
  magnitute=abs(dx);
  if(abs(dx)<abs(dy))
    magnitute=abs(dy);
  if(abs(dx)!=abs(dy) && abs(dx)>0 && abs(dy)>0 )
    magnitute=0;                 // knight route 
  updown=(dy>=0)+(dy>0)-1;
  lftrght=(dx>=0)+(dx>0)-1;
}
