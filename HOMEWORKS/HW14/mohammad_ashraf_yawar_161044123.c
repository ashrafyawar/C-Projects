#include<stdio.h>
#include<string.h>

#define COL_AR 250
#define ROW_AR 100
#define WORD_LEN 10//marco defined to size of array.

int check_horsintaly(char word_ar[10],char trach_ar[ROW_AR][COL_AR],int row_size,FILE *outp);//function which takes a 1D and 2D array of characters and a file pointer to print into and size of how many rows in teh 1D array and finds the correspoding word from the 2D array and stores if finds to the output file
int check_vertically(char word_ar[10],char trach_ar[ROW_AR][COL_AR],int row_size,FILE *outp);//function which takes same as check_horizontaly function and searches the certain word in a buck of charakters as vertically order.and in seccessfull maner stores it in a  given file

int main(){

	
	FILE *inp1,*inp2,*outp;//file pointer to open files

	inp1 = fopen("input1.txt","r");//input1 file
	inp2 = fopen("input2.txt","r");//input2 file
	outp = fopen("output.txt","w");//output file opened.
	
	char word_ar[WORD_LEN];//array which holds a word a time.
	char trach_ar[ROW_AR][COL_AR];//array  of 2D
	char ch;
	int i = 0,j = 0,test = 0,hor_pos = 0,row_size =  0,find = 0;//some used valiables in down.
	
	while(!feof(inp2)){//storing the input2 file's content to a 2D array.
		
		fscanf(inp2,"%c",&ch);//take a char at a time.
		
		while (ch!='\n')//go till a new line
		{

			trach_ar[i][j] = ch;
			fscanf(inp2,"%c",&ch);
			
			j++;
		}//end of inner loop
		
		i++;
		j = 0;
		row_size++;//size of row of the input file.
	
	}//edn of outer loop
	
	i = 0;//set i zero to be used in down.
		
	while(!feof(inp1))//loop iterates till the end of file.
	{
		
		fscanf(inp1,"%c",&ch);
		
		while (ch!='\n'){//it takes each character at a time and stores in word_ar[].

			word_ar[i] = ch;
			
			fscanf(inp1,"%c",&ch);		
			
			i++;
		}
		word_ar[i] = '\0';//set the end of the array to null so that we can use it properly in the future.
				
		find = check_horsintaly(word_ar,trach_ar,row_size-1,outp);//calling fucntion and send the certain values to it adn get the restul if find if 1 it means that we have found the locatin of the certain word by seaching it horizontaly
		
		if (find!= 1)//if find is not 1 means that we couldnt find in the certain itration the looked for word by seaching it horizontaly.
		{
			check_vertically(word_ar,trach_ar,row_size,outp);//and if it so then look fo the certain word by seaching it vetically.

		}

		i = 0;//set i zero cause will be used in the next iteration as the first element of the word_ar[].
	}

	fclose(inp1);//closing the files.
	fclose(inp2);//closing the files.
	fclose(outp);//closing the files.

	return 0;
}//end of main function

int check_horsintaly(char word_ar[10],char trach_ar[ROW_AR][COL_AR],int row_size,FILE *outp){//functions job has been discrebid in the functions prototype


	int i = 0,j = 0,row = 0,col = 0,counter = 0,test_column = 0,flag = 1;
	char temp_ar[WORD_LEN],ch,current_col = 0;//some locally used valirables.
	while (row_size!= 0){//this loop will iterate till the last row since it is a horzintally seach method function.
		
		row_size--;//reducing size of rows in each iteration.
		test_column = 0;//a way to get in to the inner loop

	 	while(test_column == 0 && trach_ar[row][col]!='\0'){//loop which iterates till end of the certaind row or end according to the found condition.
			
			if (word_ar[counter] == trach_ar[row][col]){// the current char in both of the arrays are matching then get in to the (if).
				
				temp_ar[counter] = word_ar[counter];//store the char to temp array.
				counter++;//point ot next char in array word_ar[].
				col++;//point to next char in certain row if trach_ar[][].
				flag = 1;//successfully stored a char to the array temp_ar.

				while (flag == 1){//loop which iterates till the flag is 1 and flag 1 means that we have succecfully matched the certain character.
			
					if(word_ar[counter] == trach_ar[row][col] && ((strlen(&word_ar[counter]))!= 0)){//this if check whether the certains char is matching and the left character in the certaind row is not smaller than the word to be checked for
					
						temp_ar[counter] = word_ar[counter];//store the certain char into the temp_ar

						counter++;
						col++;
						flag  = 1;//still matching.
					}
					else{//else go to the loop and iterat again 

						flag = 0;
						test_column = 0;
					}

				}//end of inner loop

				if (flag == 0 && (strlen(&word_ar[counter]))== 0){//if we have succefull natch the all characters and find its head location so get in to the if statement .
					
					row++;//since indexes starts from one in this particular progect so i have incremented the coordenates of  x and y by one(down line also means it)
					current_col++;
					temp_ar[counter] = '\0';//set null to the end of the char so that can be stored correctly in anywhere.
										
					fprintf(outp,"%s (%d,%d) Horizontal",temp_ar,row,current_col);//store the found word wiht it's coordenates and oryantaion into output file.
					fprintf(outp,"\n");
					
					return 1;
				}
				
			}//end of outer if statement.
			else//if didn't match so go to the itration again and try again till loop conditon terminates.
			{
				test_column = 0;
				counter = 0;
				current_col++;//point to the next colunm.
				col = current_col;
			}

		}//end of the first inner loop
	
		counter = 0;
		row++;//poin to next row
		current_col = 0;
		col = current_col;//point to the first colunm of the certain row
	
	}//end of the outer loop
	return 0;
}
int check_vertically(char word_ar[10],char trach_ar[ROW_AR][COL_AR],int row_size,FILE *outp){//function's job has been determined in the prototype.


	int i = 0,j = 0,row = 0,col = 0,counter = 0,test_row = 0,flag = 1,my_lent,count = 0,current_row = 0;
	char temp_ar[WORD_LEN],ch;
		
	while(row_size!=0 && row_size >= (strlen(word_ar)))//this loop iterates untill the end of rows.
	{
		
		row_size--;//point ot next row downward.
		
		my_lent = strlen(&trach_ar[count][0]);//i take in avery iteratiin the certain lines lenght search vertically untill that lenght 		
		
		while (my_lent!= 0)//loop will iterate till the lenght of the certain row is zero.
		{
			
			test_row = 0;

		 	while(test_row == 0 && trach_ar[row][col]!= '\0')//test column = 0 means didnt match in the first attempt.
			{
				
				if (word_ar[counter] == trach_ar[row][col])// the current char in both of the arrays are matching then get in to the if statement
				{
					
					temp_ar[counter] = word_ar[counter];//store the char to temp array.
					
					row++;
					counter++;
					flag = 1;//successfully stored a char to the array temp_ar.
					
					while (flag == 1)
					{
				
						if(word_ar[counter] == trach_ar[row][col] && ((strlen(&word_ar[counter]))!= 0)) 
						{
						
							temp_ar[counter] = word_ar[counter];

							counter++;
							flag  = 1;//still matching.
							row++;
						
						}
						else 
						{
							flag = 0;
							test_row = 0;
						}

					}
					if (flag == 0 && (strlen(&word_ar[counter]))== 0)//if we have succefullly found the certaind word in the trach_ar so store it into output file and terminate the funcion.
					{
						
						temp_ar[counter] = '\0';
						current_row++;
						col++;
										
						fprintf(outp,"%s (%d,%d) Vertical",temp_ar,current_row,col);// to output file store the certain word. 
						fprintf(outp,"\n");
						
						return 1;//means that i have found the exact matching of the certains word.

					}
				
				}
				else//if  the certain charakteres didnt match then ponit to the next char in certain row
				{
				
					test_row = 0;
					counter = 0;
					current_row++;
					row = current_row;
					
				}

			}//end of inner loop
		
			counter = 0;
			col++;
			current_row = 0;
			row = current_row;
			my_lent--;
		
		}//end of fisrt inner loop
		
		count++;
	}//end of outer loop
	return 0;
}//end of check_vetically function.
