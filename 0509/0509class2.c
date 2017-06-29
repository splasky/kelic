#include <math.h>
#include <stdio.h>

float get_sad(char arr1[],char arr2[],char length);
float get_msq(char arr1[],char arr2[],char length);
char check(char arr1[],char arr2[],char length);

float get_sad(int arr1[],int arr2[],int length){
	double sad=0;
	int i=0;
	if(check(arr1,arr2,length))return 0;
	
	for(i=0;i<length;++i){
		 sad+=abs(arr1[i]-arr2[i]);
	}
	return sad/length;
}

float get_msq(int arr1[],int arr2[],int length){
	double sum=0;
	int i=0;
	if(check(arr1,arr2,length))return 0;
	
	for(i=0;i<length;++i){
		sum+=((arr1[i]-arr2[i])*(arr1[i]-arr2[i]));
	}
	return sqrt(sum)/length;
}

int check(int arr1[],int arr2[],int length){
	if((sizeof(arr1)/sizeof(arr1[0]))!=length)	
		return 1;
	if((sizeof(arr2)/sizeof(arr2[0]))!=length)	
		return 1;
	return 0;
}

int main(void){
	char A[]={56,78,24,61};
	char B[]={55,76,20,60};
	char sad=get_sad(A,B,sizeof(A)/sizeof(A[0]));
	char msq=get_msq(A,B,sizeof(A)/sizeof(A[0]));
	printf("%d\n",sad);
	printf("%d\n",msq);
	return 0;
}