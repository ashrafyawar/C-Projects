#include<stdio.h>
#include<stdlib.h>
#define BUFFER 1024
void menu();
void encrypt_open_msg();
void decrypt_secret_msg();
int find_size_of_line(char line[]);
void reverse_line(char line[], int line_lenght);
void reverse_line_decrept(char line[],int line_lenght);//exrtra function that i hace writhen to use it bellow.

int main(){

	menu();
	return 0;
}//end of main fucntion.
void menu(){
	
	int choise;
	
	do{
	
		printf("1. Encrypt\n2. Decrypt\n0. Exit\n");
		printf("Choice:");

		scanf("%d",&choise);

		switch(choise){

			case 1:
				encrypt_open_msg();
			break;

			case 2:
				decrypt_secret_msg();
			break;

			case 0:
			break;

			default :
			printf("invalid input!!\n" );
		}

	}while(choise != 0);//termination condition for do_while loop.

}//end of function.
void encrypt_open_msg(){
	
	FILE *input,output;//file pointer decleration.
	int key_number,i = 0,size_line = 0,result=0,over_flow=0,new_valus=0,remainder=0;
	char string[BUFFER],ch;	

	do{//asking for a valid interger from the user.
	
		printf("key :");
		scanf("%d",&key_number);

	}while(key_number <=1 || key_number >= 26);

	input = fopen("open_msg.txt","r");//openning the file contents and reading it.

	do{//loop for geting data from the file.
	
		ch = fgetc(input);
		string[i] = ch;
		i++;
	}while(ch !='\n');
	
	string[i] = '\0';
	size_line = find_size_of_line(string);

	reverse_line(string,size_line);

	for ( i = 1; i < size_line+1; i++){

		if (string[i]!='_'&&string[i]!='*'){
		
			over_flow = string[i]-(int)key_number;
			if (over_flow>=97){
				string[i]=over_flow;
			}
		
			else if (over_flow < 97){
				
				over_flow = string[i]-(int)key_number;
				new_valus = (int)string[i] - 97;
				remainder = key_number - new_valus; 	
				result = 123-(int)remainder;
				string[i] = result;
			}
		}
	}
	printf("%s",string );

	input = fopen("secret_msg.txt","w");//storing the file.
	fprintf(input,"%s",string);

	fclose(input);
}//end of function encreypt.
void decrypt_secret_msg(){

	FILE *input,output;//file pointer decleration.
	int key_number,i = 0,size_line = 0,result=0,over_flow=0,new_valus=0,remainder=0;
	char string[BUFFER],ch;	

	do{//asking for a valid interger from the user.
	
		printf("key :");
		scanf("%d",&key_number);

	}while(key_number <=1 || key_number >= 26);

	input = fopen("secret_msg.txt","r");//openning the file contents and reading it.

	do{//loop for getting data from the file.
	
		ch = fgetc(input);
		string[i] = ch;
		i++;
	
	}while(ch !='\n');
	
	string[i] = '\0';//manualy putting the null character at the  end of the string.
	
	size_line = find_size_of_line(string);//callinf find size function
	printf("%s",string );

	reverse_line_decrept(string,size_line);//callinf reverse funntion
	for ( i = 0; i < size_line; i++){//replacing the apropriate cahrather to the corresponding cahrachter according to the key value entered.

		if (string[i]!=' '&&string[i]!='*'){
			
			over_flow = string[i]+(int)key_number;
			
			if (over_flow<=122){
				string[i]=(int)over_flow;
			}

			else if (over_flow >122){	
				new_valus = (int)over_flow -122;
				result = 96 + (int)new_valus;
				string[i]=(int)result;
			}
		}
	}
	printf("%s",string );
	input = fopen("open_msg.txt","w");//storing the file.
	
	fprintf(input,"%s",string);//storing the string array to the file.
	
	fclose(input);//closing the file.
}
void reverse_line(char line[], int line_lenght){//function ot reverser the contains of the file.

	int i=0,j=0,temp_counter = 0;
	char temp,temp_array[line_lenght];

		for (i = 0; i < line_lenght/2; i++){
					
			temp = line[i];	
			line[i]=line[line_lenght-1-i];
			line[line_lenght-1-i] = temp;
							
		}			
		for (i = 0; i < line_lenght-1; i++){

			line[0]=' ';
			if (line[i+1]==' '){
				line[i+1]='_';
			}
			if (line[i]=='.'){
				temp = line[i];
			}
		}
		line[i+1]='*';
}
void reverse_line_decrept(char line[],int line_lenght){//function to reverece the contains of the secret file.
	
	int i=0,j=0,temp_counter = 0;
	char temp,temp_array[line_lenght];

		for (i = 0; i < line_lenght/2; i++){//revreses the intire line.
		
					
			temp = line[i];	
			line[i]=line[line_lenght-1-i];
			line[line_lenght-1-i] = temp;
							
		}			

		for (i = 0; i <=line_lenght; i++){
		
			if (line[i+1]=='_')//checks whether the if statment is true
				line[i+1]=' ';
		}
}
int find_size_of_line(char line[]){

	int i=0,character = 0;
	for ( character = line[i];character!='\n';character = line[i]){
		i++;
	}
	return i-1;
}