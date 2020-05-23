#include<stdio.h>
void printDigit(int number, int digitNumber);
int power(int num,int power);

int main(){

	int number,counter = 0,temp,i,resultPower,temp2;
	printf("Enter The Number:\n");
	scanf("%d",&number);
	
	/*control statment the while loop*/
	while(number < 23 || number > 98760){	
		printf("Not in Range!!!\n");
		printf("\n");
		printf("Enter the number :\n");
	    scanf("%d",&number);
	}

	temp = number;
	while(temp !=0){//finds the quantity of the digits with respect to number.
		
		temp = temp /10;
		counter ++;
	}

	temp = counter;

	for (i = 0; i < temp; ++i){//deremines the positions of the digits.
		resultPower = power(10,counter - 1);//calling power function.
		temp2 = number / resultPower;
		printDigit(temp2,counter);//calling printDigit function.
		number = number % resultPower;
		counter--;//dicrement of counter.

	}
	return 0;
}

int power(int num,int power){//power function to any given number rise to number.

	int i,result = 1;
	for (i =0; i < power ;i++ )
		result*= num;
	return result;
}

void printDigit(int number, int digitNumber){//function to determine and print the positon of the digits according to number entered.
	
	switch(digitNumber){

		case 5 :
			printf("The Fifth digit is :  %d\n",number );
			break;
		case 4 :
			printf("The Fourth digit is : %d\n",number );
			break;
		case 3 :
			printf("The Third digit is :  %d\n",number );
			break;
		case 2 :
			printf("The second digit is : %d\n",number );
			break;
		case 1 :
			printf("The First digit is :  %d\n",number );
			break;
			default:
			printf("\n");
	}
}