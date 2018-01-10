#include"Piece.h"
#include"Route.h"
class Pawn: public  Piece{
 public:
  //Constructor
  Pawn(bool clr,const int initial_x,const int initial_y);
  //Check if the move is possible for that piece
  bool  move_possible(Route route,bool kill);
  
  void  elementary_move(int strt_x,int strt_y,int go_x,int go_y_);
  // print "Pawn"
  void  print_type(); 


};
