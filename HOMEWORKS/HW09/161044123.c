#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#define BUFFER 1024
typedef struct{
	
	char** map;
	int width;
	int height;
	int Flower_x;
	int Flower_y;

}Forest;

typedef struct{

	int coord_x;
	int coord_y;
	int water_Bootle_size;

}Botanist;

void init_game(Forest *forest,Botanist *botanist);
void print(Forest *forest);
char **generateforest(int height,int width);
void free_forest(Forest *forest);
void search(Forest *forest,Botanist *botanist,int remaining_water,int found,int cord_x_of_B,int cord_y_of_B,int *result);


int main(){

	int result = 0;
	Forest forest;//structure type varialbes 
	Botanist botanist;//structure type variables.
	
	srand(time(NULL));
	
	init_game(&forest,&botanist);//calling function init_game.
	
	print(&forest);//calling function.
	printf("\nSearching...\n");

	search(&forest,&botanist,botanist.water_Bootle_size,0,botanist.coord_x,botanist.coord_y,&result);

	print(&forest);

	if (result==1)
		printf("\nI have found it in (%d,%d)!\n",botanist.coord_x,botanist.coord_y);
	
	else
		printf("\nHelp ! I am on (%d,%d)\n",botanist.coord_x,botanist.coord_y);
	
	free_forest(&forest);//calling free function to free the all used dara area and deposite it to memory manager back.

	return 0;
}//end of main function
char **generateforest(int height,int width){//this function generate a dynamic area for the 2d array in memory  it takes the hight and witgh of the array and according to that generates and accopies the place in memory form memory manager.
    
    int i,r,c;
    char **forest;

    r = height;
    c = width;

    forest = (char **)malloc(r * sizeof(char *));//functions to allocate dynamicly memory .
    
    for (i = 0; i < r; i++){
        forest[i] = (char *)malloc(c * sizeof(char));//allocating size in memory for a char type array
    }

    return (forest);
}//end of function forest.
void free_forest(Forest *forest){//this functions deposite the memory used space to memory manager later on to be used to another perpose.
    
    int i;
    
    for (i = 0; i < forest->width; ++i){
    
        free(forest->map[i]);
    }
    
    free(forest->map);
}

void init_game(Forest *forest,Botanist *botanist){//this function initializes the forest game board.

	FILE *open_file;//setting file pointer.
	int i=0,j=0,k;
	char ch,charracter;  
    
    open_file = fopen("init.csv","r");//opennig the file

  	fscanf(open_file,"%d",&(botanist->water_Bootle_size));

  	fscanf(open_file,"%d%c%d\n",&(forest->height),&charracter,&(forest->width));

 	forest->map = generateforest(forest->height,forest->width);

 	for(i = 0;i < forest->height;i++){
 	
 		k = 0;

 		for (j = 0;j < forest->width*2+1;j++){		
 	 		
 	 		if (fscanf(open_file,"%c",&ch) != EOF){
 	 			
 	 			if (ch !=','){

 	 				forest->map[i][k] = ch;
 	 				k++;
 	 			}

 	 			if (ch =='B'){

 	 				botanist->coord_x = i;
 	 				botanist->coord_y = k-1;
 	 			}
 	 			if (ch=='F'){

 	 				forest->Flower_x = i;
 	 				forest->Flower_y = k-1;
 	 			}
	 		}
 		}
 	}
 	
 	fclose(open_file);//closign the file area.
}//end of function.
void print(Forest *forest){//this function prints out the  initialized game forest board.      
	
	int i,j;
	printf("\n");
	
	for (i = 0; i < forest->height; i++){

		for ( j = 0; j < forest->width;j++){

			printf("%c ",forest->map[i][j]);

		}
		printf("\n");
	}
}
void search(Forest *forest,Botanist *botanist,int remaining_water,int found,int cord_x_of_B,int cord_y_of_B,int *result){

	int cord_x,cord_y,keep_botanist_x,keep_botanist_y;
	char temp;

	if (remaining_water!=0 && found == 1){//base cases for the recursion.	

		*result = 1;
		keep_botanist_x = botanist->coord_x;
		keep_botanist_y = botanist->coord_y;
		forest->map[cord_x_of_B][cord_y_of_B]='F';
		forest->map[keep_botanist_x][keep_botanist_y] = ' ';
		botanist->coord_y = cord_y_of_B;
		botanist->coord_x = cord_x_of_B;
		return;	
	
	}

	else if(remaining_water==0 && found == 0){//base_case. 

		*result = 0;
		return;
	}
	else if(found == 0 && remaining_water!=0){
		
		cord_x = rand() % 10;//generating number between 0 and 9 (including 9)to x conrdenate of the forest_map.
		cord_y = rand() % 10;//generating number between 0 and 9(including 9 ) to y conrdenate of the forest_map.

		if (forest->map[cord_x][cord_y]!='#'){

			if (forest->map[cord_x][cord_y]=='F'){
					
				found = 1;
				search(forest,botanist,remaining_water,found,cord_x,cord_y,result);

			}
			else{

				found = 0;

				keep_botanist_x = botanist->coord_x;
				keep_botanist_y = botanist->coord_y;
				
				temp = forest->map[keep_botanist_x][keep_botanist_y];
				
				forest->map[keep_botanist_x][keep_botanist_y] = forest->map[cord_x][cord_y];
				forest->map[cord_x][cord_y]= temp;
				
				botanist->coord_x = cord_x;
				botanist->coord_y  = cord_y;

				search(forest,botanist,remaining_water-1,found,cord_x,cord_y,result);
			}	
		}
		else{
			
			found = 0;
			search(forest,botanist,remaining_water,found,cord_x,cord_y,result);
		}
	}
	return;
}