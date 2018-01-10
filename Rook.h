#include"Piece.h"
#include"Route.h"
class Rook: public Piece{
 public:
  //Constructor
  Rook(bool clr,const int initial_x,const int initial_y); 
  //check if the type of move is possible for that piece
  bool  move_possible(Route route,bool kill);
 
  void  elementary_move(int strt_x,int strt_y,int go_x,int go_y_);
  //print its type eg King
  void print_type(); 

};
