#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void printTraj(int input);

int main(){

	srand(time(NULL));
	
	int input,attempt = 1,flag = 0,target;
	
	target = rand() % 5 + 10;
	while(flag == 0){

		if(attempt > 3){

			printf(" YOU LOSE THE GAME!!!\n");
			printf("\n The Target Was %d With Projection Bellow >>>\n", target);
			printTraj(target);
			printf("\n");
			flag = 1;
			break;
		}

		printf("\n Trial %d - Enter throwing distance: ", attempt);
		scanf("%d", &input);
	
		printTraj(input);

		if(input == target){

			printf("\n YOU WON THE GAME !!!");
			printf("\n\n ohhhhhhh!!!!You hit the target in %d attempts and You Are Winner!!!! (-_-)\n\n", attempt);
			flag = 1;
		}

		else 
			printf("\n\nYou could not hit the target!\n\n");
		attempt++;	
	}
	return 0;
}

void printTraj(int input){

	int line = (input + 1) / 2;
	int input2 = input;
	int midmax = 1;

	for(; line > 0; line = line - 1){

			printf("\n");

			if(input % 2 == 1)
				printf(" ");

			for(int space = input2 / 2 + 1; space > 0; space = space - 1){
				printf(" ");
			}

			input2 = input2 - 2;

			if(input % 2 == 1 && line == (input + 1) / 2)
				printf("_");

			else{

				printf("/");
				for(int midspace = 0; midspace < midmax; midspace++){
					printf(" ");
				}

				printf("\\");
				midmax = midmax + 2;
			}
		}
	}
