#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#define BUFFER 20
typedef struct{

	int size;
	char string[BUFFER];
	char junk[BUFFER];
	int array_of_nums[1000000];
}Read;

typedef struct list{

	int prime_num;
	struct list *link;

}prime_num_list;

Read read_file(void);
prime_num_list *prime_link_list(Read *read_structure,int limit_size,double *cal_time_in_mili);
double  prime_array(Read *read_structure,int size);
void compare_write_calc_time(Read *my_struct);
void prime_ckeker(Read *my_struct);


int main(){
	
	Read *my_struct;
	int i;
	
	my_struct = (Read*)malloc(sizeof(Read));//allocating area in memory to the structure.
	
	*my_struct = read_file();//storing and calling function area.
	
	/*please do activate the following functions respectively to check and test the code results i have explained all the works of the function in thier function prorotype.*/
	read_file();//you can open the fucntion and test it which reads the file and stores the contents of the file in an array.
	
	//prime_ckeker(my_struct);//you can also check this functions which calls two functions inside of it which are finding the prime numbers respectivly linked and dynamicly array.
	//compare_write_calc_time(my_struct);
	return 0;
}
Read read_file(void){//this function reads a file as a string and the takes the file content untill the comma has encountered and the converts is the string data to the integer and store it in an structure array which we can use it later on to anothe purpose in functions bellow.
	
	Read *read_structure;
	FILE *input;
	char ch;
	int i = 0,k = 0 ;

	read_structure = (Read*)malloc(sizeof(Read));//allocating area for the structure type variable.

	input = fopen("data.txt","r");
	
	if (input == NULL){
		printf("make sure that you opened correctly the file !!!\n");
	}

	else{
		
		read_structure->size = 0;
		
		while(fgets(read_structure->junk,BUFFER,input)){//take a line from the file .
		
			k = 0;
			for (ch = read_structure->junk[k];ch !=',';ch = read_structure->junk[k]){
				
				read_structure->string[k] = read_structure->junk[k];//store the data untill , has encountered 
				k++;
			}
				
			read_structure->array_of_nums[i] = atoi(read_structure->string);//changing the atring to integer.
			
			//printf("reading from file ... >>> %d\n",read_structure->array_of_nums[i]);//i put this print function if you whould like to test my code to print the contednt of the filled array of structure .
			i++;

			read_structure->junk[k]='\0';
			read_structure->string[k]='\0';
		
			read_structure->size++;
		}

	}

	fclose(input);//closing the file.
	return(*read_structure);//returrnig the structure.
}
void prime_ckeker(Read *my_struct){//this functions calls the linked and dynamic array functions and sends a number from 1-1000000 and checks the prime number which is evaluated in both linked and prime array functions.
	
	double calc_time = 0;

	//prime_link_list(my_struct,1000000,&calc_time);
	//prime_array(my_struct,1000000);

}
prime_num_list *prime_link_list(Read *read_structure,int limit_size,double *cal_time_in_mili){//this function takes a structure and an int and a double as input and inside evaluate the prime numbers in side file and stores the pimes numbers in linked list an returns th elinked list which will be used in the next steps maybe.

	int i = 0,counter=0,j=0,quantity = 0;
	clock_t started_time,end_time;
	double time_in_sec;
	prime_num_list *headp,*test,*temporaryp;//creating piunters of linked list.

	headp = (prime_num_list*)malloc(sizeof(prime_num_list));//allocating the first node to head node 

	test = headp;//copping the content of the head too the test pointer vaiable.

	if (read_structure->array_of_nums == NULL){//conditioin to check whther the head node is empty or not.

		headp = NULL;
	}
	else{

		started_time = clock();
		for (i = 0; i < limit_size; ++i){

			counter = 0;

			temporaryp = (prime_num_list*)malloc(sizeof(prime_num_list));//allocating the space for the temporary node 
			
			for (j = 1; j <=read_structure->array_of_nums[i]; j++){
				
				if (read_structure->array_of_nums[i] % j == 0){
					counter++;
				}

			}
			if (counter == 2){//condition to be prime numbe
				
				temporaryp->prime_num = read_structure->array_of_nums[i];//storing the peime nums to the linked list
				
				printf(" prime numebrs in link_list are >>> %d\n",temporaryp->prime_num);//if you want you can see the prime num results in screen juct take the coment line out .
				
				test->link = temporaryp;//cerat another node 
				quantity++;//the quantity of the prime read by if condition
			}

		}

		test->link = NULL;//the last pointer link of the last node must be null. 
		
		end_time = clock();
		
		time_in_sec= (double) ((end_time - started_time)/(CLOCKS_PER_SEC));
		
		*cal_time_in_mili  = time_in_sec * 1000;
	}
	printf("the quantity of the prime numbers  read into linkedlist are >>> %d\n",quantity);
}
double prime_array(Read *read_structure,int size){//this function reads the files contedn which is in structure array and store the prime numbers in to dynamicly allocated array according to the size given 

	int i = 0,j = 0,counter = 0 ,quantity= 0 ;
	int *array;
	clock_t started_time,end_time;
	double time_in_sec,cal_time_in_mili;

	array = (int *)(malloc(size * sizeof(int)));//allocating area in memory for array with respect to size of array.

	started_time = clock();//setting the timer to calculate the time taken inside the for executions here>>>
	for (i = 0; i < size;i++){
		
		counter = 0;

		for (j = 1; j <= read_structure->array_of_nums[i]; j++){
			
			if (read_structure->array_of_nums[i] % j == 0){
				counter++;
			}
		}
		
		if (counter == 2){
		
			array[i] = read_structure->array_of_nums[i];//storing the prime numbers to dynamicly allocated array.
			printf(" primes in dynamicly allocated arra  are  >>> %d\n",array[i]);//here you can take the coment line out and test the prime numbers printing .(optional)
			quantity++;//the quantity of the prime read by if condition
		}
	
	}

	end_time = clock();//end time .	
	time_in_sec = (double)((end_time - started_time) / (CLOCKS_PER_SEC));//time calclation in seconds.
	cal_time_in_mili = time_in_sec * 1000;//time calculation in mili seconds.
	
	printf("the quantity of the prime numbers are read into dynamic array are >>> %d\n",quantity);//you can take the comment line out to activate this function and check the quantity of the primes in if condition above.

	return (cal_time_in_mili);//return the time taken.
}

void compare_write_calc_time(Read *my_struct){//this functions takes a strutures and writes the time takens in diffrent exeutions inside the other function in partecular in linked list and dynamicly allocated array here and writes that time takens inside a file txt file to used.

	FILE *print_link_to_file,*print_array_to_file;
	clock_t started_time_link,end_time_link;
	double cal_link1 = 0,cal_link2= 0 ,cal_link3= 0 ,calc_arr1= 0 ,calc_arr2= 0 ,calc_arr3= 0;
	double started_time_arr,end_time_arr,time_in_sec_arr,cal_time_in_mili_arr,total1,total2,total;
	int i;


	print_link_to_file = fopen("output_prime_linkedlist.txt","w");//opennig the file.

	if (print_link_to_file==NULL){

		printf("enable to opne the file !!!\n");
	}
	else{

		prime_link_list(my_struct,500000,&cal_link1);//calling fucntion prime_link_list.
		fprintf(print_link_to_file, "%lf\n",cal_link1);//storing to an txt file 
		
					 
		prime_link_list(my_struct,750000,&cal_link2);//calling fucntion prime_link_list.
		fprintf(print_link_to_file, "%lf\n",cal_link2);//storing to an txt file


		prime_link_list(my_struct,1000000,&cal_link3);//calling fucntion prime_link_list.
		
		
		started_time_link = clock();//setting the timer to calculate the time taken.
		total1 =(double)started_time_link/CLOCKS_PER_SEC;

		fprintf(print_link_to_file,"%lf\n",cal_link3);//storing to an txt file
		
		end_time_link = clock();
		
		total2  = (double)end_time_link  / CLOCKS_PER_SEC	;
		
		total = (total2 - total1)*1000;		
			
		fprintf(print_link_to_file, "file writtten time is:%lf\n",total);//storing to an txt file
		printf("the time taked to write the digits from 1 to 1000000 in msec in linked list is >>> %lf\n",total);

	}

	print_array_to_file = fopen("output_prime_dynamic_array.txt","w");

	if (print_array_to_file == NULL){

		printf("enable to access the file !!!!\n");
	}
	else{

		calc_arr1 = prime_array(my_struct,500000);//calling functioin prime_array.
		fprintf(print_array_to_file, "%lf\n",calc_arr1);//storing to an txt file
		
		calc_arr2 = prime_array(my_struct,750000);//calling functioin prime_array.
		fprintf(print_array_to_file, "%lf\n",calc_arr2);//storing to an txt file

		
		calc_arr3 = prime_array(my_struct,1000000);//calling functioin prime_array.
	
		started_time_arr=clock();
		
		fprintf(print_array_to_file, "%lf\n",calc_arr3);//storing to an txt file
		
		end_time_arr = clock();
		
		time_in_sec_arr = (double)((end_time_arr - started_time_arr) / (CLOCKS_PER_SEC));
		
		cal_time_in_mili_arr = time_in_sec_arr * 1000;//time in unit of mili seconds.

		printf("the time taked to write the digits from 1 to 1000000 in msec in array is >>> %.3lf\n",cal_time_in_mili_arr);

		fprintf(print_array_to_file, "file written time:%lf\n",cal_time_in_mili_arr);//storing to an txt file

	}
	fclose(print_link_to_file);//closing the file.
	fclose(print_array_to_file);//closing the file.

}//end of function
