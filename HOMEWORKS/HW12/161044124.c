#include<stdio.h>
#include<math.h>
int main()
{

	double x1 = 0.0,y1 = 0.0,x2 = 0.0,y2 = 0.0,sum_c1x = 0,sum_c1y = 0,sum_c2x = 0,sum_c2y = 0,m,x,b;//variable declration to be used down.
	double c1x,c2x,c1y,c2y,mid_x,mid_y,sep_line_slope,sep_line_b,sep_y,test_b,test_x,test_y,test_slope,equa_of_ave_point,equa_of_test_point;//variable declration to be used down.
	int i,j = 0,statue	;
	
	FILE *inpt;

	inpt = fopen("test.txt","r");

	for (i = 0; i < 20; ++i)//getting calass1 and class2's datas from the user.
	{
		
		printf("line %d > ",j);//sequence of line number.
		
		if (i < 10)//statment for class1
		{
		
			//scanf("%lf%lf",&c1x,&c1y);
			fscanf(inpt,"%lf %lf",&c1x,&c1y);
			printf("%lf %lf\n",c1x,c1y);
			
			sum_c1x += c1x;// sum of x coordenates of calss1
			sum_c1y += c1y;// sum of y coordenates of calss1
		
		}
		if (i >=10 && i < 20)//statment for class2
		{
		
			//scanf("%lf%lf",&c2x,&c2y);
			fscanf(inpt,"%lf %lf",&c2x,&c2y);
			printf("%lf %lf\n",c2x,c2y);

			sum_c2x += c2x;// sum of x coordenates of calss2
			sum_c2y += c2y;//sum of y coordenates of calss2
		
		}
	j++;//line numbers eterations variable.
	}

	x1 = sum_c1x / 10;//average point's x coordenate for class1.
	y1 = sum_c1y / 10;//average point's y coordenate for class1.
	
	x2 = sum_c2x / 10;//average point's x coordenate for class2.
	y2 = sum_c2y /10;//average point's y coordenate for class2.

	m = ((y2 - y1)/(x2 - x1));//slope of the average points.
	
	b = (y1 - (m * x1));//finding value of b from the equation.
	
	equa_of_ave_point = ((m * x1) + b);//line equation between two average points(y  = mx + b)
	
	mid_x = ((x1 + x2) / 2);//find x coordenate of midpoint.
	mid_y = ((y1 + y2) / 2);//find y coordente of midpoint.

	sep_line_slope = (1 / m) * (-1);//the slope fo the line seperating two average points(we take one over the slope of the line which is perpendicular to the seperating line and multiply of with minus one and)

	sep_line_b = (mid_y - (sep_line_slope * mid_x));
	
	sep_y = ((sep_line_slope * mid_x) + sep_line_b);//line equation for the seperating line which passes through midpoint.
	do// here : do while executes untill an invalid characher has entered.
	{
		
		printf("line %d > ",j);//line continu

		statue = scanf("%lf %lf",&test_x,&test_y);//get the test points

		if (statue == 2)//condition to check whether did we get the correct inputs from the user or not
		{
			
		
			test_slope = sep_line_slope;//slope of testing points and slopw of the seperating line will be the same.
		
			test_b =(test_y - (test_slope * test_x));//finding value of b from the equation(y = mx + b)
			
			equa_of_test_point = ((test_slope * test_x) + (test_b));//equations of the test point (y = mx + b)			
			
			if (test_b > sep_line_b)
			{

				printf("class1\n");
			}
			else if (test_b < sep_line_b)
			{
				printf("class2\n");
			} 
			else if (test_b == sep_line_b)
			{
				printf("the test point is on the seperating line!!!\n");
			}
		}

		j++;
	}while(statue == 2);
	
	fclose(inpt);
	return 0;
}