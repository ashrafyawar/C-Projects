#include <stdio.h>

int main(){

	int basic_salary;
	int gross_salary;
	int HRA, DA;

	printf("Basic salary: ");
	scanf("%d", &basic_salary);

	if(basic_salary <= 10000){

		HRA = basic_salary/100*20;
		DA = basic_salary/100*80;
	}

	else if(basic_salary >= 10001 && basic_salary <= 20000){

		HRA = basic_salary/100*20;
		DA = basic_salary/100*80;
	}

	else if(basic_salary >= 20001){

		HRA = basic_salary/100*30;
		DA = basic_salary/100*95;
	}

	gross_salary = basic_salary + DA + HRA;
	printf("Gross Salary: %d", gross_salary);

	return 0;
}
