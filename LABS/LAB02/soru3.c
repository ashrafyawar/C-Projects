#include<stdio.h>
int main(){

 	int numbers;
 	double num;
 	int i;

 	printf("Enter Ten Numbers Between 0 And 1000 From The Keyboard:\n");
 
	 	for (i = 1; i <=10 ; ++i){

	 		scanf("%d",&num);	 	 	
	 	 	if (num < 0 && num > 1000)
	 	 		printf("can't execute the task!!!\n");
	 	}
 	return 0;
 }
