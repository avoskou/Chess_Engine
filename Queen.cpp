#include"Queen.h"
#include<iostream>
#include<cmath>

using namespace std;

bool Queen::move_possible(Route route,bool kill){

  if(route.magnitute>0){
    return 1;
  }
  return 0;
}
Queen::Queen(const bool clr,const int initial_x,const int initial_y){
  color=clr;
  pos_x=initial_x;
  pos_y=initial_y;
  type='Q';
}
void Queen::elementary_move(int strt_x,int strt_y,int go_x,int go_y_){
  //sss
}
void Queen::print_type(){
  cout<<"Queen";
}
