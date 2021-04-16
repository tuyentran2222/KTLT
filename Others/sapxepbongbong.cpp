//sap xep bong bong so sánh  phan tu lien ke  thoi gian la o(n*n)
#include<stdio.h>
#define MAX 10

int list[MAX] = {1,8,4,6,0,3,5,2,7,9};

void display() {
   int i;
   printf("[");


   // navigate through all items 
   for(i = 0; i < MAX; i++) {
      printf("%d ",list[i]);
   }

   printf("]\n");
}

void bubbleSort(){
	int i,j;
	int temp;
	for (i=0;i<MAX-1;i++){
	
		for (j=0;j<MAX-i-1;j++){
			if (list[j]> list[j+1]){
				temp = list[j];
                list[j] = list[j+1];
                list[j+1] = temp;
			} 
		}
    }
}
int main(){
	display();
	bubbleSort();
	display();
	
	return 1;
}

