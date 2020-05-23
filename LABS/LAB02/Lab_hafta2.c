#include <stdio.h>
#include <math.h>

void welcome(void);
int getHeight(void);
double getInputDouble(void);
double calculateBMI(int height, double weight);
void printBMICategory(double bmi);
void printInfo(int height, double weight);
double convertHeight(int height);

int main(){

	int height;
	double weight, bmi;

	welcome();
	height = getHeight();

	weight = getInputDouble();

	bmi = calculateBMI(height, weight);

	printBMICategory(bmi);

	printInfo(height, weight);

	return 0;
}

void welcome(void){

	printf("---------- BMI Calculator ----------\n");
}

int getHeight(void){
	
	int height;

	printf("Height (in cm): ");
	scanf("%d", &height);

	return height;
}

double getInputDouble(void){
	
	double weight;

	printf("Weight (in kg): ");
	scanf("%lf", &weight);

	return weight;
}

double calculateBMI(int height, double weight){
	
	double bmi;
	bmi = weight / (pow(height, 2) / 10000);
	return bmi;
}

void printBMICategory(double bmi){

	if(bmi >= 0 && bmi <= 18.49)
		printf("Underweight\n");

	else if(bmi >= 18.5 && bmi <= 24.49)
		printf("Normal\n");

	else if(bmi >= 24.5 && bmi <= 29.99)
		printf("Overweight\n");

	else if(bmi >= 30)
		printf("Obesity\n");
}

void printInfo(int height, double weight){
	
	double bmi;

	bmi = calculateBMI(height, weight);

	printf("Height: %d cm\n", height);

	printf("Weight: %lf\n", weight);

	printf("BMI: %lf kg/m2\n", bmi);

	printf("Category: ");

	printBMICategory(bmi);
}
