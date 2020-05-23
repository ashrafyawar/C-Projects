#include <stdio.h>

int main(){

	int input;
	int total = 0;

	printf("\nEnter a number: ");
	scanf("%d", &input);

	for(int n = 1; n <= input; n++){
	
	printf("\n");

	total = 0;

		for(int i = 1; i <= n; i++){

			total += i;

			printf("%d ", i);
		
			if(i == n)
				printf("= %d", total);

			else if(i <= n)
				printf("+ ");
		}
	}
	printf("\n");

	return 0;
}
