#include"Pawn.h"
#include<iostream>
#include<cmath>

using namespace std;

bool Pawn::move_possible(Route route,bool kill){

  if(route.dy==(1-2*color) && route.dx==0 && !kill  ){
    
    return 1;
  }
  if(pos_y== 1 && route.dy==2 && route.dx==0 && !kill  ){
    
    return 1;
  }
  if(pos_y== 6 && route.dy==-2 && route.dx==0 && !kill  ){
    
    return 1;
  }
  
  if(route.updown==(1-2*color) && abs(route.dx)==1 && kill  ){
    
    return 1; 
  }
  
  return 0;
  
}

Pawn::Pawn(bool clr,const int initial_x,const int initial_y){
  color=clr;
  pos_x=initial_x;
  pos_y=initial_y;
  type='P';
}

void Pawn::elementary_move(int strt_x,int strt_y,int go_x,int go_y_){
  //sd
}
void Pawn::print_type(){
  cout<<"Pawn";
}
