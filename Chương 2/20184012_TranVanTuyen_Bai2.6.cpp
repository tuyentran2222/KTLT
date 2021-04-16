#include <stdio.h>

void print(int n) {
    printf("n=%d\n", n);
}

int mul3plus1(int n) {
    return n * 3 + 1;
}

int div2(int n) {
    return n / 2;
}

// khai báo các tham so cho các con tro hàm odd, even và output
void simulate(int n,int (*odd)(int),int (*even)(int),void(*output)(int))  {
    (*output)(n);
    if (n == 1) return;
    if (n % 2 == 0) {
        n = (*even)(n);
    } else {
        n = (*odd)(n);
    }
    simulate(n, odd, even, output);
}

int main() {
	printf("Ho Va Ten: Tran Van Tuyen\n"); 
   	printf("MSSV: 20184012\n\n");
    int (*odd)(int) =mul3plus1;
    int (*even)(int) = div2;
    void (*output)(int)=print;
   
    int n;
    scanf("%d", &n);
    simulate(n, odd, even, print);

    return 0;
}
