#include <stdio.h>

int main(){

	char operator;
	double operand1, operand2, result;

	printf("Enter an operator(+,-,*,/): ");
	scanf("%c", &operator);

	printf("Enter two operands: ");
	scanf("%lf", &operand1);
	scanf("%lf", &operand2);

	if(operand2 == 0 && operator == '/'){

		while(operand2 == 0){

			printf("Try again!\n");
			scanf("%lf", &operand2);
		}
	}

	switch(operator){

		case '+':	result = operand1 + operand2;
			break;

		case '-':	result = operand1 - operand2;
			break;
		
		case '*':	result = operand1 * operand2;
			break;
		
		case '/':	result = operand1 / operand2;
			break;
	}

	printf("%.1f %c %.1f = %.1f\n", operand1, operator, operand2, result);
	return 0;
}
