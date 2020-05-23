#include<stdio.h>
#include<string.h>
#define TEXT_LENGHT 250//define text lenght.
#define NODE_NAMES 10//define node lenght.

void read_tree(FILE *inp,char text_arr[TEXT_LENGHT]);//function which takes and inp file and and array and fills the array form the content of input file.
void ignore_left_spaces(char text_arr[TEXT_LENGHT],char copied_arr[TEXT_LENGHT]);//function ignores the left sides wite space untill a char occures.
int ignore_right_spaces(char text_arr[TEXT_LENGHT],char copied_arr[TEXT_LENGHT],int lenght);//funciton which ignores the wich spaces at the end of any textfiles in a line 
int pars_tree(FILE *out,char tree_arr[TEXT_LENGHT],char word_arr[NODE_NAMES],int parentes,int par,int spaces);//function parst the newick tree representaion as desired format useing recursion.
void print_sign(FILE *outp,int parentes);//function prinths the (-) sign according to the number of it(this function used inside pars_tree function).
void print_one_node(FILE *outp,char main_arr[TEXT_LENGHT],int *counter);//function prints one node even if it is only one word.(used inside pars_tree function).
void print_space(FILE *outp,int space);//print spaces into output file according to the entry.

int main(){

	FILE *inp,*outp;

	char node_arr[NODE_NAMES];//node array will hold only one word at a time.
	char tree_arr[TEXT_LENGHT],cpy_arr[TEXT_LENGHT];//declaring somes used arrays
	int arr_s = 0,par_count = 0,delete;

	inp = fopen("input.txt","r");//open file fron destination. 
	outp = fopen("output.txt","w");//creat and write to output file the results.
	
	read_tree(inp,&tree_arr[0]);//functions call and returns the number of occurence of'(' char in array.
	
	arr_s = strlen(tree_arr);//lenght of tree_arr.
	

	if(arr_s > 0){//if file has some values.
	
		strcpy(cpy_arr,tree_arr);//make a copy of the tree_arr	
		ignore_left_spaces(&tree_arr[0],&cpy_arr[0]);//call functions ignore 
		
		strcpy(cpy_arr,tree_arr);//make a copy of tree_arr	
		
		arr_s = strlen(tree_arr);//lenght if new array.
		delete = ignore_right_spaces(&tree_arr[0],&cpy_arr[0],arr_s);//call function returns the minus of the original size and numbers of spaces to be ignored
		
		tree_arr[delete] = '\0';//delete is  new size of the tree_arr after ignoring right and left sides with spaces.
	}
	
	pars_tree(outp,&tree_arr[0],&node_arr[0],par_count,0,0);//calling pars tree function.

	fclose(inp);
	fclose(outp);
	
	return 0;
}//endof main function.
void read_tree(FILE *inp,char text_arr[TEXT_LENGHT]){//reads from file into an array of character.

	int i = 0,status = 0;
	char ch;
	
	while(!feof(inp)){

		status = fscanf(inp,"%c",&ch);
		
		if(status == 1 && ch != '\n'){
		
			text_arr[i++] = ch;	
		}

	}
	text_arr[i]='\0';	
}
void ignore_left_spaces(char text_arr[TEXT_LENGHT],char copied_arr[TEXT_LENGHT]){//ignores the left sides with spaces using recursion.

	if(copied_arr[0]!=' '){//goo untill encountera char at the beggining of the string.
		
		strcpy(text_arr,&copied_arr[0]);	
	}
	else{

		ignore_left_spaces(text_arr,&copied_arr[1]);//calling functin itself with new index.

	}
}
int ignore_right_spaces(char *text_arr,char *copied_arr,int lenght){//ignores the leftsides with spaces using recursion.

	
	if(copied_arr[lenght-1]!=' '){
		
		return lenght;//rturns the lenght of how many spaces whre ther at the end of strign 
	}
	else{
		
		lenght = ignore_right_spaces(text_arr,copied_arr,lenght-1);//calling funcitns recusrsivly
		return lenght;
	}

}//end of funcition.

int pars_tree(FILE *out,char *tree_arr,char word_arr[NODE_NAMES],int parentes,int par,int spaces){//core functions parses the array which simply holding the newick represented tree ,the core functin of this project is this
																				/*function takes illestraded data as input finally writes into the output file it call itself acording to the given input files content and calls inside itself some other functions to make a complete program.it check for some known combinitions and manipulates the certaind array according to that and makes use of it,*/
	int counter = 0;
	
	if (tree_arr[0]=='\0'){//if we rich to end of file then terminate the function ad return to calling area.
		
		return 0;
	}
	else{//otherwise check the combinations untill rich to the end of file.

		if(tree_arr[0] =='('){//if certain value is left faced comma then do this
			
			pars_tree(out,&tree_arr[1],word_arr,++parentes,1,0);
			word_arr[0] = '\0';
			
			return 0;
		}
		else if (tree_arr[0] == ')'){
			
			pars_tree(out,&tree_arr[1],word_arr,--parentes,1,0);//call itself after update some inout values of it
			word_arr[0] = '\0';
			
			return 0;
		}
		else if (tree_arr[0] == ','){
			
			pars_tree(out,&tree_arr[1],word_arr,parentes,1,0);//call itself after update some inout values of it
			word_arr[0] = '\0';
	
			return 0;
		}
		else if (tree_arr[0] == ' ' && (par == 1)){
			
			spaces++;//increment space 
			
			if(tree_arr[1]!= ' '){

				pars_tree(out,&tree_arr[1],word_arr,parentes,0,spaces);//call itself after update some input values of it

			}
			else{
				
				pars_tree(out,&tree_arr[1],word_arr,parentes,1,spaces);//call itself after update some input values of it

			}

		}	
		else{

			if (spaces!= 0){//if we have spaces after prantheses before reaching to any character.
			
				print_sign(out,parentes);//calling funciton print_sign
				print_space(out,spaces);//print spaces.

			}
			else{

				print_sign(out,parentes);//calling funciton print_sign

			}

			print_one_node(out,&tree_arr[0],&counter);//calling function printf_one_node
			
			if(tree_arr[1]!='\n')
			{
			 	//printf("%c\n",tree_arr[0]);
			 	fprintf(out,"\n");

			 }
			
			pars_tree(out,&tree_arr[counter],word_arr,parentes,0,0);//call itself after update some inout values of it
			
			word_arr[0]='\0';
			return 0;//if successfull then return 0.
		}	
	}
}
void print_sign(FILE *outp,int parentes){//funciton which takes output file pointer and number of how any (-) it should print and prints the sign recursivly as indecated bellow.


	if (parentes == 0){

		return;
	}
	else{

		fprintf(outp,"-");//print into output file.
		print_sign(outp,--parentes);
	}
	return;

}
void print_one_node(FILE *outp,char *main_arr,int *counter){//funciton which takes output file pointer and the main array whic holdes the actual mewick tree inside and returns the lenght of a node so that in the next iteration in callling area we can start from desired index .


	if(main_arr[0] == '\0' || main_arr[0] == '(' || main_arr[0] == ')' || main_arr[0] == ','){//iterate untill one oof these characters has been encountered.
		
		return ;
	}
	else{

		
		fprintf(outp, "%c",main_arr[0]);//write into output fil
		
		*counter  =*counter + 1;//incerement the counter .
		print_one_node(outp,&main_arr[1],counter);//call function itself again with updated values.
		
		return;
	}

}
void print_space(FILE *outp,int space){//this function creats space accordong to the given entiry.
	
	if (space == 0){

		return;
	}
	else{

		fprintf(outp," ");//print into output file.
		print_space(outp,--space);
	}
	return;

}
