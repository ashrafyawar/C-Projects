#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int count_of_vowels(const char *text,char *vowels,int vowels_count);
int max_of_array(const int *arr,int arr_size,int sonuc);
int lcm(int number1,int number2,int largest);

int main(){
	
	char *array="This is example.Try to get numbers of vowels that are in the sentence..";
	char vowels[5]={'a','e','o','i','u'};
	int a,max,x,y,final;
	int arra[11]={10,13,14,15,140,12,10000,14,12,25,-1};
	
	a = count_of_vowels(array,vowels,0);
	printf(">>number of vowels are %d\n",a);
	
	printf("\n");

	max = max_of_array(arra,10,0);
	printf(">>the max number is %d\n",max);
	printf("\n");
	
	printf(">>enter two numbers to calculate thires LCM\n");
	scanf("%d%d",&x,&y);
	
	if (x > y)
		final=lcm(x,y,x);
	else
		final=lcm(x,y,y);

	printf("the LCM of the %d and %d is %d\n",x,y,final);
	return 0;
}
int count_of_vowels(const char *text,char *vowels,int vowels_count){

	if (*text=='\0')
		return vowels_count;		

	else if (*text=='a'||*text=='i'||*text=='o'||*text=='u'||*text=='e'||*text=='A'||*text=='I'||*text=='O'||*text=='U'||*text=='E'){

		vowels_count++;
		vowels_count = count_of_vowels(text+1,vowels,vowels_count);
	}
	else
		vowels_count=count_of_vowels(text+1,vowels,vowels_count);
	return vowels_count;
}
int max_of_array(const int *arr,int arr_size,int sonuc){

	int max_num,counter = 0,result ;
	
	result = sonuc;
    max_num = result;	
	
	
	if (arr[0]==-1)
		return result;
	
	else if (arr[1] > max_num){

		max_num = arr[1];
		result = max_of_array(arr+1,arr_size,max_num);
	}
	else{
		result = max_of_array(arr+1,arr_size,max_num);
	}
	return result;
}

int lcm(int number1,int number2,int largest){
	
	static int common=1;
	if (common %number1==0&&common%number1==0){
		return common;
}
	common++;
	lcm(number1,number2,common);
	return common;
}

int lcm(int a, int b){

    static int common = 1;
    if (common % a == 0 && common % b == 0)
        return common;
    common++;
    lcm(a, b);
    return common;

}
