#include <stdio.h>

void LGMGCD(int number1, int number2, int *GCD, int *LCM);

int main(void){
	
	int number1,number2,GCD = 0,LCD = 0;
	
	printf("Enter me two numbers\n");
	scanf("%d %d", &number1, &number2);
	
	LGMGCD(number1,number2,&GCD,&LCD);
	printf("LGMGCD(%d,%d) = %d,%d\n",number1, number2,LCD,GCD );

	return 0;
}
void LGMGCD(int number1, int number2, int *GCD, int *LCM){
	
	int i,j,smallOne,bigOne,result = 0;

	if(number1 >= number2){

		bigOne = number1;
		smallOne = number2;
	}
	else{

		bigOne = number2;
		smallOne = number1;
	}

	if(smallOne == 1){
	
		*GCD = 1;
		*LCM = bigOne * smallOne ;
	}
	else{
		
		for(i = 2 ; i <= smallOne ; i++){
			
			if(bigOne % i == 0 && smallOne % i == 0){
				*GCD = i;
			}
		}
		bigOne = bigOne / *GCD ;
		smallOne = smallOne / *GCD;
		*LCM = bigOne * smallOne * (*GCD);	
	}
}
