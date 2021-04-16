#include <stdio.h>
#define hang 3
#define cot 3
int main() {
   int mt[hang][cot] = {{7,8,9},
              {10,13,15},
                {2,7,8}};
    int i,j;
    for (i=0; i<hang; i++) {
        for (j=0; j<cot; j++)
           printf(" %d ", mt[i][j]);
        printf("\n");
    }
    for (i=0; i<hang; i++) {
        for (j=0; j<cot; j++) {
           *(*(mt+i)+j)=*(*(mt+i)+j) +10;
           printf(" %d ", *(*(mt+i)+j));
        }
        printf("\n");
	}
	printf("%d ",(mt));
	printf("%d ",*(mt));
	printf("%d ",*(mt+1));
	printf("%d ",*(mt+2));
	int x=12;
	int *p1= &x;
	int **p2=&p1;
	printf("%d ",(x));
	printf("%d ",*(p2));
	printf("%d ",**p2);
	return 1;
}
