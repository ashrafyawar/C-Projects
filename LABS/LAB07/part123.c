#include<stdio.h>
#include<math.h>
typedef enum{wall = 0,space,start,finish}cell;
void init_maze01(int maze01[][8],int size);
void init_maze02(int maze02[][10],int size);
void show_maze(char maze[][8],int size);

int main(){

    int maze01[8][8];
    int maze02[10][10];
    init_maze01(maze01,8);
    
    init_maze02(maze02,10);
	show_maze(init_maze01,8);

	return 0;
}

void init_maze01( int maze01[][8],int size){

	int i,j,k,l;

	for (k = 0; k < size; k++){

		for (l = 0; l < size;l++){
			maze01[k][l] = 0;
		}
	}
	maze01[0][0]= wall;
	maze01[0][1]=wall;
	maze01[0][2]=wall;
	maze01[0][3]=wall;
	maze01[0][4]=wall;
	maze01[0][5]=wall;
	maze01[0][6]=finish;
	maze01[1][0]=wall;
	maze01[1][4]=wall;
	maze01[1][7]=wall;
	maze01[2][0]=wall;
	maze01[2][2]=space;
	maze01[2][4]=wall;
	maze01[2][7]=wall;
	maze01[3][0]=wall;
	maze01[3][2]=wall;
	maze01[3][3]=start;
	maze01[3][4]=wall;
	maze01[3][7]=wall;
	maze01[4][0]=wall;
	maze01[4][2]=wall;
	maze01[4][5]=wall;
	maze01[4][7]=wall;
	maze01[5][0]=wall;
	maze01[5][2]=wall;
	maze01[5][3]=wall;
	maze01[5][5]=wall;
	maze01[5][7]=wall;
	maze01[6][0]=wall;
	maze01[6][7]=wall;
	maze01[7][0]=wall;
	maze01[7][1]=wall;
	maze01[7][2]=wall;
	maze01[7][3]=wall;
	maze01[7][4]=wall;
	maze01[7][5]=wall;
	maze01[7][6]=wall;
	maze01[7][7]=wall;

	for ( i = 0; i < size; i++){
		for (j = 0; j < size;j++)
			printf("%d ",maze01[i][j]);
		printf("\n" );
	}
}
void init_maze02(int maze02[][10],int size){
	
	int i,j,k,l;

	for (k = 0; k < size; k++){
		for (l = 0; l < size;l++)
			maze02[k][l] = 0;
	}	 
	maze02[0][0] = 0;
	 maze02[0][1] = 0;
	maze02[0][2] = 0;
	maze02[0][3] = 0;
	maze02[0][4] = 0;
	maze02[0][5] = 0;
	maze02[0][6] = 0;
	maze02[0][7] = 0;
	maze02[0][8] = 0;
	maze02[0][9] = 0;
	maze02[1][0] = 0;
	maze02[1][1] = 'S';
	maze02[1][2] = 0;
	maze02[1][7] = 0;
	maze02[1][9] = 0;
	maze02[2][0] = 0;
	maze02[2][2] = 0;
	maze02[2][4] = 0;
	maze02[2][6] = 0;
	maze02[2][8] = 0;
	maze02[2][9] = 0;
	maze02[3][0] = 0;
	maze02[3][4] = 0;
	maze02[3][6] = 0;
	maze02[3][9] = 0;
	maze02[4][0] = 0;
	maze02[4][2] = 0;
	maze02[4][4] = 0;
	maze02[4][9] = 0;
	maze02[5][0] = 0;
	maze02[5][2] = 0;
	maze02[5][4] = 0;
	maze02[5][5] = 0;
	maze02[5][7] = 0;
	maze02[5][9] = 0;
	maze02[6][0] = 0;
	maze02[6][2] = 0;
	maze02[6][5] = 0;
	maze02[6][7] = 0;
	maze02[6][9] = 'F';
	maze02[7][0] = 0;
	maze02[7][2] = 0;
	maze02[7][3] = 0;
	maze02[7][5] = 0;
	maze02[7][6] = 0;
	maze02[7][7] = 0;
	maze02[7][9] = 0;
	maze02[8][0] = 0;
	maze02[8][4] = 0;
	maze02[8][9] = 0;
	maze02[9][0] = 0;
	maze02[9][1] = 0;
	maze02[9][2] = 0;
	maze02[9][3] = 0;
	maze02[9][4] = 0;
	maze02[9][5] = 0; 
	maze02[9][6] = 0; 
	maze02[9][7] = 0; 
	maze02[9][8] = 0; 
	maze02[9][9] = 0; 

	for ( i = 0; i < size; i++){
		for (j = 0; j < size;j++)
			printf("%c ",maze02[i][j]);
		printf("\n" );
	}
}
void show_maze(char maze[][8],int size){

	int i,j;
	for (int i = 0; i < size; ++i){

		for (int i = 0; i < size; ++i){
			
			if (maze[i][j] == wall){
				printf("*");
			}
			if (maze[i][j] == finish){
				printf("F");
			}
			if (maze[i][j] == space){
				printf("S");
			}
		}
	printf("\n");
	}
}
