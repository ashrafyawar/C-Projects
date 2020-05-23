              					/*hw4_io.c:The source file implementing input and output functions.*/
#include <stdio.h>							
#include "hw4_io.h"//header file of used functions inside the hw4_io.c source file.

int read_polynomial3(double *a0, double *a1, double *a2, double *a3){//function reads four number from the user inside it and sends the values to the other funtions to be used .

	double  first_co,second_co,third_co,fourth_co;//declaring part
	printf("Enter four Coefficients of polynomial digree three respectively :\n  ");//prompting to the user

	scanf("%lf\t %lf\t %lf\t%lf",&first_co,&second_co,&third_co,&fourth_co);//storing it in memory cells
	
	*a0 = first_co;//stores  the first enterd number to the *a0 and send references it to other functions to be used.
	*a1 = second_co;//stores  the first enterd number to the *a1 and send references it to other functions to be used.
	*a2 = third_co;//stores  the first enterd number to the *a2 and send references it to other functions to be used.
	*a3 = fourth_co;//stores  the first enterd number to the *a3 and send references it to other functions to be used. 	

}//end of the read_polynomial3 function.

int read_polynomial4(double *a0, double *a1, double *a2, double *a3, double *a4){//function same as function read_polynomila3 but difference with one extra argument.
	double first_co,second_co,third_co,fourth_co,fifth_co;
	
	printf("enter five coefficients of polynomials  digree four respectively :\n");

	scanf("%lf\t%lf\t %lf\t %lf\t%lf",&first_co,&second_co,&third_co,&fourth_co,&fifth_co);
	
	*a0 = first_co;//stores  the first enterd number to the *a0 and send references it to other functions to be used.
	*a1 = second_co;//stores  the first enterd number to the *a1 and send references it to other functions to be used.
	*a2 = third_co;//stores  the first enterd number to the *a2 and send references it to other functions to be used.
	*a3 = fourth_co;//stores  the first enterd number to the *a3 and send references it to other functions to be used.
	*a4 = fifth_co; //stores  the first enterd number to the *a4 and send references it to other functions to be used.
	
	return 0;
}//end of the read_polynomial4 function.

void write_polynomial3(double a0, double a1, double a2, double a3){//writes the polynomila according to the given coefficients.
	
	double x;
	int wrong = 0;

	if (a0 == -1.0)//condition for first coefficient.
		printf("-x^3");
	else if (a0 == 1.0)
		printf("x^3");
	else if (a0 != 0.0 && a0 !=1.0 && a0 !=-1.0)
		printf("%.0lfx^3",a0);
    if (a0 > 0 && a0 != 1.0)
		printf("%.0lfx^3",a0);
	if (a0 < 1 && a0 !=-1.0 && a0 !=0)
		printf("%.0lfx^3",a0);
	else if (a0 == 0)
		wrong ++;
	if (a1 == -1.0)//condition for second coefficient.
		printf("-x^2");
	else if (a1 == 1.0)
		printf("+x^2");
	if (a1 > 0 && a1 !=1.0 )
		printf("+%.0lfx^2",a1 );
	else if (a1 < 0 && a1 != -1.0)
		printf("%.0lfx^2",a1 );
	else if (a1 == 0.0 )
		wrong++;
	if (a2 == -1.0)//condition for third coefficient.
		printf("-x");
	else if (a2 == 1.0)
		printf("+x");
	if (a2 > 0 && a2 !=1.0 )
		printf("+%.1lfx",a2 );
	else if (a2 < 0 && a2 != -1.0)
		printf("%.1lfx",a2 );
	else if (a2 == 0.0 )
		wrong++;
	if (a3 > 0 )//condition for fourt coefficient.
		printf("+%.0lf ",a3);
	if (a3 < 0)
		printf("%.0lf ",a3);
	else if (a3 == 0 )
		wrong++;
}//end of the write_polynomial3 function.

void write_polynomial4(double a0, double a1, double a2, double a3, double a4){//writes the polunomial digree four according to the given coefficients.

	double x;
	int wrong = 0;

	if (a0 == -1.0)//condition for first coefficient.
		printf("-x^4");
	else if (a0 == 1.0)
		printf("x^4");
	else if (a0 != 0.0)
		printf("%.0lfx^4",a0);
    if (a0 > 0 && a0 != 1.0)
		printf("%.1lfx^4",a0);
	else if (a0 < 1 && a0 !=-1.0 && a0 !=0)
		printf("%.1lfx^4",a0);
	else if (a0 == 0)
		wrong ++;
	if (a1 == -1.0)//condition for second coefficient.
		printf("-x^3");
	else if (a1 == 1.0)
		printf("+x^3");
	if (a1 > 0 && a1 !=1.0)
		printf("+%.1lfx^3",a1 );
	else if (a1 < 0 && a1 != -1.0)
		printf("%.1lfx^3",a1 );
	else if (a1 == 0.0 )
		wrong++;
	if (a2 == -1.0)//condition for thirdcoefficient.
		printf("-x^2");
	else if (a2 == 1.0)
		printf("+x^2");
	if (a2 > 0 && a2 !=1.0)
		printf("+%.1lfx^2",a2 );
	else if (a2 < 0 && a2 != -1.0)
		printf("%.1lfx^2",a2 );
	else if (a2 == 0.0 )
		wrong++;

	if (a3 == -1.0)//condition for fourth coefficient.
		printf("-x");
	else if (a3 == 1.0)
		printf("+x");
	if (a3 > 0 && a3 !=1.0)
		printf("+%.1lfx",a3 );
	else if (a3 < 0 && a3 != -1.0)
		printf("%.1lfx",a3 );
	else if (a3 == 0.0 )
		wrong++;

	if (a4 > 0 )//condition for fifth coefficient.
		printf("+%.0lf ",a4);
	if (a4 < 0)
		printf("%.0lf ",a4);
	else if (a4 == 0 )
		wrong++;
}//end of the write_polynomial4 function.