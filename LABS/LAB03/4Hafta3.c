#include <stdio.h>

int foo(int num);

int main(){
	
	int i, counter, flag;
	int num1, num2, num3, num4, num5, num6, num7, num8, num9, num10;

	flag = 0;
	while(flag != -1){
		
		printf("Enter 10 numbers between 0 and 1000:\n");
		scanf("%d %d %d %d %d %d %d %d %d %d", &num1, &num2, &num3, &num4, &num5, 
		&num6, &num7, &num8, &num9, &num10);

		printf("The prime numbers: ");

		num1 = foo(num1);
		num2 = foo(num2);
		num3 = foo(num3);
		num4 = foo(num4);
		num5 = foo(num5);
		num6 = foo(num6);
		num7 = foo(num7);
		num8 = foo(num8);
		num9 = foo(num9);
		num10 = foo(num10);

		if( num1==0 && num2==0 && num3==0 && num4==0 && num5==0 &&

			num6==0 && num7==0 && num8==0 && num9==0 && num10==0){
			printf("There is not a prime number!\n\n");
		}

		else{
			printf("\n");
			flag = -1;
		}
	}
	return 0;
}

int foo(int num){

	int i, counter;

	counter=0;

	for(i=1 ; i<=num ; ++i){
		
		if(num % i == 0){
			++counter;
		}
	}

	if(counter==2){

		printf("%d ", num);
		return 1;
	}

	else{
		return 0;
	}
}
