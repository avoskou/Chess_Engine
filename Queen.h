#include"Piece.h"
#include"Route.h"
class Queen: public  Piece{
 public:
 //Constractor
 Queen(const bool clr,const int initial_x,const int initial_y);
 //Check if move is possible
 bool  move_possible(Route route,bool kill);
 //
 void elementary_move(int strt_x,int strt_y,int go_x,int go_y_);
 //print its type
 void print_type(); 
};
