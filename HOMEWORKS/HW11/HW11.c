#include<stdio.h>
#include <stdlib.h>
#include<string.h>
#define BUFFER 10000

struct Customers{

	int cus_room_num;
	char cus_name[50];
	char cus_sure[50];
	int cus_age;
	char cus_gender[50];
	struct Customers *cus_next;

};

struct Customers *root_read_cus  = NULL;

struct Rooms{

	int room_num;
	int capacity;
	int floor;
	struct Rooms* r_link;
	struct Customers *link_to_cus;

};

struct Rooms *root_read_rom = NULL;
void read_rooms();
void read_customer();
void print_list();
void print_Customer();
void add_room_to_end();
void add_after_room_number();
void link_customer_to_room();
void add_customer_to_end();
void remove_room();
void show_vacancy();
void get_by_floor();
int room_length();

int main(){
	
	int choise,len;
	/*i have used the structure definations globally so that i could access it in all the functions which we gana use them down.*/
		
	read_rooms();//functions call.
	read_customer();
	
	struct Rooms *temp;
	temp = root_read_rom;
	
	while(temp->r_link!=NULL){//intilaizing the all custoerms portion of the rooms to null.

		temp->link_to_cus =  NULL;
		temp = temp->r_link;
	}

	print_list();

	do{//this is the menu in which you can perform all the operations that has been desired .
		
		printf("_____________________________\n");
		printf("**HOTEL RECEPTION MANAGMENT**\n");
		
		printf(" 1:add_room_to_end\n");
		printf(" 2:add_after_room_number\n");
		printf(" 3:remove_room\n");
		printf(" 4:show_vacancy\n");
		printf(" 5:get_by_floor\n");
		printf(" 6:add_customer_to_end\n");
		printf(" 7:link_customer_to_room\n");
		printf(" 8:rooms quantity\n");
		printf(" 0:exit\n");
		
		printf(" your choise:");
		scanf("%d",&choise);
	
		switch(choise){

			case 1: add_room_to_end();
			break;

			case 2: add_after_room_number();
			break;

			case 3: remove_room();
			break;

			case 4: show_vacancy();
			break;

			case 5: get_by_floor();
			break;

			case 6: add_customer_to_end();
			break;

			case 7: link_customer_to_room();
			break;

			case 8:  len = room_length();
			
			printf("the quantity of existing rooms are : %d\n",len);
			break;
			
			case 0: 
			printf(" closing the program...\n");
			break;

			default :
			printf("invalid selection!!!\n");
		}

	}while(choise!=0);
	
	/*in partecular if you want you can test the functions seperatly down by opening them...*/
	//add_room_to_end();
	//add_after_room_number();
	//remove_room();
	//add_customer_to_end();
	//show_vacancy();
	//link_customer_to_room();
	//print_Customer();
	//get_by_floor();
	//print_list();
	return 0;
}//end of main funtion.
void add_customer_to_end(){//functions add the customer to the end of the list and them updates the list 

	struct Customers* temp;
	struct Customers *test;
	test  = root_read_cus;
	int i = 1,len = 0,condition;
    temp = (struct Customers*)malloc(sizeof(struct Customers));//creat the node.
 	
 	printf("Enter new Customers Roon number:");
 	scanf("%d",&temp->cus_room_num);
 	
 	printf("Enter customers name :\n");
 	scanf("%s",temp->cus_name);
 	
 	printf("Enter Customers sure_name :");
 	scanf("%s",temp->cus_sure);

 	printf("Enter Customers age:");
 	scanf("%d",&temp->cus_age);
   
   	printf("Enter Customers gender:");
	scanf("%s",temp->cus_gender);
	
	temp->cus_next = NULL;
   
    if(root_read_cus == NULL){

        root_read_cus = temp;
    }
    else{

        struct Customers* test;
        test = root_read_cus;

        while(test->cus_next!= NULL){

             test = test->cus_next;
        }
        test->cus_next = temp;
    }
    print_Customer();
}
void read_rooms(){//functions reads the all datas respectivly from the rooms.txt file and stores them into  a linked list callad Rooms .

	struct Rooms *temp;
    struct Rooms *test;
	FILE *input;
	char junk_array[BUFFER];
	char *rmnumber;
	char *flor;
	char *capa;

	input = fopen("rooms.txt","r");
	
	if (input == NULL)
		printf("coudn't read properly!! make sure you read correctlly!!\n");
	
	else{
				
		while(fgets(junk_array,BUFFER,input)){//reading line by line 

			temp  = (struct Rooms*)malloc(sizeof(struct Rooms));//memory allocation for each node in linked list

			rmnumber = strtok(junk_array,",");//
			temp->room_num  =atoi(rmnumber);
		
			flor = strtok(NULL,",");
			temp->floor  = atoi(flor);

			capa  = strtok(NULL,",");
			temp->capacity  = atoi(capa);
		
		    temp->r_link = NULL;
					   			   
		    if(root_read_rom == NULL){

		        root_read_rom = temp;
		    }
		   	else{

		        test = root_read_rom;
	        	while(test->r_link!= NULL){

	             test = test->r_link;
	         	}

	        	test->r_link = temp;      
			}
			//printf("%d %d %d\n",temp->room_num,temp->floor,temp->capacity);	
		}
	}
	fclose(input);
}
void get_by_floor(){//function which gets  a number from the use and according to that lists the floors in linked list rooms

	struct Rooms *temp;
	temp = root_read_rom;	
	int counter= 0;
	int floornumber;
	printf("\nEnter the floor number:");
	scanf("%d",&floornumber);

	
	while(temp!=NULL){

		if (temp->floor == floornumber){
          
			printf("Room %d (Floor %d-capacity %dx):",temp->room_num,temp->floor,temp->capacity);
			printf("\n");
			counter++;
		}
		temp = temp->r_link;
	}

	if (counter== 0){
		printf("There is no such a Floor in the List !!!\n");
	}
	free(temp);
}
void show_vacancy(){

	struct Rooms *temp;
	temp = root_read_rom;	

	printf("\n**** Available Empty Rooms Are ****\n\n");
	
	while(temp!=NULL){

		if (temp->link_to_cus == NULL)
			printf("Room %d (Floor %d-Capacity %dx):\n",temp->room_num,temp->floor,temp->capacity);
		temp = temp->r_link;
	}

}
void read_customer(){//functions reads the Customer from the customers.txt file and stores them into customer linked list to be used

	int i = 0;
	char junk_array[BUFFER];
	char *cu_roomnum;
	char *cu_name_sur;
	char *cu_age;
	
	FILE *input;
	struct Customers *temp;
	
	input = fopen("customers.txt","r");
	
	if (input == NULL)
		printf("coudn't read properly!! make sure you read correctlly!!\n");
	
	else{

		while(fgets(junk_array,BUFFER,input)!=NULL){//reads line by line from the file
			
			temp  = (struct Customers*)malloc(sizeof(struct Customers));
			
			cu_roomnum  = strtok(junk_array," ,\n");//using strtom to get the customer room number form the file 
			temp->cus_room_num  = atoi(cu_roomnum);	
			
			sprintf(temp->cus_name,"%s",strtok(NULL," ,\n"));

			sprintf(temp->cus_sure,"%s",strtok(NULL," ,\n"));

			cu_age  = strtok(NULL,",\n");//get  customers age from the file 
			temp->cus_age  =atoi(cu_age);
			
			sprintf(temp->cus_gender,"%s",strtok(NULL," ,\n"));
			
			temp->cus_next = NULL;

			if (root_read_cus == NULL){//if root is null so store store the data there
				
				root_read_cus = temp;
			}

			else{//else creat another poninter an trace the list 

		        struct Customers* test;

		        test = root_read_cus;
	        	while(test->cus_next!= NULL){

	             test = test->cus_next;
	         	}
	        	test->cus_next = temp;
			}
			//printf("%d %s %d %s\n",temp->cus_room_num,temp->cus_name,temp->cus_age,temp->cus_gender);
		}
	}
	fclose(input);
}
void print_Customer(void){//functions prints the customer linked list.

	struct Customers *temp;
   
	temp = root_read_cus;
  	
  	if (temp == NULL)
        printf("the list is empty !!\n");
   	
   	else{
    
    	while(temp!=NULL){
           
			printf("room:%d name:%s sure_name :%s age:%d gender:%s",temp->cus_room_num,temp->cus_name,temp->cus_sure,temp->cus_age,temp->cus_gender);
            temp = temp->cus_next;
            printf("\n");
		}
   	}

}
void add_after_room_number(){//functions adds a node after disered node locations.

 	struct Rooms* temp,*test;
    int i = 1,location;

    printf("Enter the location where you want to add the room: ");
    scanf("%d",&location);

    if (location > room_length()){//if locations is bigger than the lenght so give error and add a node at the end and go back to menu.

    	printf("num is larger than the room_length of the list !!! calling add_room_to_end function >>> \n");
    	add_room_to_end();//fucnitons call.
    	return;
    }
    else{//if the location is excit in the list to perform the below else block...

        test = root_read_rom;

        while(i < location){//find the locations whrere the node to be added

            test = test->r_link;
            i++;
        }
        
        temp = (struct Rooms*)malloc(sizeof(struct Rooms));//creat a node.

    	printf("Enter new room number:");
	 	scanf("%d",&temp->room_num);
	 	
	 	printf("Enter floor number:");
	 	scanf("%d",&temp->floor);

	 	printf("Enter capacity number:");
	 	scanf("%d",&temp->capacity);
       
        temp->r_link = NULL;//null the link of the newly created node.
        temp->r_link = test->r_link;
        test->r_link = temp;

    }
    print_list();//print the updated list.
}
void add_room_to_end(void){//function adds the romm at the end 

	struct Rooms* temp;
	struct Rooms *test;
	test  = root_read_rom;
	int i = 1,len = 0,condition;
    temp = (struct Rooms*)malloc(sizeof(struct Rooms));//creat the node.

    len = room_length();//the lenght of the current list.
 	
 	printf("Enter new room number:");
 	scanf("%d",&temp->room_num);
 	
 	printf("Enter floor number:");
 	scanf("%d",&temp->floor);

 	printf("Enter capacity number:");
 	scanf("%d",&temp->capacity);
   
	temp->r_link = NULL;
   
    if(root_read_rom == NULL)
        root_read_rom = temp;
    
    else{

        struct Rooms* test=root_read_rom;
        while(test->r_link!= NULL){
             test = test->r_link;

        }
        test->r_link = temp;
    }
    print_list();
}
void remove_room(){//fucntions deletes or removes the desired room in the list
   
    struct Rooms* temp;
    int location=0,len;

    printf("Enter the room location to be deleted >>\n");
    scanf("%d",&location);
    len = room_length();
   
    if (location >len){//check the location
   
        printf("invalid location !!! \n");
        printf("your choise must be smaller that %d !!!\n",len );
    }
    else if (location == 1){//if the location is the fisrt node.
    
        temp = root_read_rom;//copy the root node to temp to perform oparations bellow.
        
        root_read_rom = temp->r_link;
        
        temp->r_link == NULL;
        printf("rest rooms' list after removing the first room >>> \n\n");
   		print_list();
        
        free(temp);
    }
    else{

    	int i = 1;
    	struct Rooms* test = root_read_rom,*test1;

        while(i < location-1){
        
            test = test->r_link;
            i++;
        }

        test1 = test->r_link;        
        test->r_link = test1->r_link;
        test1->r_link = NULL;
     
        free(test1);
     
      	printf("rooms list after removing the desired room >>> \n\n");
 	  	print_list();
	}
}
void print_list(){//print list func prints the updated list every after operation.

	struct Rooms *temp;
   	struct Customers *capasi;
	
	temp = root_read_rom;
	capasi = root_read_cus;
   
    if (temp == NULL)
        printf("the list is empty !!\n");
    
    else{
      
      while(temp!=NULL){

            printf("Room %d (Floor %d-capacity %dx):\n",temp->room_num,temp->floor,temp->capacity);
           	/*while(temp->link_to_cus!= NULL){
            	
            	printf("-> %s %s (%d-%s)\n",temp->link_to_cus->cus_name,temp->link_to_cus->cus_sure,temp->link_to_cus->cus_age,temp->link_to_cus->cus_gender);
            	temp->link_to_cus= temp->link_to_cus->cus_next;
            }*/
            
            temp = temp->r_link;
       }
    }

}
int room_length(){//functions findes the lenght of the current room and returns the lenght of the list to be used 

    int counter = 0;
    struct Rooms* temp;

     temp =root_read_rom;
  
     if (temp == NULL)
        printf("list is empty!!!\n");
     
     else{

        while(temp!=NULL){

            temp = temp->r_link;
            counter++;
        }
     }
     return(counter);
}
void link_customer_to_room(){

	struct Rooms *temp1;
	struct Customers *temp2;
	
	temp1 = root_read_rom;
	temp2 = root_read_cus;

	while(temp1!=NULL){//traversing the whole rooms

		if(temp1->capacity!= 0){//if there is empty place in rooms

			struct Customers *test;

			while(temp2!= NULL){//traversing the whole customers.
				
				if(temp1->room_num == temp2->cus_room_num){//if the customers room number and the rooms room number matches then execute the if block.
				
					test = (struct Customers*)malloc(sizeof(struct Customers));			
					test = temp2;					
					
					test = test->cus_next;
					test->cus_next = NULL;
				}
				temp2 = temp2->cus_next;
		    }
			temp1->link_to_cus = test;
		}
	temp1 = temp1->r_link;
	}
}