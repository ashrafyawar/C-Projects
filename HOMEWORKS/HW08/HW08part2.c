#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* find_operations(int arr[], int expected_val, char operations[], size_t arr_len, int cursor, int current);
int mypow(int degree);
char **generateOperators(int arr_len);
void printOperators(char** probabilityOrder, int arr_len);

typedef enum {TRUE,FALSE} bool;//enumarated type to check false andd true conditions.

int main(){

    int arr[] = {25,12,6,10,32,8};//you can expand and deacrise the elements of the array to test.
    int expected_val = 44;//the resultant to the array elements after applying some operations on them.
    size_t arr_len = 6;//you can increase and dicreease the size of the array  according to the size of the arr[].
    int r,j;
    char **probabilityOrder;//char array to find the probability oparators used .
    bool found = FALSE;//enum type variable.

    r = mypow(arr_len-1);//calling the function.

    probabilityOrder = generateOperators(arr_len);
    //printOperators(probabilityOrder,arr_len);//this functions prints all the probably operator if you will you can take is out of the cumment mode and try it .

    for (j = 0; j < r; ++j){

        if( 0 > strcmp(find_operations(arr,expected_val,probabilityOrder[j],arr_len,0,0),"0")){//matching the opeartor to find the exact one.
        
            printf("%s\n", probabilityOrder[j]);//if it is true them print the matched one 
            found = TRUE;
            break;
        }
    }

    if (found  == FALSE){//condition to check whether the desired operator can be fount according to the given arra of not if it is not so print the message in side the if statment 
    
        printf("\nThere are  no any operations for number that you selected as array!\n");
    }
    return 0;
}

void printOperators(char** probabilityOrder, int arr_len){//function prints the operator if it is found.

    int r,c;
    r = mypow(arr_len-1);

    for (int m = 0; m < r; ++m) {
        printf("%s\n", probabilityOrder[m]);
    }
}

char **generateOperators(int arr_len){//function generates operators.

    int i,k, l=1, t =3, m,q=1, step;
    int r,c;
    char **probabilityOrder;

    r = mypow(arr_len-1);//calling function mypow.
    c = arr_len-1;

    probabilityOrder = (char **)malloc(r * sizeof(char *));//functions to allocate dynamicly memory .
    for (i=0; i<r; i++)
        probabilityOrder[i] = (char *)malloc(c * sizeof(char));//allocating size in memory for a char type array 

    for (int j = 0; j <= arr_len -2; ++j){
       
        step = mypow(arr_len - 2);
        for (k = 0; k < step*3; k  += t) {
       
            for (m = 0; m < l; ++m) {
                probabilityOrder[k+m][j] = '*';
            }
       
            for (m = 0; m < l; ++m) {
                probabilityOrder[k+m+q][j] = '-';
            }
       
            for (m = 0; m < l; ++m) {
                probabilityOrder[k+m+(2*q)][j] = '+';
            }
        }
        t *= 3;
        l *= 3;
        q *= 3;
    }

    for (m = 0; m < r; ++m){
            probabilityOrder[m][c] = '\0';
    }
    return probabilityOrder;
}

int mypow(int degree){
    
    int num = 1,m;
    
    for (m = 0; m <= degree-1; ++m) {
        num = num * 3;
    }
    
    return num;
}

char* find_operations(int arr[], int expected_val, char operations[], size_t arr_len, int cursor, int current){//function to find the operator recurisively.

    char * found;

    if (arr_len <= 0){// condition to print error  if the size of the list is not suffecient.
        printf("The size of list of numbers less than zero");
        return "0";
    }

    if (strlen(operations) < arr_len - 1 || strlen(operations) > arr_len - 1){
        printf("The size of list of operators are not n-1");
        return "0";
    }

    if (current == expected_val){

        found = (char *)malloc(sizeof(char)*(arr_len-1));//allocating memory to char type.
        sprintf(found,"%s",operations);
        return found;
    }

    if (cursor == arr_len) {
        return "0";
    }

    if (cursor == 0){
    
        current = arr[0];
    }
    else{
    
        switch (operations[cursor-1]){//switch used to find the exact operator .
            case '+':
                current = current + arr[cursor];
                break;
            case '-':
                current = current - arr[cursor];
                break;
            case '*':
                current = current * arr[cursor];
                break;
            default:
                printf("Unknown operator!");
        }
    }
    return find_operations(arr,expected_val,operations,arr_len,cursor+1,current);//calling the function it self recoursivly.
}