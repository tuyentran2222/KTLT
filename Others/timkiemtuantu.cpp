#include<stdio.h>
#define MAX 20
int intArray[MAX]={1,2,3,4,6,7,9,11,12,14,15,16,17,19,33,34,43,45,55,66};
void printArrray(int count){
	
}

int find(int data){
	int comparisons =0;
	int index=-1;
	int i;
	
	for(i=0;i<MAX;i++){
		comparisons++;
		
		if (data == intArray[i]){
			index=i;
			break;
		}
	}
	printf("Tong so so sanh thuc hien la : %d \n", comparisons);
	return index;
	
}
void display(){
	int i;
	printf("[");
	
	for (i=0;i<MAX-1;i++){
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
	int location= find(55);
	int l1= find(98);
	if (location== -1){
		printf("So khong co trong day.\n ");
		
	}else{
		printf("Vi tri cua so trong day la : %d \n",location+1);
	}
	if (l1== -1){
		printf("So 98 khong co trong day.\n ");
		
	}else{
		printf("Vi tri cua so 98 trong day la : %d \n",l1+1);
	}
	return 1;
}
