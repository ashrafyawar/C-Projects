#include<stdio.h>
#define p1 0.5
#define p2 20
int min(const double a[],int size);
void sort_my_chunck(double array1[],int array2[],double array3[100][1000],int size,int keep_ind[]);
void print_to_file(double chunks[100][1000],int holded_ind[],int size,FILE *output);

int main(){
	

	FILE *inp; //file pointer input.
	FILE *outp;//file pointr output;
	
	int sorted_ar_ind[100];//array for store the indexes of the new sorted arrays.
	int nth_num = 1,i = 0,j = 0,k = 0,test = 0 ,counter = 0,start,ind,t = 0,store_num = 0,status = 0;/*decleration parts*/
	int number = 1,e,old_index[1000],l;
	
	double n,a = 0.0,b = 0.0,temp_sum = 0.0;
	double chunks_ar[100][1000];//array for store the chunks with their elements.
	double chunks_average[100];//array for stor the averages of the chunks.

	inp = fopen("input.txt","r");//opening the file read mode
	
	outp = fopen("output.txt","w");//opening the file as write mode

	while(!feof(inp))//will itarate tiil reachs the end of file
	{	
	
		if (store_num == 0){
		
			fscanf(inp,"%lf",&n);//first we scan the data into an array of dimentions.
			
		}		
			
		a = n/nth_num++;//firstly we assing a the very first number of the chunks to a 
		
		chunks_ar[i][j++] = n;//and then assing it to the array  

		fscanf(inp,"%lf",&n);//get an other number from the file
			
		b = (a + n)/nth_num++;//and calculate the average b here
			
		temp_sum = a + n;//to keet track of the sum of the numbers in the chunks	
		
		while(!(b > (a*(1 + p1))|| b < (a*(1 - p1)) || a > (n*p2)|| a < (n/p2)) && (!feof(inp)))//the main condition ot add the getting number to the chunk
		{
	
			chunks_ar[i][j++] = n;
			
			a = b;//store the last value of b as a.
			
			status = fscanf(inp,"%lf",&n);
			
			if (status==1)
			{
				
				status = 0;
	
				temp_sum = temp_sum + n;//numbers total
				
				b =((double)(temp_sum)/(double)nth_num++);//b is the new average 				
			
				if (!(b > (a*(1 + p1))|| b < (a*(1 - p1)) || a > (n*p2)|| a < (n/p2))){// i put this condition so that i can check and maintain the next scanf whether it should take it or not
						
					store_num = 0;

				}
				else{//else i put a flag so that it should decide that to take the first or second scanf in the next iteration.
					
					store_num = 1;
				}		

			}
			
		}
		
		chunks_average[k] = a;//this array which is integer array collects the all average of the chunck in corresponding cells 

		a = 0;
		b = 0;
		j = 0;
		
		nth_num = 1;//counts the count of numbers in each iteration.
		k++;
		i++;
		
	}

	for (i = 0; i < 1000;++i)//filling array from 0 to 1000 cotigously.
	{
		
		old_index[i]= i;

	}
	
	sort_my_chunck(chunks_average,sorted_ar_ind,chunks_ar,k,old_index);//fucntion calling 
	
	print_to_file(chunks_ar,old_index,k,outp);//this functions assings and stores the values of the chunks to the output files.

	fclose(inp);//closing files.
	fclose(outp);//closing files.

	return 0;
}
void sort_my_chunck(double array1[],int array2[],double array3[100][1000],int size,int keep_ind[]){//this function takes  a 2D array which holds the chunkd inside and an rray which holds index of the corresponding chunks and an array which contains contingous numbers from 0 to 100 and returns back the corresponding indexes of the ordered chunks so that make it easy to print them on the output file
		
	int i,ind,temp1,temp2,j,k;	
	
	for( i= 0; i < size;i++)
	{
    
        for(j=i+1; j< size; j++)
        {
          
            if(array1[i] > array1[j])
            {
    
                temp1 = array1[i];//last three rows swaps the values inside average array.
                array1[i] = array1[j];
    			array1[j] = temp1;
    			
    			temp2 = keep_ind[i];//last three rows swapps the corresponding index of the cunkncks and sends back the array so that to be used to print the chunks in the output file.
    			keep_ind[i] = keep_ind[j];
    			keep_ind[j] = temp2;   
           
            }

        }

	}

}
void print_to_file(double chunks[100][1000],int holded_ind[],int size,FILE *output){

	int counter,i,j;
	counter = 0;//counter will make our work easy to find the index of the which number should we store in the out put file  by	
	
	while(counter!=size)//this loop iterates untill we completly store the all desired values of the required array's data.
	{
		
		for ( i = 0; i < 100; ++i)//this loop iterates for each cell of the old_index array to find the which untill wich values of it mathces with the i.
		{
					
			if (i == holded_ind[counter])//condition to store the deisred data to the output file
			{

				for ( j = 0; j <=size; ++j)
				{
					
					if (chunks[i][j]!=0)
					{
						fprintf(output, "%lf ",chunks[i][j]);//print the result to the output file.
					}
				
				}
				
				fprintf(output,"\n");
			}
		}
	
		counter++;	
	}

}