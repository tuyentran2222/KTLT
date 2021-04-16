#include<stdio.h>
// tim kiem noi suy la bien the cua binary search ,du lieu phai sap xep va phan bo deu
#define MAX 10
int intArray1[20]={1,2,3,4,6,7,9,11,12,14,15,16,17,19,33,34,43,45,55,66};
int intArray[MAX] = { 10, 14, 19, 26, 27, 31, 33, 35, 42, 44 };
// tim kiem noi suy
int find(int data){
	int low =0;
	int high=MAX-1;
	int mid=-1;
	int comparisons=1;
	int index=-1;
	
	while (low<= high){
		printf ("\n Comparisons %d \n",comparisons);
		printf("low  : %d ,intArray[%d] = %d \n",low,intArray[low]);
		printf("high : %d ,intArray[%d] = %d \n",low,intArray[high]);
		
		comparisons ++;
		 mid = low + (((double)(high - low) / (intArray[high] - intArray[low])) * (data - intArray[low]));

		printf("mid= %d \n",mid);
		
		if (intArray[mid]==data){
			index=mid;
			break;
		}
		else{
			if  (intArray[mid]<data){
				low=mid+1;
			}
			else{
				high=mid-1;
			}
		}
		
	}
	printf("Total comparisons made : %d", --comparisons);
	return index;
}
int main(){ 

	// find location of 15
	int location = find(26);
	
	// if element was found
	if(location != -1)
      printf("\nElement found at location: %d" ,(location+1));
    else
      printf("Element not found.");
	return 1;
}
