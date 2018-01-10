#ifndef KING_H
#define KING_H


#include"Piece.h"
#include"Route.h"
class King: public Piece{
 public:
  //Constructor
  King(bool clr,const int initial_x,const int initial_y);
  
  //Checks if a move is possible
  bool  move_possible(Route route,bool kill);
  
  void  elementary_move(int strt_x,int strt_y,int go_x,int go_y_);
  
  //print King
  void print_type();
  
};
#endif
