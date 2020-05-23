#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int count_of_vowels(const char *text,char *vowels,int vowels_count);
int max_of_array(const int *arr,int arr_size,int sonuc);

int main(){
	
	char *array="This ifEaa example.Try to get numbers of vowels that are in the sentence..";
	char vowels[5]={'a','e','o','i','u'};
	int a,max;
	int arra[11]={10,13,14,15,14,12,30,12,12,25,-1};
	//a = count_of_vowels(array,vowels,0);
	printf("number of vowels are %d\n",a);
	printf("\n");

	max = max_of_array(arra,10,0);
	printf("the max index is %d>>",max);


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
	
	int max_index,counter = 0,result;
	
	result = sonuc;
    max_index = arr[0];	
	
	if (arr[0]==-1)
		return result;
	else if (arr[1] > max_index){

		max_index = arr[1];
		result = max_of_array(arr+1,arr_size,max_index);
	}
	else
		result = max_of_array(arr+1,arr_size,max_index);
	return result;
}
