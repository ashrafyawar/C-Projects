#include <stdio.h>
void sumOfPrimeCheck(int number, int *prime1, int*prime2);
int isPrime(int number);
int main(){

	int number,prime1,prime2;
	
	printf("Enter a positive integer\n");
	scanf("%d",&number);

	sumOfPrimeCheck(number, &prime1,&prime2);
	printf("Returning: (%d,%d)\n",prime1,prime2 );
}

int isPrime(int number){
	
	int i,flag = 1;
	
	if(number == 0 || number == 1){
		return -1;
	}
	
	for(i = 2 ; i < number  ; ++i){
		if(number % i == 0){
			flag =0;
		}
	}
	return flag;
}

void sumOfPrimeCheck(int number, int *prime1, int*prime2){
	
	int tempNumber;
	
	for (int i = 3; i <= number / 2 ; ++i){
		
		if(isPrime(i) == 1 && (isPrime(number - i)) ==1){
		
			printf("%d = %d + %d\n",number, i , number - i);
			*prime1 = i;
			*prime2 = number - i;
		}
	}
}
