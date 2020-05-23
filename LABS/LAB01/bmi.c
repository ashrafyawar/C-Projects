/*program to find BMI of a person.*/
/*written by:ashraf yawar*/

#include<stdio.h>//library includes functions to be used.
#include<math.h>//math library.

void welcome (void);//function welcome
int getheight (void);
double getinputdouble (void);
double calculateBMI(int height,double weight);
void printinfo(int height , double weight);
void printBMICategory( double bmi);

int main(){//functions main
	
 	double kg,bmi;
 	int cm;

    welcome ();
    
    cm = getheight ();//function call
    kg = getinputdouble ();//function call
    
    printinfo(cm ,kg);//function call
  	return 0;
}
void welcome (void){

	printf("_______BMI Calculator_______\n");
	printf("body mass index tells someone wether");
	printf(" he/she has a healthy weight for his");
	printf(" or her height.tell us your height and weight then we are going to tell you about your BMI category\n");
}
int getheight (void){
	
	int height;
	
	printf("inter  height in cm:\n");
	scanf("%d", &height);
	
	return (height);
}
double getinputdouble(void){// gets the weight.
	
	double weight;
	
	printf("enter weight\n");  
	scanf("%lf",&weight);
	
	return (weight);
}

double calculateBMI(int height,double weight){// calsulates the bmi.
	
	double m,bmi;

	m =  height * 0.01;
	bmi = (weight)/pow(m,2);  
	
	return (bmi);
}

void printBMICategory(double bmi){
	
	if(bmi >= 0 && bmi <= 18.49)
		printf("underweight\n");

	else if (bmi>= 18.49 && bmi <= 24.49)
		printf("Normal\n");

	else if(bmi>=24.5 && bmi <=29.99)
		printf("overwieght\n");

	else if ( bmi >= 30)
		printf("obsity\n");
	
	else 
		printf("your are not a man !!!!\n");
}

void printinfo(int height , double weight){//function to display the all results(bim)
	
	double bmi = calculateBMI(height,weight); 
	double m;
	m = height * 0.01;

	printf("your height is = %lf[m]\n",m);
	printf("your weight is = %lf [kg] \n",weight);
	printf("your BMI is = %lf [kg/m2]\n",bmi);
	printf("category is: ");  
	
	printBMICategory(bmi);
}
