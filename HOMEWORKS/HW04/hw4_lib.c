#include <stdio.h>
#include "hw4_lib.h"
#include <math.h>
#include <stdlib.h>
double integral(double f(double x), double xs, double xe,double delta){//function to evaluate the finite integral of given function
	
	int i;
	double dx,x,sum = 0,integral;//declaring variables

	dx = ( xe - xs ) / delta;// finding the dx of the integral
	i = 1;//initilalization of while loop
	
	while(i  <  delta){//condition of while loop

	x = xs + i * dx;

	sum = sum + f(x);//doing sum operation on f(X).
	i++;//incrementing the while loop.
	}

	integral = (dx / 2) * (f(xs) + f(xe) + 2 * sum);//find the integral by evaluating the left side.  
	return (integral);//returns the integral of the given function
}//end of the integral function.

double integral2(double f(double x, double y), double xs, double xe, double ys, double ye, double delta){//funtion evaluates the integral of two given functions.

	double i = 0,j = 0, result = 0;//decleration part
	i = ys;//nitializing the integration
	while(i < ye){//finds the outer functions integration.
	 
	    j = xs;
		while(j < xe ){//finds the innner functions's integration
			result = result +  f(i ,j) * delta;//adds the results of the two integral 
	        j = j + delta;
	    }
	
	i = i+ delta;
	}

	return result;//returns the final result.
}

int derivatives(double f(double a), double x, double eps, double *d1, double *d2){//function calcualtes the numerical derivatives o fthe first and second .

	int value = 1;
	double first_derivative,second_derivative;//declation part

	if (eps == 0)
		return -1;
	else{

	first_derivative = (f(x + eps)-f(x - eps)) / (2 * eps);//calcualtes the first derivative according ti the formula.	
	
	*d1 = first_derivative;//send to the referenced argument *d1 to be used in the other function.

	second_derivative = (f(x + eps) - 2 * (f(x))+(f(x-eps))) /(eps * eps);//calculate the second derivative of the funtion according to the formula .
	
	*d2 = second_derivative;//send to the argument *d2 to be used inside the other function.
	}

	return (1);
}
int compare_derivatives(double f(double a), double d1(double b), double d2(double b), double x, double eps, double * e1, double *e2){//function returns the avalues of the difference between actual derivative and numerical calculated ones

	double actual_derivative1,actual_derivative2;//declation part
	double numerical_deri1,numerical_deri2;//declation part
	double first_derivative_differrence,second_derivative_difference;//declation part

	derivatives(f,x,eps,&numerical_deri1, &numerical_deri2);//calling the function derivatives which calcualtes the numerical first and second derivatives of the given funtion.
	
	first_derivative_differrence = fabs(d1(x) - numerical_deri1) ;//finds the difference of the first actual and numerical calualted derivatives
	
	*e1 = first_derivative_differrence;//sends to the  argument *e1 in main.c


	second_derivative_difference = fabs(d2(x) - numerical_deri2);//finds the difference of the second actual and numerical calualted derivatives
	
	*e2 = second_derivative_difference;//sends to the argument *e2 in main.c
}

int find_roots(double f(double x), double *x1, double *x2, double *x3, double *x4){

	int counter = 0,i,j,k;
	int roots[4];
	
	for (i = 0; i < 4;i++)
		roots[i] =  0;
	
	for(j = -1000000000;j < 10000000000000;j++){//estimation of the root between almost infinity number.

		if (f(j) == 0)//condition to find the root
			roots[i] = j;//my array elements will be my roots and i can print them out
	}

	for (k = 0; k < 4; k++)//for loop to print the roots of the function.
		printf("%d\n",roots[k] );

	roots[0] = *x4;//sending the roots.
	roots[1] = *x3;//sending the roots.
	roots[2] = *x2;//sending the roots.
	roots[3] = *x1;//sending the roots.

	return 0;
}