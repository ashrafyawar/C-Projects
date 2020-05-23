#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
void countOccurrence();/*coudnts the number accured in a range entered number*/
void menu();/*displyas the menu */
void horseRacingGame();/*function horse racing game*/
int getInt(int mini, int maxi);//checks whether the  number is between mini and maxi.
int numberGeneratorBetweenRange(int min, int max);//genrerates random number in a desired range of numbers.
void triangleofSequences();//scetchs the triangle of sequence numbers generated by a random generator.

int main(){
 
 	menu();//function 
 	return 0;
 }//end of main.

void menu(){
 	
 	int choise;//declaration
 	do{// do while.
	
	 	printf("****_MENU CHOISE GAME_****\n");
	 	printf("1.Horse Racing Game\n");
	 	printf("2.Occurrence Counter\n");
	 	printf("3.Triangle of Sequences\n");
	 	printf("0.Exit\n");
	 	printf("Enter your choise from the list above:\n");//promt to user.
	 	scanf("%d",&choise);

	 	if(choise !=1 && choise !=2 && choise !=3 && choise !=0){
	 		printf("you have choisen wrong number !!!\n");
	 		printf("___________________________\n");
	 	}
	 	
		switch(choise){
		
		case 1:
			horseRacingGame();//function call.
			break;
		case 2:
		    countOccurrence();//function call.
			break;
		case 3:
			triangleofSequences();//function calling.
			break;
		case 0:
			break;
		default:
			printf("\n");
		}    

    }while(choise != 0);//end of do while


 }//end o void menu function.*/

void horseRacingGame(){//function definition
	
	printf("**** Horse_Racing_Game ***\n");//menu title

	srand(time(NULL));//random number genarator.

	int random_horse,first_horse_speed;//decleration.
	int horse_num,horse_course,i,j,min_index;//declerations
	int index = 1,fastest_horse =20,fastest,tie = 0,exit;//declerations

	random_horse = numberGeneratorBetweenRange(3,5);//calling function generator random number between two number

	printf("number of horses : %d\n",random_horse);
	horse_num = getInt(1,random_horse);//calling the intget funtion to check the condition.
	printf("Racing Starts...\n");

	for (i = 0; i < random_horse; i++){// outer loop horse racing game.
		printf("Horse %d:",index);//horse index.

		horse_course = numberGeneratorBetweenRange(10,20);

		for (j = 0; j < horse_course; j++){//inner loop
	    	printf("-");
	    	if (i == 0)
	    		first_horse_speed = horse_course;//kepping the first horses value taken to compare it with others.

		}//end of inner loop

		if (horse_course < fastest_horse){//finds the fatest horse.
			
			fastest_horse = horse_course;//finds the winner horse
    	    min_index = index;//index of winner horse
		}

		if(i == 0)
			tie = horse_course;//kepping first generated number to compare it with next ones. 

		if (i > 0){
			
			if (horse_course == tie||first_horse_speed == horse_course)//comparing of condition sutissfied .
			 	exit = 0;
			else
		   		tie = horse_course;//transfaring the horse_courses value then will be used .
		}
		
		printf("\n");
		index++;//increamenting the horse index.

	}//end of outer loop

 	if(exit !=0){

	 	if (horse_num == min_index){//if condition is true so will print the winner.
 			
 			printf("You Win! ");
 			printf("Winner is Horse %d\n",min_index);

	 	}
		else
    		printf(" You Lose! Winner is Horse %d\n",min_index);//fastest horse finded
	}

	if(exit == 0){

		if (horse_num ==horse_course )
		  printf("You Win! Winner Is Horse %d\n",horse_num);
		else
			printf("You Lose Winner Is Horse %d\n",min_index );
	}

	printf("___________________________\n");

 }//end of void horseRacingGame function.

int getInt(int mini, int maxi){//checks whethera valu is bitween the range.
 	
 	int horse_num;
 	do{
 		printf("which horse will Win?:");
 		scanf("%d",&horse_num);

 	}while(horse_num > maxi || horse_num < mini);//condition 
 		
 	return(horse_num);//returns int horse_num.	
 }//end of getInt(int mini, int maxi) function.*/
	
 void countOccurrence(){
 	
 	int big_num,search_num,counter1 = 0,counter2 = 0,temp=0,temp1 = 0,i,reminder =0,x=0;
 	int counter3,temp2;
 	
 	printf("Big Number :");
 	scanf("%d",&big_num);//bg number
 	
 	printf("\n");
 	printf("search Number:");//user entered number
 	scanf("%d",&search_num);

 	temp1 = search_num;//storing the user entered number to temp1
 	while(temp1!=0){//this while computes the digits of the entered numbers by the user.
 		temp1 = temp1 /10;
 		counter1++;
 	}

 	temp1 = counter1;//number digit of the search numberz
 	temp2 = big_num;//storing the big number
 	
 	while(temp2!=0){//this while computes the digits of the big number 
 
 		temp2 = temp2 /10;
 		counter3++;
 	}

 	temp = big_num;
 	for (i = 0; i < counter3; i++){

 		x = pow(10,temp1);//finds the digits to be compared. 	    
 	    reminder = temp % x;//takes the mode of the big_number.

 		if (reminder == search_num){//condition to find the  number of accurences.
 		 	counter2++;
 		}
 		temp = temp / 10;
 	}//end of for loop

    printf("occurence : %d \n",counter2 );
    printf("___________________________\n");

 }//end of count accurence function.

void triangleofSequences(){//function defination triangle sequence.

 	srand(time(NULL));
 	int random_number;
 	int i,t,j;

 	random_number = numberGeneratorBetweenRange(2,10);//calling the function and sending the arguments.
 	for (i = 1; i <= random_number; i++){
 	    
 	    t = i;//store the i into t variable .
 		for(j = 1;j <= i;j++){ 

			printf("%d ",t);
			t = t + i;//sequence sectuation.
 		}
 		printf("\n");
 	}
 	printf("___________________________\n");

 }//end of triangleofSequences function.

int numberGeneratorBetweenRange(int min, int max){//function defination of number generator between two numbers.
 	
 	int difference,random,modules,random_enteger;
	random = rand();
	difference = max - min;//difference of maximum number and minimum number
	modules = random % difference;//find the modules of the generated number with respect to difference number. 
	random_enteger = modules + min;

	return(random_enteger);//returns the a generated number between max and min number.
 }//end of number_generator_between_range function.