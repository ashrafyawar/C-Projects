#include<stdio.h>
#include<stdlib.h>// header file for using rand() function.
#include<time.h>

int main(){
	
	int students_count,each_grade,i,select_menu,A = 0,B = 0,C = 0,D = 0,F = 0;//number of students which will be entered by the user.
	double average,total_grades = 0;
	int max = 0,min = 100,max_index = 1,min_index = 1,index = 0;/* will be used in down operations*/
    srand(40);// generates random numbers

	printf("Enter students counts:\n");//promts to get cuantity of students in a calass.
    scanf("%d",&students_count);

	while(students_count < 3 || students_count > 50){//condition to execute the while inside
		printf("Not in Range!!!\n");
		printf("\n");
		printf("Enter student count :\n");
	    scanf("%d",&students_count);
	}

	for(i = 1;i <= students_count;i++){//generates random number. 

		index++;// index has incremented here.
		each_grade = (rand() % 100 +1);//generates random numbers in interval accordingt to student_count
		
		printf("%d",each_grade);

		if(each_grade >= 90 && each_grade <= 100)/*counts the letter_grade of students according to the condition satisfication*/
		    A++;
		else if(each_grade >= 80 && each_grade <= 89)
		    B++;
		else if(each_grade >= 70 && each_grade <= 79)
		    C++;
		else if(each_grade >= 60 && each_grade <= 69)
	   		D++;
		else if(each_grade >= 0 && each_grade <= 59)
			F++;
		if (max < each_grade){//calcualtes most succecful_setudent.
  			max = each_grade;
  			max_index = index;
		}

		if (min > each_grade){//calculates most unsuccusful student.
			min = each_grade;
			min_index = index;
		}
						
		total_grades = total_grades + each_grade;//storing each_grade to total to use in average.
		printf("\t");      
	}

    average  = total_grades / students_count;//calcualtes the average of the all students grades. 
	printf("\n");
    printf("_______________________________________________________\n");

	do{
		do{//do while loop used to prompt and pop up the menu.  

	        printf("****_students score calculator Menu for %d students_**** \n",students_count );
	        printf("\n");
		    printf("1) most successful student \n");
		    printf("2) most unsuccessful student \n");
		    printf("3) letter grade statistics \n");
			printf("4) calculate average \n");  
			printf("5) show all data \n\t\t\t"); 
			printf("Make selection:");
			
			scanf("%d",&select_menu);
			
			if(select_menu !=1 && select_menu !=2 && select_menu!=3 && select_menu!=4 && select_menu!=5)//condition to execute the inside if statment
				printf("false selection!!!\n");
	    }
	    while(select_menu !=1 && select_menu !=2 && select_menu!=3 && select_menu!=4 && select_menu!=5 && select_menu!=-1);
	
    switch(select_menu){//menu selection 
    	case 1://dispals the most succesful student's details.
	    	printf(" most successful student:\n");
	    	printf("index : %d\n",max_index);
	    	printf("score :%d\n",max);

	    	if (max >= 90)//these if statmenst used to find the find the latter gardes of the students according to their points.
	    		printf("later grade : A\n");
	    	if (max > 80 && max < 90)
	    		printf("later grade : B\n");
	    	if (max > 70 && max < 80)
	    		printf("later grade : C \n");
	    	if (max > 60 && max < 70)
	    		printf("later grade : D\n");
	    	if (max < 60)
	    		printf("later grade : F\n");
	        break;
	    case 2://displays the most unsuccesful student's details.
	    	printf(" most unsuccessful student:\n");
	    	printf("index : %d\n",min_index);
	    	printf("score : %d\n",min);
	    	if (min >= 90)
	    		printf("later grade : A\n");
	    	if (min > 80 && min < 90)
	    		printf("later grade : B\n");
	    	if (min > 70 && min < 80)
	    		printf("later grade : C \n");
	    	if (min > 60 && min < 70)
	    		printf("later grade : D\n");
	    	if (min < 60)
	    		printf("later grade : F\n");
    	    break;
    	case 3://letter grade statistics displaying.
	    	printf(" %d students got letter grade'A'\n",A);//displays the letter statistics of the students
	    	printf(" %d students got letter grade'B'\n",B);
	    	printf(" %d students got letter grade'C'\n",C);
	    	printf(" %d students got letter grade'D'\n",D);
	    	printf(" %d students got letter grade'F'\n",F);
	    	break;
    	case 4://average displaying.
	    	printf("the average score of %d student is %.2f\n",students_count,average );//finds the average of the all students marks according to thier quantity.
	    	break;
	    case 5://displays the all data at the same time.
	    	printf(" most successful student:\n");
	    	printf("index : %d\n",max_index);
	    	printf("score :%d\n",max);

	    	if (max >= 90)
	    		printf("later grade : A\n");
	    	if (max > 80 && max < 90)
	    		printf("later grade : B\n");
	    	if (max > 70 && max < 80)
	    		printf("later grade : C \n");	
	    	if (max > 60 && max < 70)
	    		printf("later grade : D\n");
	    	if (max < 60)
	    		printf("later grade : F\n");

	    	printf("__________________________________________\n");
	    	printf(" most unsuccessful student:\n");
	    	printf("index : %d\n",min_index);
	    	printf("score : %d\n",min);

	    	if (min >= 90)
	    		printf("later grade : A\n");
	    	if (min > 80 && min < 90)
	    		printf("later grade : B\n");	    	
	    	if (min > 70 && min < 80)
	    		printf("later grade : C \n");	
	    	if (min > 60 && min < 70)
	    		printf("later grade : D\n");
	    	if (min < 60)
	    		printf("later grade : F\n");

	    	printf("__________________________________________\n");
 			printf(" %d student got letter grade'A'\n",A);
	    	printf(" %d student got letter grade'B'\n",B);
	    	printf(" %d student got letter grade'C'\n",C);
	    	printf(" %d student got letter grade'D'\n",D);
	    	printf(" %d student got letter grade'F'\n",F);
	    	printf("__________________________________________\n");
			printf("the average score of %d student is %.2f\n",students_count,average );
	    	break;

	    default :
		    	printf("\n");

        }
    
    }
    while(select_menu != -1);
    return 0;
}     	