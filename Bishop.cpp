#include"Bishop.h"
#include<iostream>
#include<cmath>

using namespace std;

bool Bishop::move_possible(Route route,bool kill){
  if( abs(route.updown)==abs(route.lftrght) && route.magnitute>0 )
    return 1;
  return 0;
}
Bishop::Bishop(bool clr,const int initial_x,const int initial_y){
  color=clr;
  pos_x=initial_x;
  pos_y=initial_y;
  type='B';
}


void Bishop::elementary_move(int strt_x,int strt_y,int go_x,int go_y_){
}  
void Bishop::print_type(){
  cout<<"Bishop";
}
