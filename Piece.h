#include"Route.h"
#ifndef PIECE_H
#define PIECE_H
#include<cstdio>
class Piece{
 protected:

  bool color; //0 for white 1 for black
  char type;  // eg 'K' for King
  int pos_x;  //x coordinate
  int pos_y;  //y coordinate
  
 public:

  //the value of color
  bool show_color();

  //check if a move is possible;
  virtual bool move_possible(Route route,bool kill){return 0;}
  
  // print the type eg "King"
  virtual void print_type();
  
  //Destraction
  virtual ~Piece();
  
  //Show type eg 'K' fro King
  char show_type();
  
  //print type and color
  void print_id();
  
  //return x coordinate
  int x();
  
  //return y coordinate
  int y();
   
  //set x coordinate
  void set_x(int inx);
  
  //set y coordinate
  void set_y(int iny);
    
  };
  
#endif 
