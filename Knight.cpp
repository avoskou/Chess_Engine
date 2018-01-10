#include"Knight.h"
#include<iostream>
#include<cmath>

using namespace std;

bool Knight::move_possible(Route route,bool kill){
  if(route.magnitute==0 &&          (    (abs(route.dx)==2 && abs(route.dy)==1)    ||           (abs(route.dx)==1 && abs(route.dy)==2)  )     )
    return 1;
  return 0;
}


Knight::Knight(bool clr,const int initial_x,const int initial_y){
  color=clr;
  pos_x=initial_x;
  pos_y=initial_y;
  type='H';
}

void Knight::elementary_move(int strt_x,int strt_y,int go_x,int go_y_){
  //as
}  
void Knight::print_type(){
  cout<<"Knight";
}
