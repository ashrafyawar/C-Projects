#include<stdio.h>

int main(){
  	
  	double a,b,total;  
    char operator;
  	
  	printf("enter an oparator(+,-,*,/):-\n");
  	scanf("%c",&operator);
  	
  	printf("enter two operands:\n");
  	scanf("%lf%lf",&a,&b);
  	
  	if (b == 0){
  		printf("you have entered 0 for the second operand can't execute the division part!!!\n");
  	}

  	else if(b!=0){

	  	switch(operator){
	  		
		  	case'+':
		    total  = a + b;
		    printf("sum of the [%f + %f] is :%f\n",a,b,total );
		  	break;
		    case'-':
		    total = a - b;
	        printf("abstraction of the [%f - %f] is :%f\n",a,b,total );	    
	        break;
		    case'*':
		    total= a*b;
	        printf("multiflication of the [%f * %f] is :%f\n",a,b,total );
	        break;
		    case'/':
		    total= a/b;
	        printf("division  of the [%f / %f] is :%f\n",a,b,total );
		    break;
		    default:
		    printf("you have Entred non of the for [ +_-_*_/] operators so can't execute the operation!!!.enter a valid operator!!!");
	  	}
	}
  return 0;
  }
