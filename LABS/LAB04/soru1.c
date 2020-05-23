/*this program will calculate for you the entered numebrs sum as much as you enter */

#include<stdio.h>
int main(){
  	
  	int num,sum = 0,i,j;

  	printf("enter a number:");
  	scanf("%d",&num);

	if(num < 0 || num ==0)
		printf("not in range!!!/n enter an enteger");

	else{
    
	    for(i = 1;i <= num;i++){

		    for(j = 1;j <=i;j++){
		      	
		      	if (j !=1)
		          printf("+");
		    
		      printf("%d",j);
		   
		    }

	    	sum = sum + i;
	    
	    	printf("=%d",sum);
	    	printf("\n");
	    }
  	}

	return 0;
}
