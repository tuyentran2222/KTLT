#include<stdio.h>
#include<iostream>
using namespace std;
void reversearray(int arr[],int size){
	int i=0;
	int tmp;
	int a[size];
	for (i=0;i<size;i++){
	 	a[i]=arr[size-i-1];
	}
	for (i=0;i<size;i++){
	 	arr[i]=a[i];
	}
}
void ptr_reversearray(int *arr,int size){
	int i=0;
	int* a= new int[size];
	for (i=0;i<size;i++){
		*(a+i)=*(arr+size-i-1);
	}
	for (i=0;i<size;i++){
		*(arr+i)=*(a+i);
	}
}

int main(){
	int arr[] = {9, 3, 5, 6, 2, 5};
	printf("Ho Va Ten: Tran Van Tuyen\n"); 
   	printf("MSSV: 20184012\n\n");
	reversearray(arr, 6);
	for(int i = 0; i < 6; i++) cout << arr[i] << " ";
	int arr2[] = {4, -1, 5, 9};
	ptr_reversearray(arr2, 4);
	for(int i = 0; i < 4; i++) cout << arr2[i] << " ";
	return 1;
}
