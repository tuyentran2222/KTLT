#include <stdio.h>

int cube(int x) {
    //# tra ve lap phuong cua x
   return x*x*x;
}

//#viet ham lap phuong cua double
double cube(double x) {
    //# tra ve lap phuong cua x
   return x*x*x;
}

int main() {
	   printf("Ho Va Ten: Tran Van Tuyen\n"); 
   	printf("MSSV: 20184012\n\n");
    int n;
    double f;
    scanf("%d %lf", &n, &f);
    
    printf("Int: %d\n", cube(n));
    printf("Double: %.2lf\n", cube(f));
    
    return 0;
}
