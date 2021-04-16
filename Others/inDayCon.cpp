#include<stdio.h>

void inDayCon(int *a,int n){
	int i=0;
	int j,k;
	for (i=0;i<n;i++){
		j=i;
		while(j!=n){
			j++;
			for (k=i;k<j;k++){
				printf("%d ",*(a+k));
			}
			printf("\n");
			
		}
	}
}

int main(){
	printf("Ho Va Ten: Tran Van Tuyen\n"); 
   	printf("MSSV: 20184012\n\n");
	int n;
	scanf("%d",&n);
	int i;
	int A[n];
	for (i=0;i<n;i++){
		scanf("%d",&A[i]);
	}
	inDayCon(A,n);
	return 1;
}
