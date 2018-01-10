#include"Rook.h"
#include<iostream>
#include<cmath>

using namespace std;

bool Rook::move_possible(Route route,bool kill){
  if(route.magnitute>0 && !(abs(route.updown)>0 && abs(route.lftrght)>0  ))
    return 1;
  return 0;
}

Rook::Rook(bool clr,const int initial_x,const int initial_y){
  color=clr;
  pos_x=initial_x;
  pos_y=initial_y;
  type='R';
}





void Rook::elementary_move(int strt_x,int strt_y,int go_x,int go_y_){
  //
}


void Rook::print_type(){
  cout<<"Rook";
}
