#include <stdio.h>

void foo(int num);

int main(){

	int i, counter;
	int num1, num2, num3, num4, num5, 
	num6, num7, num8, num9, num10;

	printf("Enter 10 numbers between 0 and 1000:\n");
	scanf("%d %d %d %d %d %d %d %d %d %d", &num1, &num2, &num3, &num4, &num5, 
	                                       &num6, &num7, &num8, &num9, &num10);

	printf("The prime numbers: ");

	foo(num1);
	foo(num2);
	foo(num3);
	foo(num4);
	foo(num5);
	foo(num6);
	foo(num7);
	foo(num8);
	foo(num9);
	foo(num10);

	return 0;
}

void foo(int num){

	int i, counter;

	counter=0;
	for(i=1 ; i<=num ; ++i){

		if(num % i == 0){

			++counter;
		}
	}

	if(counter==2){
		
		printf("%d ", num);
	}
}
