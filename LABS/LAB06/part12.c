#include<stdio.h>
#include<math.h>
void init_maze01(char maze01[][8],int size);
void init_maze02(char maze02[][10],int size);
/*typedef enum{wall,space,s,f};
type_enum;*/
int main(){

    char maze01[8][8];
    char maze02[10][10];
    init_maze01(maze01,8);
    init_maze02(maze02,10);
	return 0;
}

void init_maze01( char maze01[][8],int size){
	
	int i,j,k,l;

	for (k = 0; k < size; k++){
		for (l = 0; l < size;l++)
			maze01[k][l] = 0;
	}
	maze01[0][0]='*';
	maze01[0][1]='*';
	maze01[0][2]='*';
	maze01[0][3]='*';
	maze01[0][4]='*';
	maze01[0][5]='*';
	maze01[0][6]='F';
	maze01[1][0]='*';
	maze01[1][4]='*';
	maze01[1][7]='*';
	maze01[2][0]='*';
	maze01[2][2]='*';
	maze01[2][4]='*';
	maze01[2][7]='*';
	maze01[3][0]='*';
	maze01[3][2]='*';
	maze01[3][3]='S';
	maze01[3][4]='*';
	maze01[3][7]='*';
	maze01[4][0]='*';
	maze01[4][2]='*';
	maze01[4][5]='*';
	maze01[4][7]='*';
	maze01[5][0]='*';
	maze01[5][2]='*';
	maze01[5][3]='*';
	maze01[5][5]='*';
	maze01[5][7]='*';
	maze01[6][0]='*';
	maze01[6][7]='*';
	maze01[7][0]='*';
	maze01[7][1]='*';
	maze01[7][2]='*';
	maze01[7][3]='*';
	maze01[7][4]='*';
	maze01[7][5]='*';
	maze01[7][6]='*';
	maze01[7][7]='*';
		
	for ( i = 0; i < size; i++){
		for (j = 0; j < size;j++)
			printf("%c",maze01[i][j]);
		printf("\n" );
	}
}
void init_maze02(char maze02[][10],int size){

	int i,j,k,l;

	for (k = 0; k < size; k++){
		for (l = 0; l < size;l++)
			maze02[k][l] = 0;
	}	 

	maze02[0][0] = '*';
	maze02[0][1] = '*';
	maze02[0][2] = '*';
	maze02[0][3] = '*';
	maze02[0][4] = '*';
	maze02[0][5] = '*';
	maze02[0][6] = '*';
	maze02[0][7] = '*';
	maze02[0][8] = '*';
	maze02[0][9] = '*';
	maze02[1][0] = '*';
	maze02[1][1] = 'S';
	maze02[1][2] = '*';
	maze02[1][7] = '*';
	maze02[1][9] = '*';
	maze02[2][0] = '*';
	maze02[2][2] = '*';
	maze02[2][4] = '*';
	maze02[2][6] = '*';
	maze02[2][8] = '*';
	maze02[2][9] = '*';
	maze02[3][0] = '*';
	maze02[3][4] = '*';
	maze02[3][6] = '*';
	maze02[3][9] = '*';
	maze02[4][0] = '*';
	maze02[4][2] = '*';
	maze02[4][4] = '*';
	maze02[4][9] = '*';
	maze02[5][0] = '*';
	maze02[5][2] = '*';
	maze02[5][4] = '*';
	maze02[5][5] = '*';
	maze02[5][7] = '*';
	maze02[5][9] = '*';
	maze02[6][0] = '*';
	maze02[6][2] = '*';
	maze02[6][5] = '*';
	maze02[6][7] = '*';
	maze02[6][9] = 'F';
	maze02[7][0] = '*';
	maze02[7][2] = '*';
	maze02[7][3] = '*';
	maze02[7][5] = '*';
	maze02[7][6] = '*';
	maze02[7][7] = '*';
	maze02[7][9] = '*';
	maze02[8][0] = '*';
	maze02[8][4] = '*';
	maze02[8][9] = '*';
	maze02[9][0] = '*';
	maze02[9][1] = '*';
	maze02[9][2] = '*';
	maze02[9][3] = '*';
	maze02[9][4] = '*';
	maze02[9][5] = '*'; 
	maze02[9][6] = '*'; 
	maze02[9][7] = '*'; 
	maze02[9][8] = '*'; 
	maze02[9][9] = '*'; 

	for ( i = 0; i < size; i++){
		for (j = 0; j < size;j++)

			printf("%c",maze02[i][j]);
		printf("\n" );
	}
}
