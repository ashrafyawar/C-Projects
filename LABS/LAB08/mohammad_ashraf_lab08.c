#include <stdio.h>


void pretty_print(int grid[][9]);
int is_valid_row(int grid[][9], int row);
int is_valid(int grid[][9]);
int is_valid_column(int grid[][9], int col);
int is_valid_block(int grid[][9], int r, int c);

void read_a_solution(int grid [][9], char * file_name);
void print_board(int grid[][9]);
void test_game(char * file_name);


int main(){

	test_game("game001.txt");	
	test_game("game002.txt");
	
	//pretty_print();
}


void pretty_print(int grid[][9]) {
	
	/* complete this */
	int i ,j,k,sum = 1,sum1 =0;

	for ( i = 0; i < 9; ++i){

		if (i==0||i==3||i==6||i>=9){

			printf(" -----------------------\n");
		}
		
		printf("|");
		
		if (sum==4||sum==8||sum==12){
			printf("|");
			sum = sum +2;
		}

		for ( j = 0; j < 9; ++j){
			
			if (j==3||j==6||j==9){
				printf("|");
			}

			printf(" %d",grid[i][j] );
		}

		printf(" |");
		printf("\n");
	}
	printf(" -----------------------\n");	
}

int is_valid_row(int grid[][9], int row){
 	
 	int flag = 0;
 	int digits[10][10],i,j;
	
	for ( i = 0; i <10 ; ++i){
		for ( j = 0; j < 10 ; ++j)
			digits[i][j];
	}

	for ( i = 0; i < 9; ++i){
	 	if (grid[i][i]!=digits[i][i]&&grid[i][i])	 		
	 		flag = 1;
	 } 
	return flag;
}


int is_valid_column(int grid[][9], int col){
	
 	int flag = 0;
 	int digits[10][10],i,j;
	
	for ( i = 0; i <10 ; ++i){
		for ( j = 0; j < 10 ; ++j)
			digits[i][j];
	}

	for ( i = 0; i < 9; ++i){
	 	
	 	for(j = 0;j<9;j++){
		 	if (grid[i][j]!=digits[i][j]&&grid[i][j])
		 		flag = 1;
		}
	 } 
	 return flag;
}


int is_valid_block(int grid[][9], int r, int c) {

	int flag = 0;

	for (i = 0; i < 3; ++i){
	
		for ( j = 0; j < 3; ++j){
			
			if (grid[i][j] == )
				flag = 1;
		}	
	}
	return flag;
}

int is_valid(int grid[][9]){
	
	int a,b,c, flag = 0;
	 a = is_valid_row();
	 return flag;
}


void read_a_solution(int grid [][9], char * file_name){
	
	FILE * fin;
    int i, j;

	fin = fopen(file_name, "rt");
	if (fin==NULL) {
		printf("Cannot open file %s for reading the game...\n", file_name);
	}
	else {
	    for (i = 0; i < 9; i++)
	        for (j = 0; j < 9; j++)
	            fscanf(fin, "%d", &grid[i][j]);
	}
}

void print_board(int grid[][9]){

    int i, j;

	for (i = 0; i < 9; i++){
        for (j = 0; j < 9; j++){
            printf("%d ", grid[i][j]);
		}
		printf("\n");
	}
}

void test_game(char * file_name){

    int grid[9][9];
	
	printf("Testing game in %s.............................\n", file_name);
    
    read_a_solution(grid, file_name);
	pretty_print(grid);
	
	print_board(grid);
    
    if (is_valid(grid))
       printf("Valid solution\n");
    else
		printf("Invalid solution\n");
}
