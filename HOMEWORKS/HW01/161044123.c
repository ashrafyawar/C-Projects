#include<stdio.h>// header file
#include<math.h>// header file to use some desired function
#define PI 3.14// constant macro
double circle_area(double radius);//function prototype.
double calc_hypotenuse(int side_1,int side_2);//function prototype.
double calc_radius_of_smallest_circle(int side_1, int side_2);//function prototype.
double calc_radius_of_largest_circle(int side_1, int side_2);//function prototype.
double calc_area_of_smallest_circle(int side_1,int side_2);//function prototype.
double calc_area_of_largest_circle(int side_1,int side_2);//function prototype.
double calc_area_of_smallest_square(int side_1,int side_2);//function prototype.
double calc_area_of_largest_square(int side_1, int side_2);//function prototype.
double calc_area_of_square (int side);//function prototype.
void display_results(double largest_circle_area,double largest_square_area,double smallest_circle_area,double smallest_square_area);

int main(){//main function

	double largest_circle_area;//decleration part
	double largest_square_area;//decleration part
	double smallest_circle_area;//decleration part
	double smallest_square_area;//decleration part
	display_results(largest_circle_area,largest_square_area,smallest_circle_area,smallest_square_area);//calling the display_result funtion
	return 0;
}

void display_results(double largest_circle_area,double largest_square_area,double smallest_circle_area,double smallest_square_area){ // displays the final results of the all funtions used bellow.

	int side_1;//declaration 
	int side_2;//declaration
	
	printf("enter first side for rectangle :\n\t");//takes one side of the rectangle
	scanf("%d",&side_1);
	
	printf("enter second side for rectangle:\n\t");//takes another side of the rectangle
	scanf("%d",&side_2);

    largest_circle_area = calc_area_of_largest_circle(side_1,side_2);//function call
    largest_square_area = calc_area_of_largest_square(side_1,side_2);//function call      
    smallest_circle_area = calc_area_of_smallest_circle(side_1,side_2);//function call
    smallest_square_area = calc_area_of_smallest_square(side_1,side_2);//function call
    
    printf("The area of the largest_circle that fits inside a rectangle:      [%.2lf]\n",largest_circle_area);
    printf("The area of the largest_square that fits inside a rectangle:      [%.2lf]\n",largest_square_area);
    printf("The area of the smallest_circle that surrounds the same rectangle:[%.2lf]\n",smallest_circle_area);
    printf("The area of the smallest_square that surrounds the same rectangle:[%.2lf]\n",smallest_square_area);

}

double calc_radius_of_largest_circle(int side_1, int side_2){// finding the radius of the largest circle.

	double radius;
	if (side_1 < side_2)//finds the smaller side and divide by 2 and find the radius. 
		radius = (side_1 / 2.0);
	else
		radius = (side_2 / 2.0);
	
	return (radius);//returns the radius of the largest circle
}

double circle_area(double radius2){//returns the area circle to given radius.

 	double rad;
 	rad = (PI) * (pow(radius2,2.0));//assingment part rad is the area of the largest circle 
 	return (rad);//returns the area fo the largest circle to another function
}

double calc_area_of_largest_circle(int side_1, int side_2){//calculates the area of the largest cirlce.

 	double rad = calc_radius_of_largest_circle(side_1,side_2);//function calling.
	double area = circle_area(rad);//function calling and store the result to area as double type.
	return area;// returns the area of the largest circle
}
double calc_area_of_square (int side){//fucntio to calculate area of the any square
    side = pow(side,2);//using power function
    return(side);
}

double calc_area_of_largest_square(int side_1, int side_2){//calculatea the area of the largest square.
	
	double smallest_side,area,side;
    if (side_1< side_2)//finds the smallest side 
   		smallest_side = side_1;
    else
   		smallest_side = side_2;
    area = calc_area_of_square (smallest_side);//area of the largest square
    return area;
}
double calc_hypotenuse(int side_1, int side_2){//function to find the hypotenuse of the triangle
    
    double hypotenuse;
   	hypotenuse = sqrt ((side_1 * side_1) + (side_2 * side_2));//square root function used to find the hypotenuse.
    return(hypotenuse);
}
double calc_radius_of_smallest_circle(int side_1, int side_2){//function calculatea the radius of the smallest circle.
    double radius1;
    double hypotenuse = calc_hypotenuse(side_1,side_2);
    radius1 = hypotenuse / 2;
    return(radius1);
}
double calc_area_of_smallest_circle(int side_1, int side_2){// calcualtes the area of the smallest circle that is outside of the rectangle
    
    double area,rad,hypotenuse;
    hypotenuse = calc_hypotenuse(side_1,side_2);//calling the function wihich calculates the hypotenuse.
    rad = calc_radius_of_smallest_circle(side_1,side_2);//calling the function which calculates the radius.
    area = circle_area(rad);
    
    return(area);//returns the area of the smallest circle.
}
double calc_area_of_smallest_square( int side_1, int side_2){//calculates the area of the smallest square.
    double smallest_square_area,rad1;
   
    if ( side_1 > side_2)
    	smallest_square_area = pow (side_1,2); 
    else 
    	smallest_square_area = pow (side_2,2); 
    return (smallest_square_area);//returns the area of the smallest square.
}