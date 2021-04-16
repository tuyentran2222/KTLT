#include<stdio.h>

int countEven(int *arr,int size){
	int count=0;
	int i=0;
	for (i=0;i<size;i++){
		if ((*(arr+i))%2==0){
			count++;
		}
	}
	return count;
}

int main(){
	int arr[]= {1,5,4,8,10,6,7,2}; 
	int count1=0;
	printf("Ho Va Ten: Tran Van Tuyen\n"); 
   	printf("MSSV: 20184012\n\n");
	count1= countEven(arr,8);
	printf("%d",count1);
	return 0;
}


