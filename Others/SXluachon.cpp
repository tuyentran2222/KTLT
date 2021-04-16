#include<stdio.h>
// vi du ve sap xep lua chon
//mang chia thanh hai phan : phan da duoc sap xep va phan chua duoc sap xep
#include <stdbool.h>

#define MAX 7

int intArray[MAX] = {4,6,3,2,1,9,7};

void printline(int count) {
   int i;
	
   for(i = 0;i < count-1;i++) {
      printf("=");
   }
	
   printf("=\n");
}

void display() {
   int i;
   printf("[");
	
   // navigate through all items 
   for(i = 0;i < MAX;i++) {
      printf("%d ", intArray[i]);
   }
	
   printf("]\n");
}

void selectionSort(){
	int indexMin,i,j;
	
	for (i=0;i<MAX-1;i++){
		indexMin=i;
		int min=intArray[i];
		for (j=i+1;j<MAX;j++){
			if(intArray[j]< min){
				indexMin=j;
				min=intArray[j];
			}
		}
		if (indexMin != i){
			printf("Item Swapped : [ %d,%d] \n", intArray[i], intArray[indexMin]);
			int temp=intArray[indexMin];
			intArray[indexMin]=intArray[i];
			intArray[i]=temp;
		}
		
		printf("Iteration %d :",i+1);
		display();
}
}
int main() {
   printf("Input Array: ");
   display();
   printline(50);
   selectionSort();
   printf("Output Array: ");
   display();
   printline(50);
  return 1 ;
}
