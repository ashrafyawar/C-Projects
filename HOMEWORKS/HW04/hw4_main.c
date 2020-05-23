#include <stdio.h>
#include "hw4_lib.h"
#include "hw4_io.h"
#include <math.h>
#include <stdlib.h>
void test_compare_derivatives(){
 	
 	double e,w,r,t;
	/*double f(double x){return x*x;}

	double d1(double x) { return 2.0*x; }

	double d2(double x) { return 2.0; }

	double e1, e2;
	int res = compare_derivatives(f, d1, d2, 1.0, 0.0001, &e1, &e2);

	printf("%f %f\n",e1,e2);*/
	double f1(double x)
		{
	
			return x*x*x*x+x*x*x+x*x-x+7;
		
		}

	 find_roots(f1,&e, &w, &r,&t);
	 
	 printf("%lf %lf %lf %lf \n",e,w,r,t);

	/*double integrall;
 	integrall = integral2(f1,1,3,1,4,50);
 	
 	printf("%lf is  integral !!!\n",integrall );*/

}

int main(void){
	
	test_compare_derivatives();
	/*double first_derivative,second_derivative;
	int w;
	double integrall;
	double (*function)(double) = f;
 	integrall = integral(*function,2,2,50);
 	printf("%lf is  integral !!!\n",integrall );*/
 	
 	/*double(*fn)(double) = f;
    w = derivatives(*fn,7,0.001,&first_derivative,&second_derivative);
 	printf("%lf \n%lf\n",first_derivative,second_derivative);
 	printf("%d\n",w );*/

	return (0);
} /* end main */