#include<stdio.h>
#include<math.h>
int main(){
	

	double c1x1=12.4,c1x2=12.4,c1x3=18.3 ,c1x4=17.3,c1x5=21.0,c1x6=18.4,c1x7=11.1,c1x8=17.6,c1x9=15.8,c1x10=45.6,c1y1=11.8,c1y2=16.8,c1y3= 12.7,c1y4= 19.1 ,c1y5=13.2,c1y6= 16.8,c1y7= 10.5,c1y8= 13.6,c1y9= 18.5,c1y10= 16.2;
	double c2x1=12.4,c2x2=15.7 ,c2x3=18.3,c2x4=17.3,c2x5=21.0,c2x6=18.4,c2x7=11.1,c2x8=17.6,c2x9=15.8,c2x10=45.6,c2y1=18.5,c2y2=35.7,c2y3=25.1,c2y4=22.6,c2y5=28.7,c2y6=31.8,c2y7=32.8,c2y8=35.0,c2y9=36.4,c2y10=33.5;
	double x1 = 0.0,y1 = 0.0,x2 = 0.0,y2 = 0.0,sum_c1x = 0,sum_c1y = 0,sum_c2x = 0,sum_c2y = 0,m,y,x,b;
	int i,j;
	
	for (i = 0; i < 10; ++i)//loop for getting inputs of class one
		{
			
			printf("line %d > ",i);
			
			if (i == 0)
			{

				//scanf("%lf%lf",&c1x1,&c1y1);	
				printf("%.1lf %.1lf\n",c1x1,c1y1);	
				sum_c1x +=c1x1;
				sum_c1y +=c1y1;  
			}
			else if (i==1)
			{
				//scanf("%lf%lf",&c1x2,&c1y2);	
				printf("%.1lf %.1lf\n",c1x2,c1y2);
				sum_c1x +=c1x2;
				sum_c1y +=c1y2;
				
			}
			else if (i==2)
			{
				//scanf("%lf%lf",&c1x3,&c1y3);	
				printf("%.1lf %.1lf\n",c1x3,c1y3);
				sum_c1x +=c1x3;
				sum_c1y +=c1y3;
				
			}
			else if (i==3)
			{
				//scanf("%lf%lf",&c1x4,&c1y4);	
				printf("%.1lf %.1lf\n",c1x4,c1y4);
				sum_c1x +=c1x4;
				sum_c1y +=c1y4;
				
			}
			else if (i==4)
			{
				//scanf("%lf%lf",&c1x5,&c1y5);	
				printf("%.1lf %.1lf\n",c1x5,c1y5);
				sum_c1x +=c1x5;
				sum_c1y +=c1y5;
				
			}
			else if (i==5)
			{
				//scanf("%lf%lf",&c1x6,&c1y6);	
				printf("%.1lf %.1lf\n",c1x6,c1y6);
				sum_c1x +=c1x6;
				sum_c1y +=c1y6;
				
			}
			else if (i==6)
			{
				//scanf("%lf%lf",&c1x7,&c1y7);	
				printf("%.1lf %.1lf\n",c1x7,c1y7);
				sum_c1x +=c1x7;
				sum_c1y +=c1y7;
				
			}
			else if (i==7)
			{
				//scanf("%lf%lf",&c1x8,&c1y8);	
				printf("%.1lf %.1lf\n",c1x8,c1y8);
				sum_c1x +=c1x8;
				sum_c1y +=c1y8;
				
			}
			else if (i==8)
			{
				//scanf("%lf%lf",&c1x9,&c1y9);	
				printf("%.1lf %.1lf\n",c1x9,c1y9);
				sum_c1x +=c1x9;
				sum_c1y +=c1y9;
				
			}
			else if (i==9)
			{
				//scanf("%lf%lf",&c1x10,&c1y10);	
				printf("%.1lf %.1lf\n",c1x10,c1y10);
				sum_c1x +=c1x10;
				sum_c1y +=c1y10;
				
			}
			
		}
		x1 = sum_c1x / 10;
		y1 = sum_c1y / 10;
		
		printf("x1 : %lf\n",x1); 
		printf("y1 : %lf\n",y1);

		for (i = 10; i < 20; ++i)
		{
			
			printf("line %d > ",i);

			if (i == 10)
			{

				//scanf("%lf%lf",&c2x1,&c2y1);	
				printf("%.1lf %.1lf\n",c2x1,c2y1);
				sum_c2x +=c2x1;
				sum_c2y +=c2y1;
					
			
			}
			else if (i==11)
			{
				//scanf("%lf%lf",&c2x2,&c2y2);	
				printf("%.1lf %.1lf\n",c2x2,c2y2);
				sum_c2x +=c2x2;
				sum_c2y +=c2y2;
				
			}
			else if (i==12)
			{
				//scanf("%lf%lf",&c2x3,&c2y3);	
				printf("%.1lf %.1lf\n",c2x3,c2y3);
				sum_c2x +=c2x3;
				sum_c2y +=c2y3;
				
			}
			else if (i==13)
			{
				//scanf("%lf%lf",&c2x4,&c2y4);	
				printf("%.1lf %.1lf\n",c2x4,c2y4);
				sum_c2x +=c2x4;
				sum_c2y +=c2y4;
				
			}
			else if (i==14)
			{
				//scanf("%lf%lf",&c2x5,&c2y5);	
				printf("%.1lf %.1lf\n",c2x5,c2y5);
				sum_c2x +=c2x5;
				sum_c2y +=c2y5;
				
			}
			else if (i==15)
			{
				//scanf("%lf%lf",&c2x6,&c2y6);	
				printf("%.1lf %.1lf\n",c2x6,c2y6);
				sum_c2x +=c2x6;
				sum_c2y +=c2y6;
				
			}
			else if (i==16)
			{
				//scanf("%lf%lf",&c2x7,&c27);	
				printf("%.1lf %.1lf\n",c2x7,c2y7);
				sum_c2x +=c2x7;
				sum_c2y +=c2y7;
				
			}
			else if (i==17)
			{
				//scanf("%lf%lf",&c2x8,&c2y8);	
				printf("%.1lf %.1lf\n",c2x8,c2y8);
				sum_c2x +=c2x8;
				sum_c2y +=c2y8;
				
			}
			else if (i==18)
			{
				//scanf("%lf%lf",&c2x9,&c2y9);	
				printf("%.1lf %.1lf\n",c2x9,c2y9);
				sum_c2x +=c2x9;
				sum_c2y +=c2y9;
				
			}
			else if (i==19)
			{
				//scanf("%lf%lf",&c2x10,&c2y10);	
				printf("%.1lf %.1lf\n",c2x10,c2y10);
				sum_c2x +=c2x10;
				sum_c2y +=c2y10;
				
			}
		}
		x2 = sum_c2x / 10;
		y2 = sum_c2y /10;
		printf("x2 : %lf\n",x2);
		printf("y2 : %lf\n",y2);

		m = ((y2 - y1)/(x2 - x1));//slope of the equation.
		printf("m = %lf\n",m);
		
		b = (y - (m * x2));
		printf("b = %lf \n",b);
		
		return 0;
	}