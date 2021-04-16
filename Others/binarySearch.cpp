#include<stdio.h>
#define MAX 20;
int intArray[20]={1,2,3,4,6,7,9,11,12,14,15,16,17,19,33,34,43,45,55,66};
int binarySearch(int data){
	int mid=0;
	int low=0;
	int high=MAX-1;
	int dem=0;
	int index=-1;
	while(low<= high){
		mid= int(low + (high-low)/2);
		if ( intArray[mid]== data){
			dem++;
		    index= mid;
		    break;
		}
		else if ( intArray[mid]< data){
			dem++;
			low= mid+1;
		}
		else{
			dem++;
			high=mid-1;
		}
	}
   return index;	
}
void display(){
	int i=0;
	printf("[");
	
	for(int i=0;i< 19;i++) {
		printf("%d",intArray[i]);
		printf(",");
	}
	printf("%d",intArray[19]);
	printf("] \n");
}
int main(){
	printf("Danh sach dau vao :");
	display();
	printf("\n");
	int location= binarySearch(16);
	if (location== -1){
		printf("So khong co trong day.\n ");
		
	}else{
		printf("Vi tri cua so trong day la : %d \n",location+1);
   }
   return 1;
}

