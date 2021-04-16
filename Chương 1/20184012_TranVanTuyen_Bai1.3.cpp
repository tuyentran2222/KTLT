#include <stdio.h>
int main()
{
	printf("Ho Va Ten: Tran Van Tuyen\n"); 
   	printf("MSSV: 20184012\n\n");
	    
    int x, y, z;
    int *p;
    scanf("%d %d %d", &x, &y, &z);
    printf("Here are the values of x, y, and z:\n");
    printf("%d %d %d\n", x, y, z);
    
    p=&x;
    *p=(*p)+100;
     p=&y;
    *p=(*p)+100;
     p=&z;
    *p=(*p)+100;
   
    printf("Once again, here are the values of x, y, and z:\n");
    printf("%d %d %d\n", x, y, z);
    return 0;
}    

