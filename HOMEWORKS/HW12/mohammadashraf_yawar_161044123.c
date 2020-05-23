#include<stdio.h>
#define CLASS1_COUNT 10//you can change the macro to test the program.
#define CLASS2_COUNT 10
#define SLOPE_AVOIDENCE 0.012//i have just defined for the sectuation like slope is infinity if it is infinity we can assume it this macro and for the time we can change the macro as we wish. 

int main()
{

	double x1 = 0.0,y1 = 0.0,x2 = 0.0,y2 = 0.0,sum_c1x = 0,sum_c1y = 0,sum_c2x = 0,sum_c2y = 0,m,x,b;//variable declration to be used down.
	double c1x,c2x,c1y,c2y,mid_x,mid_y,sep_line_slope,sep_line_b,sep_y,test_b,test_x,test_y,test_slope,equa_of_ave_point,equa_of_test_point;//variable declration to be used down.
	int i,j = 0,statue,step = 0;
	
	while(step != CLASS1_COUNT)
	{

		printf("line %d > ",j);//sequence of line number.

		scanf("%lf%lf",&c1x,&c1y);
		
		sum_c1x += c1x;// sum of x coordinates of calss1
		sum_c1y += c1y;// sum of y coordinates of calss1
		
		step++;			
		j++;//line number eteration variable.

	}

	for (i = 1; i <= CLASS2_COUNT;i++)//getting calass1 and class2's datas from the user.
	{
		
		printf("line %d > ",j);//sequence of line number.
			
		scanf("%lf%lf",&c2x,&c2y);

		sum_c2x += c2x;// sum of x coordinates of calss2
		sum_c2y += c2y;//sum of y coordinates of calss2
		
		j++;//line number eteration variable.
	}

	x1 = sum_c1x / CLASS1_COUNT;//average point's x coordinate for class1.
	y1 = sum_c1y / CLASS1_COUNT;//average point's y coordinate for class1.
	
	x2 = sum_c2x / CLASS2_COUNT;//average point's x coordinate for class2.
	y2 = sum_c2y / CLASS2_COUNT;//average point's y coordinate for class2.

	if ((x2 - x1) == 0 && (y2 - y1) != 0)//condition to check if the denominator of slope formula is zero and nominator is not zero then execute the if block.
	{
		m = SLOPE_AVOIDENCE;
	}
	else
	{
		m = ((y2 - y1)/(x2 - x1));//slope of the line between average points.
	}
	
	b = (y1 - (m * x1));//finding value of b from the equation(y = mx + b).
	
	equa_of_ave_point = ((m * x1) + b);//line equation between two average points(y  = mx + b)
	
	mid_x = ((x1 + x2) / 2);//x coordeiate of midpoint.
	mid_y = ((y1 + y2) / 2);//y coordinte of midpoint.

	sep_line_slope = (1 / m) * (-1);//the slope fo the line seperating two average points(we take one over the slope of the line which is perpendicular to the seperating line and multiply of with minus one and)

	sep_line_b = (mid_y - (sep_line_slope * mid_x));
	
	sep_y = ((sep_line_slope * mid_x) + sep_line_b);//line equation for the seperating line which passes through midpoint.
	
	do// here : do while executes untill an invalid characher has entered.
	{
		
		printf("line %d > ",j);//line continu

		statue = scanf("%lf %lf",&test_x,&test_y);//get the test points

		if (statue == 2)//condition to check whether did we get the correct inputs from the user or not.
		{
		
			test_slope = sep_line_slope;//slope of testing points and slope of the seperating line will be the same because the point that we are testing is in the same trajectory with the line seperating passess through midpoints.
		
			test_b = (test_y - (test_slope * test_x));//finding value of b from the equation(y = mx + b) for testing point.
			
			equa_of_test_point = ((test_slope * test_x) + (test_b));//equations of the test point (y = mx + b)			
			
			if (test_b > sep_line_b)//condition for printing class1.
			{

				printf("class1\n");
			}
			else if (test_b < sep_line_b)//condition to print class2.
			{
				printf("class2\n");
			} 
		}

		j++;
	}while(statue == 2);
	
	return 0;
}