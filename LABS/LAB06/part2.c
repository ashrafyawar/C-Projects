#include<stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 100

int main(){
	
	int arr_size = 0,i,j,limit = 5,boundry,sum = 0;	
	double average,actual_val,difference1,difference2,guess;
	srand(time(NULL));
	
	printf(" Enter array size:");
	scanf("%d",&arr_size);
	
	int arr[arr_size];
	
	printf("\n");
	printf(" Enter range of random numbers 0-to:");

	scanf("%d",&boundry);
	printf(" ");
	
	for (i = 0; i < arr_size;i++){
	
		arr[i] = rand() % boundry+1;
		sum = sum + arr[i];
		printf("[%d] ",arr[i] );
	}
	
	average = (double)sum / (double)arr_size;
	printf("\n the average is %lf \n",average);
	
	difference1 = (double)fabs(arr[0]-average);
	
	for (j = 0; j < arr_size; j++){
		
		difference2 = (double)fabs(arr[j]-average);		

	    if (difference1 > difference2 || difference1 == difference2){
			actual_val = (double)arr[j];
			difference1 = difference2;
		}
	}

	printf("you have %d guesses to find the actual_value of the list>>>\n",limit);
	
	while(limit >!1){

		printf("Make you guess(%d left):",limit);
		scanf("%lf",&guess);
		
		if (guess == actual_val){

			printf("congractualtions!!! you just found the actual_value\n");
			limit = 0;
		}
		else if ((guess > actual_val) && (guess-actual_val > 10)){
			printf("cold,you should decrease your guess!\n");
		}
		else if ((guess > actual_val) && (guess-actual_val < 10)){
			printf("hot,you almost find target actual_value!!!\n");
		}
		else if ((guess < actual_val) && (actual_val-guess > 10)){
			printf("cold,you should increase your guess!\n");
		}
		else if ((guess < actual_val) && (actual_val-guess < 10)){
			printf("hot,you almost find target actual_value!!!\n");
		}

		limit--;
	}

	if (limit == 0){
		printf("\nyou could not find the actual_value (-__-)\n");
	}
	return 0;
}
