#include<stdio.h>

int main(){
	int x,y,z;
	int *ptr;
	printf("Ho Va Ten: Tran Van Tuyen\n"); 
   	printf("MSSV: 20184012\n\n");
	printf("Enter three integers: ");
	scanf("%d%d%d",&x,&y,&z);
	printf("The three integers are:\n");
	ptr=&x;
	printf("x = %d\n",*ptr);
	ptr=&y;
	printf("y = %d\n",*ptr);
	ptr=&z;
	printf("z = %d\n",*ptr);
	return 1;
}
