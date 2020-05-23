#include<stdio.h>
#include<stdlib.h>
void change_format(int start_day_number);
void input_date();
#define BUFFER 1000000
int find_first_day(int first_day,int first_month,int first_year);

int main(){
	
	input_date();
	return 0;
}//end of main function

void input_date(){

	FILE *input;//declaration parts
	int first_day,first_month,first_year;
	int last_day,last_month,last_year,i=0,j=0,k=0,a = 1,b = 1;
	int endofmonth, endofday,result;
	int days[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};//declaring integer array
	
	input  = fopen("input_date.txt","w");//opening the file.

	printf("Enter the start_date in format of: dd/MM/yyyy >>>\n");//promting the user for the start date
	scanf("%d%d%d",&first_day,&first_month,&first_year);
	
	printf("Enter the end_date in format of : dd/MM/yyyy >>>\n");//promting the user for the end date
	scanf("%d%d%d",&last_day,&last_month,&last_year);

	for (i = first_year; i <= last_year; ++i){//loop to generate all the desited date between to entered dates .

		if (0 == i % 4)//condition for the february month which it's day count varies avery after four year betweed 28 and 29 days.
			days[2] = 29;
		else
			days[2] = 28;

		if (i < last_year)//conditiono to print the desired last month the following if and else .
			endofmonth = 12;
		else
			endofmonth = last_month;

		for (j = first_month; j <= endofmonth; ++j){//condition to genete the desied month between desired dates.

			first_month = 1;

			if (j < endofmonth)//condition to print the varous end of the month days in a year.
				endofday = days[j];
			else{

				if (i == last_year)
					endofday = last_day;
				else
					endofday = days[j];
			}

			for (k = first_day; k <= endofday; ++k){//printig the desired dates day month and year respectively.
			
				if(k < 10 && j > 9){

					fprintf(input,"0%d/%d/%d\n",k,j,i);//k=days,j=months,i=year in here.
					first_day = 1;				
				}

				else if (j < 10 && k > 9){

					fprintf(input,"%d/0%d/%d\n",k,j,i);//k=days,j=months,i=year in here.
					first_day = 1;		
				}
				else if(j < 10 && k < 10){

					fprintf(input,"0%d/0%d/%d\n",k,j,i);//k=days,j=months,i=year in here.
					first_day = 1;
				}
				else if(k > 9 && j > 9){

					fprintf(input,"%d/%d/%d\n",k,j,i);//k=days,j=months,i=year in here.
					first_day = 1;
				}
			}
		}
	}
	fclose(input);//closing the file 

	result = find_first_day(first_day,first_month,first_year);//the number of the day where it should start from.
	change_format(result);//calling the function.

}//end of input date
void change_format(int start_day_number){

	char *month_names[12]={"january","february","march","april","may","june","july","august","september","october","nevember","december"};
 	char *day_name[7]={"sunday","monday","tuisday","widnesday","tursday","friday","saturday"};
 	int i = 0,k=start_day_number,line=0,j = 0;
 	FILE *input,*output;
 	char file_input[50];
 	char upateded_date[BUFFER];
 	char day[3],month[3],year[5];
 	
 	input  = fopen("input_date.txt","r");//opening the file in the read mode.
 	output = fopen("new_date.txt","w");//open file in write mode. 	

	while(fgets(file_input,BUFFER,input)){//get line by line from the file in to the char array

		for (j = 0; file_input[j]!='\n' ; ++j){//get untill the slash has found and store in varous char arrays down all if else conditions...
		
			if (j< 2 && file_input[j]!='/'){
			
			day[0] = file_input[0];
			day[1]=file_input[1];
			}

			else if (j < 5 && j > 2 && file_input[j]!='/'){

				month[0] = file_input[3]; 
				month[1] =file_input[4];
				month[2]='\0';
			}

			else if (j > 5){

				year[0] = file_input[6];
				year[1] = file_input[7];
				year[2] = file_input[8];
				year[3] = file_input[9];
			}
		}

		if (month[0] =='0'&& month[1]=='1')//check whether the first two elements of the month arrays match so do the {}.
			sprintf(upateded_date,"%s,%s %s,%s",day_name[k],month_names[0],day,year);

		else if (month[0] =='0'&& month[1]=='2')
			sprintf(upateded_date,"%s,%s %s,%s",day_name[k],month_names[1],day,year);
		else if(month[0] =='0' && month[1]=='3')
			sprintf(upateded_date,"%s,%s %s,%s",day_name[k],month_names[2],day,year);
		else if (month[0]=='0'&&month[1]=='4')
			sprintf(upateded_date,"%s,%s %s,%s",day_name[k],month_names[3],day,year);
		else if (month[0]=='0'&&month[1]=='5')
			sprintf(upateded_date,"%s,%s %s,%s",day_name[k],month_names[4],day,year);		
		else if (month[0]=='0'&&month[1]=='6')
			sprintf(upateded_date,"%s,%s %s,%s",day_name[k],month_names[5],day,year);		
		else if (month[0]=='0'&&month[1]=='7')
			sprintf(upateded_date,"%s,%s %s,%s",day_name[k],month_names[6],day,year);		
		else if (month[0]=='0'&&month[1]=='8')
			sprintf(upateded_date,"%s,%s %s,%s",day_name[k],month_names[7],day,year);	
		else if (month[0]=='0'&&month[1]=='9')
			sprintf(upateded_date,"%s,%s %s,%s",day_name[k],month_names[8],day,year);		
		else if (month[0]=='1'&&month[1]=='0')
			sprintf(upateded_date,"%s,%s %s,%s",day_name[k],month_names[9],day,year);	
		else if (month[0]=='1'&&month[1]=='1')
			sprintf(upateded_date,"%s,%s %s,%s",day_name[k],month_names[10],day,year);	
		else
		 	sprintf(upateded_date,"%s,%s %s,%s",day_name[k],month_names[11],day,year);	
		
		fprintf(output, "%s\n",upateded_date );
		i++;
		k++;
		if (k == 7)
			k = 0;
	}

	fclose(input);
}//end of change format functions.
int find_first_day(int first_day,int first_month,int first_year){//function which finds the start_date of the corresponding date.

	int result,m,k,d,i = 3, final,c;
	k = first_day;
	if (first_month == 1)
		m = 11;
	else if (first_month==2)
		m = 12;
	for (i = 3; i <=12 ; ++i){
		if (first_month == i)
			m = i - 2;
	}
	
	d =  first_year % 100;//last two digtits of the year.
	c = first_year / 100;
	final = k + ((13 * m - 1)/ 5)+ d +(d / 4) + (c / 4) - (2 * c);//y makeing use of the zeller's methode.
	result  = final / 7;//the number of the day which it shoud start from		

	return (result);
}