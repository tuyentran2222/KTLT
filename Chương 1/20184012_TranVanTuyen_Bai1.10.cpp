#include<iostream>
#include<stdio.h>
using namespace std;
int** input(int n){
	int** mt;
    mt = new int *[n];
    int *temp = new int[n*n];
    int i;
    for (i=0;i<n*n;i++){
    	scanf("%d",temp+i);
	}
    for (i=0; i< n; ++i) {
        mt[i] = temp;
        temp += n;
    }
    return mt;
    
    
}

void tinhTong(int **mt1,int **mt2,int n){
	int i,j;
	int** mt3;
    mt3 = new int *[n];
    int *temp = new int[n*n];

    for (i=0;i<n*n;i++){
    	*(temp+i)=0;
	}
    for (i=0; i< n; ++i) {
        mt3[i] = temp;
        temp += n;
    }

	for ( i=0;i<n;i++){
		for (j=0;j<n;j++){
		     *(*(mt3+i)+j) =*(*(mt1+i)+j) +*(*(mt2+i)+j);
		     printf("%d ",*(*(mt3+i)+j));
		     if (j==n-1) printf("\n");
		}
	}
	delete [] mt3[0];
    delete [] mt3;
	
}
void tinhTich(int **mt1,int **mt2,int n){
	int i,j,k;
	int** mt3;
    mt3 = new int *[n];
    int *temp = new int[n*n];

    for (i=0;i<n*n;i++){
    	*(temp+i)=0;
	}
    for (i=0; i< n; ++i) {
        mt3[i] = temp;
        temp += n;
    }

	for ( i=0;i<n;i++){
		for (j=0;j<n;j++){
			for(k=0;k<n;k++){
		       *(*(mt3+i)+j)=*(*(mt3+i)+j) + *(*(mt1+i)+k) * *(*(mt2+k)+j);
		    }
		    printf("%d ",*(*(mt3+i)+j));
		    if (j==n-1) printf("\n");   
		}
		    
	}
	
}
int main(){
	int n;
	printf("Ho Va Ten: Tran Van Tuyen\n"); 
   	printf("MSSV: 20184012\n\n");
	    
	scanf("%d",&n);
	int **mt1,**mt2;
	mt1=input(n);
	mt2=input(n);
	printf("Tong hai ma tran\n");
	tinhTong(mt1,mt2,n);
	printf("Tich hai ma tran\n");
	tinhTich(mt1,mt2,n);
	delete [] mt1[0];
    delete [] mt1;
    delete [] mt2[0];
    delete [] mt2;
	return 1;
	
}


