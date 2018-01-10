#include"King.h"
#include<iostream>
#include<cmath>

using namespace std;

bool King::move_possible(Route route,bool kill){
  if( route.magnitute==1)
    return 1;
  return 0;
}

King::King(bool clr,const int initial_x,const int initial_y){
  color=clr;
  pos_x=initial_x;
  pos_y=initial_y;
  type='K';
}
void King::elementary_move(int strt_x,int strt_y,int go_x,int go_y_){
  /////////////
}
void King::print_type(){
  cout<<"King";
}
