#include <stdio.h>
void Fibonacci(int number, int *biggest, int *counter);
int main(void){

	int biggest = 0,counter = 0,number;
	
	printf("Enter number:\n");
	scanf("%d",&number);

	Fibonacci(number, &biggest, & counter);
	printf("Number of the integer and biggest number in the Fibonacci series: %d,%d\n",counter,biggest );

	return 0;
}

void Fibonacci(int number, int *biggest, int *counter){

	int a = 1,b =  0,c = 0;
	
	for (int i = 0; c <= number; ++i){

		printf("%d  ",c );
		
		*biggest = c;
		
		(*counter)++;
		
		c = a + b;
		a = b;
		b = c;		
	}
	printf("\n");
}
