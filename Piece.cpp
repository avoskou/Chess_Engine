#include"Piece.h"
#include<iostream>

using namespace std;

bool Piece::show_color(){
	return color;
} 
char Piece::show_type(){
	return type;
}
void Piece::print_id(){
 cout<<"|"<<type<<" "<<color<<"|";
}
Piece::~Piece(){}

void Piece::print_type(){}

//return x coordinate
int Piece::x(){
  return pos_x;
}
  
//return y coordinate
int Piece::y(){
  return pos_y;
}

//set x coordinate
void Piece::set_x(int inx){
  pos_x=inx;
}
//set y coordinate
void Piece::set_y(int iny){
  pos_y=iny;
}
