#include <stdio.h>

int main(){

	int input,line = 1.input2;
	
	printf("\nEnter a number: ");
	scanf("%d", &input);
	input2 = input;

	for(; line <= input; line++){

		printf("\n");
		for(int space = 1; space < input2; space++){
			printf(" ");
		}

		input2 = input2 - 1;

		for(int star = 1; star < line * 2; star++){
			printf("*");
		}

	}

	for(int mid = 1; mid <= input - 2; mid++){

		printf("\n");
		for(int star = 1; star < line * 2 - 2; star++){
			printf("*");
		}
	}

	if(input > 1){

		input2 = 0;
		for(line = input; line > 0; line = line - 1){

			printf("\n");
			for(int space = 1; space <= input2; space++){
				printf(" ");
			}

			input2++;
			for(int star = 1; star < line * 2; star++){
				printf("*");
			}
		}
	}
	printf("\n\n");

	return 0;
}
