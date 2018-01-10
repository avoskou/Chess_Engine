
#include"Route.h"
#include"Piece.h"
class Bishop: public Piece{
 public:
  //Constructor
  Bishop(bool clr,const int initial_x,const int initial_y);

  //Check of move is possible fot the piece
  bool  move_possible(Route route,bool kill);
  
  //
  void  elementary_move(int strt_x,int strt_y,int go_x,int go_y_);
  
  //print Bishop
  void print_type(); 

};
