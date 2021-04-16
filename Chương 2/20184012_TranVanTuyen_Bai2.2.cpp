
#include <stdio.h>

void rotate(int &x, int &y, int &z) {
    int temp;
    temp=x;
    x=y;
    y=z;
    z=temp;
}

int main() {
    int x, y, z;
    printf("Ho Va Ten: Tran Van Tuyen\n"); 
   	printf("MSSV: 20184012\n\n");
    //# Nhap 3 so nguyên
    scanf("%d %d %d",&x,&y,&z);
    
    printf("Before: %d, %d, %d\n", x, y, z);
    rotate(x, y, z);
    printf("After: %d, %d, %d\n", x, y, z);
    
    return 0;
}
