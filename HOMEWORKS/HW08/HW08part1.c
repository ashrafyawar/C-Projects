#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
struct block{

		char text[10];
		int data;
		char type;
		int pos_X,pos_y,jump_x,jump_y;
};

typedef enum{M,B,P,S,T}types; 		
void initialize_board(struct block board[][10]);
void print_block_board(struct block board[][10]);
int play_game(struct block board[][10],int current_position,int previous_position,int total_counter);
void game_controller(struct block board[][10]);
int numberGeneratorBetweenRange(int min, int max);
int main(){

	srand(time(NULL));//random number genarator.
	struct block board[10][10];// struct block type 
	game_controller(board);//calling the function

}//end of main function.
void game_controller(struct block board[][10]){//this funtion calls the player function twise one for the player one the other one for the player two and then prints the winnner

	int i=0,p1,p2,j,winner1,winner2;
	
	print_block_board(board);//calling function print_board.

	p1 = board[9][9].data;//initialising the player one's position.
	p2 = board[9][9].data;//initialising the player two's position.
	printf("            ****** THE DICING GAME ******\n");
	printf("<<<PLAYER_ONE >>>\n");
	printf("STARTING THE DICING GAME ...\n");

	winner1 = play_game(board,p1,0,0);//calling the function the function play_game. 
	
	printf(">>> %d  attemps has accured to reach the 100 number block <<<\n",winner1);
	printf("__________________________________________________\n");
	printf("<<<PLAYER_TWO >>>\n");
	printf("STARTING THE DICING GAME ...\n");

	winner2 = play_game(board,p2,0,0);//calling the function play_game
	
	printf(">> %d  attemps has accured to reach the 100 number block <<\n",winner2);
	printf("attempting to find the winner...\n\n");

	if (winner1 < winner2){
		printf("THE WINNER IS PLAYER ONE IN %d ATTEMPTS !!!\n",winner1);
	}
	else if (winner2 < winner1 ){
		printf("THE WINNER IS PLAYER_TWO IN %d ATTEMPTS !!!\n",winner2);
	}
	else if (winner1 == winner2){
		printf("NO WINNER !!!\n");
	}

}//end of the function game_countroller
int play_game(struct block board[][10],int current_position,int previous_position,int total_counter){//this function uses the recuisin to reach the 100 blosk as qiuk as possible by generating ramdom numbers in each inner calllin.and returns the counts of the attemps of the each player to the game controller functions.
	
	int randum,i,j,counter = 0,result;
	
	previous_position = current_position;//kepping the current to be used bellow.
	
	counter =  total_counter;//kepping the previous counter in memory.

	if (current_position == 100){//this is the base case to stop the loop.
		result = counter;
		printf(" current_position is %d\n",current_position );
		return result;
	}

	else{
		
		randum = numberGeneratorBetweenRange(1,6);//calling function to generate number.	
		current_position = current_position + randum;//the new position tobe gone.
				
		/*in bellow all the if and else condtions are used to check the player position and analyse it and move to the corresponting position that block have required.*/	
		if (current_position == 6 ){

			current_position = 1;
			counter++;
		}
		else if (current_position == 7){

			current_position = 11;
			counter++;
		}
		else if (current_position==13){

			current_position = previous_position;
		}
		else if (current_position == 17){

			current_position = 28;
			counter++;
		}
		else if (current_position == 25){

			current_position = 12;
			counter++;

		}
		else if (current_position==29){

			current_position = current_position +5;
			counter++;
		}
		else if (current_position== 32){

			current_position = 52;
			counter++;
		}
		else if(current_position==36){

			current_position = current_position +5;
			counter++;
		}
		else if (current_position == 40){

			current_position = current_position-5;
			counter++;
		}
		else if (current_position ==45){

			current_position = 22;
			counter++;
		}
		else if (current_position==48){

			current_position = previous_position;
		
		}
		else if (current_position == 50){

			current_position = current_position+5;
			counter++;
		}
		else if (current_position==54){

			current_position=current_position-5;
			counter++;
		}
		else if (current_position==57){

			current_position=77;
			counter++;
		}
		else if (current_position==60){

			current_position = 44;
			counter++;
		}
		else if (current_position==63){
			
			current_position  = 52;
			counter++;
		}
		else if (current_position==66){
			
			current_position= current_position+5;
			counter++;
		}
		else if (current_position==69){

			current_position = 77;
			counter++;
		}
		else if (current_position==73){

			current_position =68;
			counter++;
		}
		else if (current_position==76){

			current_position = 83;
			counter++;
		}
		else if (current_position == 79){

			current_position = current_position-5;
			counter++;
		}
		else if (current_position ==82 ){

			current_position=current_position+5;
			counter++;
		}
		else if (current_position==85){

			current_position = previous_position;
		}
		else if (current_position==89){

			current_position=94;
			counter++;
		}
		else if (current_position==93){

			current_position=current_position-5;
			counter++;
		}
		else if (current_position==98){

			current_position= 72;
			counter++;
		}
		else if (current_position==99){

			current_position = 56;
			counter++;
		}
		else if (current_position > 100){

			current_position = previous_position;
			counter++;
		}
		else{

			counter++;
		}

		result = play_game(board,current_position,previous_position,counter);//calling the function it self reciussivly.
		
		//previous_position = previous_position + randum;
		printf(" current_block is >> %d  diced number is >> %d  so moving to block >> %d \n",previous_position,randum,current_position);//printing the currenc position and the position where we attempting to move to.
	}
	return result;
}//end of paly_game function.
int numberGeneratorBetweenRange(int min, int max){//function defination of number generator between two numbers.

 	int difference,random,modules,random_enteger;
	random = rand();
	difference = max - min;//difference of maximum number and minimum number
	modules = random % difference;//find the modules of the generated number with respect to difference number. 
	random_enteger = modules + min;

	return(random_enteger);//returns the a generated number between max and min number.

 }//end of number_generator_between_range function.
void print_block_board(struct block board[][10]){//this function prints the boardas required.

	int i,j;
	initialize_board(board);//calling function initialize_board function.
	
	printf("            ****** THE DICING GAME_BOARD ******\n");
	printf("________________________________________________________________________________________________\n");

	for (i = 0; i < 10; i++){

		for ( j = 0; j < 10 ; j++){
			
			if (board[i][j].data == 1){

				strcpy(board[i][j].text,"START"); 
				printf("%-10s",board[i][j].text);
			}
			else if ( board[i][j].data == 6){

				strcpy(board[i][j].text,"S{1}");
				printf("%-10s",board[i][j].text); 
			}
			else if ( board[i][j].data == 7){

				strcpy(board[i][j].text,"M{11}");
				printf("%-10s",board[i][j].text); 

			}
			else if ( board[i][j].data ==13){

				board[i][j].type = 'P';
				printf("%-10c",board[i][j].type);
			}
			else if (board[i][j].data ==17){

				strcpy(board[i][j].text,"M{28}");
				printf("%-10s",board[i][j].text); 

			}
			else if (board[i][j].data ==25){

				strcpy(board[i][j].text,"S{12}");
				printf("%-10s",board[i][j].text); 

			}
			else if (board[i][j].data ==29){

				board[i][j].type = 'B';
				printf("%-10c",board[i][j].type);
			}
			else if (board[i][j].data ==32){

				strcpy(board[i][j].text,"M{52}");
				printf("%-10s",board[i][j].text); 

			}
			else if (board[i][j].data ==36){

				board[i][j].type = 'B';
				printf("%-10c",board[i][j].type);
			}
			else if (board[i][j].data ==40){

				board[i][j].type = 'T';
				printf("%-10c",board[i][j].type);
			}
			else if (board[i][j].data ==45){

				strcpy(board[i][j].text,"S{22}");
				printf("%-10s",board[i][j].text); 

			}
			else if (board[i][j].data ==48){

				board[i][j].type = 'P';
				printf("%-10c",board[i][j].type);
			}
			else if (board[i][j].data ==50){

				board[i][j].type = 'B';
				printf("%-10c",board[i][j].type);
			}
			else if (board[i][j].data ==54){

				board[i][j].type = 'T';
				printf("%-10c",board[i][j].type);
			}
			else if (board[i][j].data ==57){

				strcpy(board[i][j].text,"M{77}");
				printf("%-10s",board[i][j].text); 
			}
			else if (board[i][j].data ==60){

				printf("S{44}");
			}
			else if (board[i][j].data ==63){

				strcpy(board[i][j].text,"S{52}");
				printf("%-10s",board[i][j].text); 

			}
			else if (board[i][j].data ==66){

				board[i][j].type = 'B';
				printf("%-10c",board[i][j].type);
			}
			else if (board[i][j].data ==69){

				strcpy(board[i][j].text,"M{77}");
				printf("%-10s",board[i][j].text); 

			}
			else if (board[i][j].data ==73){

				strcpy(board[i][j].text,"S{68}");
				printf("%-10s",board[i][j].text); 

			}
			else if (board[i][j].data ==76){

				strcpy(board[i][j].text,"M{83}");
				printf("%-10s",board[i][j].text); 

			}
			else if (board[i][j].data ==79){

				board[i][j].type = 'T';
				printf("%-10c",board[i][j].type);
			}
			else if (board[i][j].data ==82){

				board[i][j].type = 'B';
				printf("%-10c",board[i][j].type);
			}
			else if (board[i][j].data ==85){

				board[i][j].type = 'P';
				printf("%-10c",board[i][j].type);
			}
			else if (board[i][j].data ==89) {

				strcpy(board[i][j].text,"M{94}");
				printf("%-10s",board[i][j].text); 

			}
			else if (board[i][j].data ==93){

				board[i][j].type = 'T';
				printf("%-10c",board[i][j].type);
			}
			else if (board[i][j].data == 98){

				strcpy(board[i][j].text,"S{72}");
				printf("%-10s",board[i][j].text); 

			}
			else if (board[i][j].data ==99){

				strcpy(board[i][j].text,"S{56}");
				printf("%-10s",board[i][j].text); 

			}
			else if (board[i][j].data ==100){

				strcpy(board[i][j].text,"FINISH");
				printf("%-10s",board[i][j].text); 

			}
			else {

				printf("%-10d",board[i][j].data);
			}
			
		}
		printf("\n");

	}
	printf("________________________________________________________________________________________________\n");
}//end of print_board function._
void initialize_board(struct block board[][10]){//this function initialise's the structed block board.

	int counter = 0,i,j,k;

	for (i = 0; i < 10; i++){
		
		if (i == 0){

			counter = 91;
			for ( k = 0; k <10 ;++k){
			
				board[i][k].data = counter;
				counter++;		
			}
		}
		else if (i == 1){
			counter = 90;
			for ( j = 0; j < 10 ;++j){
			
				board[i][j].data = counter;
				counter--;		
			}
		}
		else if (i==2){
			
			counter = 71;
			for ( k = 0; k <10 ;++k){

				board[i][k].data = counter;
				counter++;		
			
			}
		}
		else if (i == 3){

			counter = 70;
			for ( j = 0; j < 10 ;++j){
			
				board[i][j].data = counter;
				counter--;		
			}
		}
		else if (i==4){

			counter = 51;
			for ( k = 0; k <10 ;++k){
			
				board[i][k].data = counter;
				counter++;		
			}
		}
		else if (i == 5){

			counter = 50;
			for ( j = 0; j < 10 ;++j){
			
				board[i][j].data = counter;
				counter--;		
			}
		}
		else if (i==6){

			counter = 31;
			for ( k = 0; k <10 ;++k){
			
				board[i][k].data = counter;
				counter++;		
			}
		}
		else if (i == 7){
			
			counter = 30;
			for ( j = 0; j < 10 ;++j){
			
				board[i][j].data = counter;
				counter--;		
			}
		}
		else if (i==8){

			counter = 11;
			for ( k = 0; k < 10 ;++k){
			
				board[i][k].data = counter;
				counter++;		
			}
		}
		else if (i == 9){

			counter = 10;
			for ( j = 0; j < 10 ;++j){
			
				board[i][j].data = counter;
				counter--;		
			}
		}
	}
}