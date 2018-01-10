#include<iostream>
#include<cstdio>
#include"King.h"
#include"Queen.h"
#include"Knight.h"
#include"Rook.h"
#include"Pawn.h"
#include"Bishop.h"
#include"Route.h"

using namespace std;



class ChessBoard{
 private:
  Piece* piece[8][8]; //array with the pieces of the board
  Piece* king[2];     //The 2 kings
  string player[2];   //{White,Black}
  bool plays;         //0 white turn 1 black turn
  bool end;           // true if game over

  //clear the board
  void clearboard(); 
 
  //set pieces to their starting position
  void setboard();    

  //input string to integers
  bool decode(const char from[],const char to[],int &from_x,int &from_y,int &to_x,int &to_y);  
  // check if a route is possible (doesnt include pieces in the middle) 
  bool check_route(int from_x,int from_y,Route route);
  
 public:

  //constractor
  ChessBoard();

  //Check if there are no possible moves
  bool mate(); 

  //find the from one square to an other
  bool find_route(int from_x,int from_y,int to_x,int to_y,Route &route);

  //print the Chessboard
  void print_board();
  
  //Check if the palyer will be in check after the move
  bool Check_possible(int from_x,int from_y,int to_x,int to_y,const bool player);
   
  //check if move is valid
  bool validMove(int from_x,int from_y,int to_x,int to_y,const bool player);

  //checks if a move can kill the king 
  bool checkMove(int from_x,int from_y,const bool player);

  //true if player is check;
  bool check(const bool player);
  
  //sumbit a move and check if it is valid
  bool submitMove(const char from[],const char to[]);

  //pieces back to the starting positions
  void resetBoard();
 
  //destructor
  ~ChessBoard();
};


