
#include"ChessBoard.h"

void ChessBoard::print_board(){
  printf("\n-----------------------------------------\n");
  for(int j=7;j>=0;j--){
    for(int i=0;i<=7;i++){
      if(piece[i][j]!=NULL){
	piece[i][j]->print_id();
      }else{
	printf("|   |");
      }
    }
    printf("|\n-----------------------------------------\n");  
  }
}


void ChessBoard::setboard(){
  
  end=0;
  plays=0;               //whites play first
  player[0]="White";
  player[1]="Black";
  
  for(int j=0;j<=7;j++){
    for(int i=0;i<=7;i++){
      piece[j][i]=NULL;
    }
  }
  
  for(int j=0;j<=1;j++){
    piece[0][7*j]= new Rook(j,0,7*j);
    piece[1][7*j]= new Knight(j,1,7*j);
    piece[2][7*j]= new Bishop(j,2,7*j);
    piece[3][7*j]= new Queen(j,3,7*j);
    piece[4][7*j]= new King(j,4,7*j);
    piece[5][7*j]= new Bishop(j,5,7*j);
    piece[6][7*j]= new Knight(j,6,7*j);
    piece[7][7*j]= new Rook(j,7,7*j);
    for(int i=0;i<=7;i++)
      piece[i][1+j*5]=new Pawn(j,i,1+j*5);
  }
  
 
  king[0]=piece[4][0]; //white king 
  king[1]=piece[4][7]; //black king
  
  printf("A new chess game is started!\n");
  //  print_board(piece);
  
    
}
  

ChessBoard::ChessBoard(){
  setboard();
}

void ChessBoard::clearboard(){
   for(int j=0;j<=7;j++){
    for(int i=0;i<=7;i++){
      delete piece[j][i];
      piece[j][i]=NULL;
    }
  }
}

ChessBoard::~ChessBoard(){
  clearboard();
}


void ChessBoard::resetBoard(){
  clearboard();
  setboard();
}

  

bool ChessBoard::decode(const char from[],const char to[],int &from_x,int &from_y,int &to_x,int &to_y)
{  
   
   if('H'<from[0] || 'A'>from[0] || '8'<from[1] || '1'>from[1] ){
     return 0;
   }
   if('H'<to[0] || 'A'>to[0] || '8'<to[1] || '1'>to[1]){
     return 0;
   }
   from_x=(int)(from[0])-65;
   from_y=(int)(from[1])-49;
   to_x=(int)(to[0])-65;
   to_y=(int)(to[1])-49;
   
   return 1;
       
   
}



bool ChessBoard::find_route(int from_x,int from_y,int to_x,int to_y,Route &route){
  int dx=to_x-from_x;
  int dy=to_y-from_y;
  if(abs(abs(dx)-abs(dy))>1 && abs(dx)>0 && abs(dy)>0) return 0;
  route.setup(dx,dy);
  return 1;
}


bool ChessBoard::check_route(int from_x,int from_y,Route route){
  for(int i=1;i<route.magnitute;i++){
    if(piece[from_x+i*route.lftrght][from_y+i*route.updown]!=NULL)
      return 0;
  }
  return 1;
}

bool ChessBoard::mate(){
  bool player = !plays;
  for(int a=0;a<=7;a++){
    for(int b=0;b<=7;b++){
      for(int c=0;c<=7;c++){
	for(int d=0;d<=7;d++){
	  if(piece[a][b]!=NULL && piece[a][b]->show_color()==player && validMove(a,b,c,d,player) ){
        	     return 0;
	
	  }
	}
      }
    }
  }
  
  return 1;
}



bool ChessBoard::Check_possible(int from_x,int from_y,int to_x,int to_y,const bool player){
  Piece *temp1,*temp2;
  int tempx1,tempx2,tempy1,tempy2;
  if(piece[from_x][from_y]==NULL)
    return 0;
  
  temp1=piece[from_x][from_y];
  temp2=piece[to_x][to_y];
  tempx1=piece[from_x][from_y]->x();
  tempy1=piece[from_x][from_y]->y();
  if(piece[to_x][to_y]!=NULL){ 
    tempx2=piece[to_x][to_y]->x();
    tempy2=piece[to_x][to_y]->y();
  }
  piece[from_x][from_y]=NULL;
  piece[to_x][to_y]=temp1;

  piece[to_x][to_y]->set_x(to_x);
  piece[to_x][to_y]->set_y(to_y);
  
  if( check(player)){
    piece[from_x][from_y]=temp1;
    piece[to_x][to_y]=temp2;
    piece[from_x][from_y]->set_x(tempx1);
    piece[from_x][from_y]->set_y(tempy1);
    if(piece[to_x][to_y]!=NULL){
      piece[to_x][to_y]->set_x(tempx2);
      piece[to_x][to_y]->set_y(tempy2);
    }
    
    return 0;
  }
  piece[from_x][from_y]=temp1;
  piece[to_x][to_y]=temp2;
  

  piece[from_x][from_y]->set_x(tempx1);
  piece[from_x][from_y]->set_y(tempy1);
  if(piece[to_x][to_y]!=NULL){
    piece[to_x][to_y]->set_x(tempx2);
    piece[to_x][to_y]->set_y(tempy2);
  }
  return 1;
}

  


bool ChessBoard::validMove(int from_x,int from_y,int to_x,int to_y,const bool player){
 
  Route route;
  bool kill=0;
 
  if(piece[from_x][from_y]==NULL)
    return 0;
  
  if(!Check_possible(from_x,from_y,to_x,to_y,plays)){
      return 0;
  }

  if(piece[from_x][from_y]==NULL){
    return 0;
  }

  if(piece[from_x][from_y]->show_color()!=player){
    return 0;
  }

  if(piece[from_x][from_y]==NULL){
    return 0;
  }

  if(piece[to_x][to_y]!=NULL  && piece[from_x][from_y]->show_color()==piece[to_x][to_y]->show_color()){
    return 0;
  }

  if(!find_route(from_x,from_y,to_x,to_y,route)){
    return 0;
  }
  if(piece[to_x][to_x]!=NULL)
    kill=1;
  if(!piece[from_x][from_y]->move_possible(route,kill)){
    return 0;
  }
  if(!check_route(from_x,from_y,route)){
    return 0;
  }
  return 1;
}



bool ChessBoard::checkMove(int from_x,int from_y,const bool player){
  Route route;
  bool kill=1;
  
  int to_x=king[!player]->x();
  int to_y=king[!player]->y();

  if(piece[from_x][from_y]==NULL){
    return 0;
  }
  
  if(piece[from_x][from_y]->show_color()!=player){
    return 0;
  }
  
  if(piece[from_x][from_y]==NULL){  
    return 0;
  }

  if(piece[to_x][to_y]!=NULL  && piece[from_x][from_y]->show_color()==piece[to_x][to_y]->show_color()){
    return 0;
  }

  if(!find_route(from_x,from_y,to_x,to_y,route)){
    return 0;
  }
 
  if(!piece[from_x][from_y]->move_possible(route,kill)){
    return 0;
  }
  if(!check_route(from_x,from_y,route)){
    return 0;
  }
  
  return 1;
}


bool ChessBoard::check(bool player){
  
  for(int y=0;y<=7;y++){
    for(int x=0;x<=7;x++){
      if(piece[x][y]!=NULL && piece[x][y]->show_color()==player){
	if(checkMove(x,y,player)){
	  return 1;
	}
      }
    }
  }
  return 0;
}

bool ChessBoard::submitMove(const char from[],const char to[]){
  int from_x,from_y,to_x,to_y;
  Route route;
  bool kill=0;

  if(end) {
    cout<<"game over"<<endl;
    return 0;
  }
  //check if input is correct
  if(!decode(from,to,from_x,from_y,to_x,to_y)){
    cout<<"No existing square!";
    return 0;
  }

  //check if the square is empty 
  if(piece[from_x][from_y]==NULL){
    cout<<"There is no piece at position "<<from<<" !"<<endl;
    return 0;
  }
  
  //check if is the right color
  if(piece[from_x][from_y]->show_color()!=plays && !plays){
    cout<<"It is not Black’s turn to move!"<<endl;
    return 0;
  }

  if(piece[from_x][from_y]->show_color()!=plays && plays){
    cout<<"It is not White’s turn to move!"<<endl;
    return 0;
  }
  

  
  
  //check if a piece of the same color is the target
  if(piece[to_x][to_y]!=NULL && piece[from_x][from_y]->show_color()==piece[to_x][to_y]->show_color()){
    cout<<player[plays]<<"'s ";
    piece[from_x][from_y]->print_type();
    cout <<" cannot move to "<<to<<" !"<<endl;
    return 0;
  }
  
  
  //finds the route to the tager
  if(!find_route(from_x,from_y,to_x,to_y,route)){
    cout<<player[plays]<<"'s ";
    piece[from_x][from_y]->print_type();
    cout<<" cannot move to "<<to<<" !"<<endl;
    return 0;
  }

  //checks if there is an enemy at the target
  if(piece[to_x][to_y]!=NULL)
    kill=1;
    
  
  //checks if this piece is possible make the move that route descripes 
  if(!piece[from_x][from_y]->move_possible(route,kill)){
    cout<<player[plays]<<"'s ";
    piece[from_x][from_y]->print_type();
    cout<<" cannot move to "<<to<<" !"<<endl;
    return 0;
  }
  
  //checks if there are any pieces between the 2 squares
  if(!check_route(from_x,from_y,route)){
    cout<<player[plays]<<"'s ";
    piece[from_x][from_y]->print_type();
    cout<<" cannot move to "<<to<<" !"<<endl;
    return 0;
  }

  // checks if that move means a check situation
  if(!Check_possible(from_x,from_y,to_x,to_y,!plays)){
    cout<<player[plays]<<"'s ";
    piece[from_x][from_y]->print_type();
    cout<<" cannot move to "<<to<<" !";
    cout<<"  will be check"<<endl;
    return 0;
  }
   
  if(plays){
    printf("Black's ");
  }
  else{
    printf("White's ");
  }
  
  piece[from_x][from_y]->print_type();
  printf(" moves from %s to %s ",from,to);

  if(piece[to_x][to_y]!=NULL){
    cout<<"taking ";
    if(!plays){
      cout<<"Black's ";
    }
    else{
      cout<<"White's ";
    }
    piece[to_x][to_y]->print_type();
    delete piece[to_x][to_y];
    piece[to_x][to_y]=NULL;
    
  }

  
  // the actual move
  piece[to_x][to_y]=piece[from_x][from_y];
  piece[to_x][to_y]->set_x(to_x);
  piece[to_x][to_y]->set_y(to_y);
  piece[from_x][from_y]=NULL;

  // checks for check and mate situations 
  if(check(plays)){
    cout<<endl;
    cout<<player[!plays]<<" is in check";
    if(mate()){
      end=1;
      cout<<"mate";
    }
    cout<<endl;
  }
  else{
    if(mate()) cout<<"is in stalemate"<<endl;
  }

  cout<<endl;
  plays=!plays;
  return 1;
  
  
}
  
  
   
  
    
  
