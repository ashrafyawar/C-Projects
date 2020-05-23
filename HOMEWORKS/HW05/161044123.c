#include<stdio.h>

typedef enum {white = 10, black = 20} player;
typedef enum {white_man, black_man, white_king,black_king, empty}piece;
void init_board(piece board[][8]);
void display_board(piece board[][8]);

int move(piece board[][8], int from_x, int from_y, int to_x, int to_y, player p);
int check_end_of_game(piece board[][8]);

void sample_game_1();
void sample_game_2();
void move_player_white(piece board[][8],int from_x, int from_y, int to_x, int to_y, player p,int flag,int *move_allowed,int *capture);
void move_player_black(piece board[][8],int from_x, int from_y, int to_x, int to_y, player p,int flag,int *move_allowed,int *capture);
int main(){

	 sample_game_1();//calling function sample_game1.
	return 0;
}//end of main function.

void sample_game_1(){

	int f_x,a,end_of_game_checker,f_y,t_x,t_y,i,counter = 1,nth_time_cap = 0;
	piece winner;//enum type variable.
	
	piece board[8][8];//array of enum type.	
	init_board(board);//calling function init_board. 

	do{

		end_of_game_checker = check_end_of_game(board);//cheching end of game .
		do{

			counter = counter +1;
			display_board(board);//calling the function display_board.
			
			if (counter % 2 == 0){//condition to make turn to white player

				printf("Player_white...\n");
				printf("select x and y axises respectively to move from >>\n");
				scanf("%d%d",&f_x,&f_y);
				
				printf("select x and y axises respectively to move for >>\n");
				scanf("%d%d",&t_x,&t_y);

				a = move(board,f_x,f_y,t_x,t_y,white);//calling function move.

				if (a >= 0){
					nth_time_cap = a;//how many times capturing happened.
					printf("%d pieces of capturing have happened\n",nth_time_cap );
				}
				else if (a == -1)
					printf("the pices is not belong to you!!!\n");//when terun is -1.
				else if (a == -2)
					printf("move is not allowed!!\n");
			}

			else if (counter % 2!= 0){//condition ot make turn to black player. 
			
				printf("Player_black...\n");
				printf("select x and y axises respectively in eachto move from>>\n");
				scanf("%d%d",&f_x,&f_y);
				
				printf("select x and y axises respectively in each line to move for >>\n");
				scanf("%d%d",&t_x,&t_y);
			
				a = move(board,f_x,f_y,t_x,t_y,black);//calling function move.
								
				if (a >= 0){

					nth_time_cap = a;//how many times capturing happened
					printf("%d pieces of capturing have happened \n",nth_time_cap);
				}
				else if (a == -1)
					printf("the piece is not belong to you!!!\n");//when turn is -1.
				else if (a == -2)
					printf("move is not allowed!!!\n");
			}

		}while(end_of_game_checker == -1 ||winner !=white ||winner != black);//inner do while to check and execute and give turn to the both players.
	
	}while(end_of_game_checker == -1 ||winner !=white ||winner != black );//do while to check.
}

int move(piece board[][8], int from_x, int from_y, int to_x, int to_y, player p){

	int flag = 0,moves_allowed = 0,counter = 0,next_step,moves,captures = 0,i,j,k,l;	
	piece temp;//enum type variable decleration.

	if(board[from_y][from_x] == white_man && p == black_man)//condition to check whether the axises and player turns match or not.
		flag = -1;//controls the unrelated choise of player.

	else if (board[from_y][from_x] == black_man  && p == 10)//condition to check whether the axises and player turns match or not.
		flag = -1;//controls the unrelated choise of player.
	
	 if(board[from_y][from_x] == white_man||board[from_y][from_x] == white_king && flag != -1)//condition to move white_man pieces
		move_player_white(board,from_x,from_y,to_x,to_y,p,flag,&moves_allowed,&captures);	
	
	else if (flag != -1 && board[from_y][from_x] == black_man)// move black_player's pieces
		move_player_black(board,from_x,from_y,to_x,to_y,p,flag,&moves_allowed,&captures);
	
	else if (flag == -1)//condition to error accurence of unrelated turn.
		next_step = flag;

	else if (flag !=-1 && moves_allowed == 0 )//condition to show move has accured.
		next_step = -2; 

	else if (flag !=-1 && moves_allowed !=0 )//condition to show that how many captures have executed
		next_step = captures;

	return next_step;
}//end of move function.

void move_player_white(piece board[][8],int from_x, int from_y, int to_x, int to_y, player p,int flag,int *move_allowed,int *capture){

	int move_is_allowed = 0,counter = 0,moves = 0,test_capture = 0,i=0,j=0,k=0,l=0;
	piece temp;//enum type variable decleration.

	do{

		moves = counter;//assignign the counter's value to moves variable.
		
		for (i = 0; i < 1; i++){//condition to be a king player
	  		
		  		for ( j = 0; j < 8; j++){

		  			if (board[i][j] == white_man)
		  				board[i][j] = white_king;
		  		}
	  	}

	  	if (from_x+1==to_x||from_x-1==to_x||from_y-1==to_y || (board[from_y][from_x+1]==empty||from_x-1==empty||from_y-1==empty)||(board[from_y][from_x+1]==black_man&&board[from_y][from_x+2]==empty)||(board[from_y][from_x-1]==black_man && board[from_y][from_x-2]==empty)||(board[from_y-1][from_x]==black_man&&board[from_y-2][from_x]==empty)){

		  	if (board[from_y][from_x]==white_king){//condition to move the white king to the right.
		  	
	  			for (i = 0; i < 8 ; i++){//to find the first black in right side
	  		
	  				if (board[from_y][from_x+i]==black_man||board[from_y][from_x+i]==black_king){
	  					
	  					temp=board[from_y][from_x];
	  					board[from_y][from_x]=board[from_y][from_x+i+1];
	  					board[from_y][from_x+i+1]=temp;
	  					board[from_y][from_x+i] = empty;
	  				}

	  			}
	  			for (i = 0; i < 8 ; i++){//find the first black in left side
	  			
	  				if (board[from_y][from_x-i]==black_man||board[from_y][from_x-i]==black_king){
	  					
	  					temp=board[from_y][from_x];
	  					board[from_y][from_x]=board[from_y][from_x+i+1];
	  					board[from_y][from_x+i+1]=temp;
	  					board[from_y][from_x+i] = empty;
	  				}

	  			}
	  			 for( i = 0; i < 8;i++){//find the first black in down ward.
	  			
	  				if (board[from_y-i][from_x]==black_man||board[from_y-i][from_x]==black_king){
	  				
	  					temp=board[from_y][from_x];
	  					board[from_y][from_x]=board[from_y-i-1][from_x];
	  					board[from_y-i-1][from_x]=temp;
	  					board[from_y-i][from_x] = empty;
	  				}
	  			}
	  			
	  			for (i = 0; i < 8;i++){//find the first black in down ward.
	  			
	  				if (board[from_y+i][from_x]==black_man||board[from_y+i][from_x]==black_king){
	  			
	  					temp=board[from_y][from_x];
	  					board[from_y][from_x]=board[from_y+i+1][from_x];
	  					board[from_y+i+1][from_x]=temp;
	  					board[from_y+i][from_x] = empty;
	  				}
	  			}
		  	}

			if (board[from_y][from_x+1] == empty && board[from_y][from_x+1] == board[to_y][to_x]){//condition to move right.
				
				move_is_allowed =1;//condition  to show move has executed.
				temp = board[from_y][from_x];
				board[from_y][from_x] = board[to_y][to_x];			  	
			  	board[to_y][to_x] = temp;
			  	counter = counter +1;///how many moves from one side in one turn has executed.
			}

			else if (board[from_y][from_x+1] == black_man && board[from_y][from_x+2]== empty){//condition to move right and capture the encounterd opposite player.
			 		
			    move_is_allowed =1;//condition  to show move has executed.

				temp = board[from_y][from_x];
				board[from_y][from_x] = board[from_y][from_x+2];		
				board[from_y][from_x+2] = temp;		
				board[from_y][from_x+1] = empty;
				test_capture++;
				
				*capture = test_capture;//condition to how many captures has executed
				counter = counter +1;
			}

			else if (board[from_y][from_x-1] == empty && board[from_y][from_x-1]==board[to_y][to_x]){//condition to move left.
			
				move_is_allowed= 1;//condition  to show move has executed.

				temp = board[from_y][from_x];
				board[from_y][from_x] = board[to_y][to_x];		  	
			  	board[to_y][to_x] = temp;
			  	
			  	counter = counter +1;///how many move from one side in one turn has executed.

			}
			else if (board[from_y][from_x-1] == black_man && board[from_y][from_x-2]== empty){//condition to move left and capture the encounterd opposite player.
			
			    move_is_allowed = 1;//condition  to show move has executed.
			    temp=board[from_y][from_x];
			    board[from_y][from_x]=board[from_y][from_x-2];
			    board[from_y][from_x-2]=temp;
			    board[from_y][from_x-1]= empty;
				test_capture++;
				*capture = test_capture;//condition to how many captures has executed
				counter = counter +1;
			}

			else if ((board[from_y-1][from_x] == empty )&& (board[from_y-1][from_x]==board[to_y][to_x]) ||( board[from_y-2][from_x] == empty) && (board[from_y-2][from_x] == board[to_y][to_x] )&&(board[from_y-1][from_x] == white_man) &&(board[to_y][to_x]!=board[from_y+1][from_x])){//condition to move up.
				
	            move_is_allowed;//condition  to show move has executed.
				
				temp = board[from_y][from_x];
				board[from_y][from_x] = board[to_y][to_x];			  	
			  	board[to_y][to_x] = temp;			  	
			  	
			  	counter = counter +1;//how many move from one side in one turn has executed.	  	
			}
			else if (board[from_y-1][from_x] == black_man && board[from_y-2][from_x]== empty){//condition to move up and capture the encounterd opposite player.
			
	            move_is_allowed = 1;//condition  to show move has executed.
				
				temp = board[from_y][from_x];//put the white to temp		
			 	board[from_y][from_x] = board[from_y-2][from_x];//put the empty to white's palce			
				board[from_y-2][from_x] = temp;//put the temp to the empty's place
				board[from_y-1][from_x] = empty;//put the empty to the place of black_man;

			  	test_capture++;
				*capture =test_capture;//condition to how many captures has executed
				counter = counter +1;
			}
		}
		else
			move_is_allowed = 0;
	
	}while (counter != moves);//if some of the execution inside the do while has accured so continue.		

	if (move_is_allowed == 1){
		*move_allowed = move_is_allowed;
	}
	else if (move_is_allowed ==0){
		*move_allowed = move_is_allowed;
	}	
} //end of fucntion move_white_player.

void move_player_black(piece board[][8],int from_x, int from_y, int to_x, int to_y, player p,int flag,int *move_allowed,int *capture){

	int move_is_allowed = 0,counter = 0,moves,test_capture = 0,i,j,k,l;	
	piece temp;//enum type variable decleration.
			
	do{
	
		moves = counter;//assigning the counter's value to moves variable.
		
		for (i = 7; i <8; i++){//condition to be a king player
	  		for ( j = 0; j < 8; j++){
	  		
	  			if (board[i][j] == black_man){
	  				board[i][j] = black_king;
	  			}
	  		}
	  	}

	  	if (board[from_y][from_x]==black_king){//condition to move the white king to the right.

  			for (i = 0; i < 8 ; i++){//to find the first black in right side
  			
  				if (board[from_y][from_x+i]==white_man||board[from_y][from_x+i]==white_king){
  				
  					temp=board[from_y][from_x];
  					board[from_y][from_x]=board[from_y][from_x+i+1];
  					board[from_y][from_x+i+1]=temp;
  					board[from_y][from_x+i] = empty;
  				}

  			}
  			for (i = 0; i < 8 ; i++){//find the first black in left side
  			
  				if (board[from_y][from_x-i]==white_man||board[from_y][from_x-i]==white_king){
  					temp=board[from_y][from_x];
  					board[from_y][from_x]=board[from_y][from_x+i+1];
  					board[from_y][from_x+i+1]=temp;
  					board[from_y][from_x+i] = empty;
  				}

  			}
  			 for( i = 0; i < 8;i++){//find the first black in down ward.
  			
  				if (board[from_y-i][from_x]==white_man||board[from_y-i][from_x]==white_king){
  			
  					temp=board[from_y][from_x];
  					board[from_y][from_x]=board[from_y-i-1][from_x];
  					board[from_y-i-1][from_x]=temp;
  					board[from_y-i][from_x] = empty;
  				}
  			}
  			
  			for (i = 0; i < 8;i++){//find the first black in down ward.
  			
  				if (board[from_y+i][from_x]==white_man||board[from_y+i][from_x]==white_king){
  				
  					temp=board[from_y][from_x];
  					board[from_y][from_x]=board[from_y+i+1][from_x];
  					board[from_y+i+1][from_x]=temp;
  					board[from_y+i][from_x] = empty;
  				}
  			}
	  	} 

		if(board[from_y][from_x+1]== empty && board[from_y][from_x+1] == board[to_y][to_x]&&(board[from_y][from_x]==black_man||board[from_y][from_x]==black_king)){//condition to move right.

			move_is_allowed = 1;//condition  to show move has executed.		
			temp = board[from_y][from_x];
			board[from_y][from_x] = board[to_y][to_x];		  	
		  	board[to_y][to_x] = temp;
		  	
		  	counter = counter +1;//how many move from one side in one turn has executed.
		}
		else if (board[from_y][from_x+1] == white_man||board[from_y][from_x+1]== white_king && board[from_y][from_x+2]== empty){//condition to move right and capture the encounterd opposite player.

			move_is_allowed = 1;//condition  to show move has executed.
			
			temp = board[from_y][from_x];
			board[from_y][from_x]= board[from_y][from_x+2];
			board[from_y][from_x+2] = temp;
			board[from_y][from_x+1] = empty;
		
			*capture++;//condition to how many captures has executed
			counter = counter +1;
		}

		else if (board[from_y][from_x-1] == empty && board[from_y][from_x-1]==board[to_y][to_x]){//condition to move left.

			move_is_allowed = 1;//condition  to show move has executed.
				
			temp = board[from_y][from_x];
			board[from_y][from_x] = board[to_y][to_x];	
		  	board[to_y][to_x] = temp;

		  	counter = counter +1;//how many move from one side in one turn has executed.

		}
		else if (board[from_y][from_x-1] == white_man ||board[from_y][from_x-1] == white_king && board[from_y][from_x-2]== empty){//condition to move left and capture the encounterd opposite player.
			
			move_is_allowed = 1;//condition  to show move has executed.

			temp = board[from_y][from_x];
			board[from_y][from_x]= board[from_y][from_x-2];
			board[from_y][from_x-2] = temp;
			board[from_y][from_x-1] = empty;

			*capture++;//condition to how many captures has executed
			counter = counter +1;
		
		}
		else if ((board[from_y+1][from_x]==empty && board[from_y+1][from_x]==board[to_y][to_x])||(board[from_y+2][from_x] == empty && board[from_y+2][from_x] == board[to_y][to_x] && board[from_y+1][from_x] == white_man || board[from_y+1][from_x] ==white_king)&&board[to_y][to_x]!=board[from_y-1][from_x]){//condition to move down.					
        
            move_is_allowed = 1;//condition  to show move has executed.
			temp = board[from_y][from_x];
			board[from_y][from_x] = board[to_y][to_x];		  	
		  	board[to_y][to_x] = temp;
		  	
		  	counter = counter +1;//how many move from one side in one turn has executed.

		}
		else if (board[from_y+1][from_x] == white_man ||board[from_y+1][from_x] == white_king && board[from_y+2][from_x]== empty){//condition to move down and capture the encounterd opposite player.

           	move_is_allowed = 1;//condition  to show move has executed.

           	temp = board[from_y][from_x];
           	board[from_y][from_x]=board[to_y][to_x];
           	board[to_y][to_x] = temp;
           	board[from_y+1][from_x]= empty;
			
			*capture++;//condition to how many captures has executed
			counter = counter +1;
			
		}

	}while(moves!=counter);//if some of the execution inside the do while has accured so continue.			
		
	if (move_is_allowed == 1)
		*move_allowed = move_is_allowed;
	else if (move_is_allowed ==0)
		*move_allowed = move_is_allowed;
}
int check_end_of_game(piece board[][8]){

	int i,j,end_of_game = 1;

	for ( i = 0; i < 8; i++){

		for (j = 0; j < 8; j++){
		
			if ((board[i][j] == white_man || board[i][j] == white_king)&& (board[i][j]!=black_man && board[i][j] != black_king))//condition to check whether the table is empty or not we assume that table still has elements whith is essintially
				end_of_game = -1;
			else if ((board[i][j] == black_man || board[i][j]==black_king) && (board[i][j]!=white_man && board[i][j]!=white_king))
				end_of_game = -1;
		}
	}
	return end_of_game;
}
void init_board(piece board[][8]){//function creates game_board.

	int i,j;
	
	for (i = 0; i < 8; i++){

	    	for ( j = 0;j < 8 ;j++){
	    	
	    		if (i == 0||i == 3||i == 4||i == 7 )//condition to print charachter'-',
	    			board[i][j] = empty;
	    		else if (i == 1 ||i == 2 )//condition to print charachter'b'.
	    			board[i][j] = black_man;
	    		else if (i == 5||i == 6)//condition to print charachter 'w'.
	    			board[i][j] = white_man;
	    	}
	    }		                
}

void display_board(piece board[][8]){//function displays the table as a current sectuation.
	
	int i,j;
	printf("***TURKISH CHECKERS GAME***\n");
	printf("_________________________\n");

	for (i = 0; i < 8; i++){//outer loop to check the rows of the called array
		
			printf("%d ",i);
			for ( j = 0; j < 8 ;j++){//inner loop to check the columns of the array.
			
				
				if (board[i][j] == empty)
					printf(" - ");
				else if (board[i][j] == black_man)
					printf(" b ");
			    else if (board[i][j] == white_man)
					printf(" w ");
				else if (board[i][j] == black_king)
					printf(" B ");
				else if (board[i][j] == white_king)
					printf(" W ");
			}
			printf("\n");
		}

		printf("   " );
		for ( i = 7; i < 8; ++i){
			for ( j = 0; j < 8 ; ++j){
				printf("%d  ",j);
			}
		}
		printf("\n_________________________\n");
}