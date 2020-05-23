#include<stdio.h>

int main(){

	int basic_salary,gross_salary,HRA,DA;
	
	printf("input basic_salary of an employee:\n");
	scanf("%d",&basic_salary);
	
	 	if (basic_salary <=10000){

	 		HRA = 20 * basic_salary / 100;
	 		DA = 80 * basic_salary / 100;
	 	}

	 	else if( basic_salary >= 10001 && basic_salary <= 20000){

	 		HRA = 25 * basic_salary / 100;
	 		DA = 90 * basic_salary / 100;
	 	}

	 	else if(basic_salary>=20001){

	 		HRA = 30* basic_salary / 100;
	 		DA = 95 * basic_salary / 100;
	 	}
	 	
	 	gross_salary = basic_salary + HRA + DA;
	 	printf("gross_salary = %d\n",gross_salary );
  return 0;
 }
