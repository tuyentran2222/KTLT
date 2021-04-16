
#include <stdio.h>
#include<stdlib.h>
void allocate_mem(int ***mt, int m, int n){
	//allocate memory 
    *mt = new int*[m];
    int *tmp = new int[m*n];
    int i;
    for(i=0;i<m;i++){
    	*(*mt+i)=tmp+i*n;
	}
	
}


void input(int **mt, int m, int n){
    //#Input elements of the matrix
    int i,j;
    for(i=0;i<m;i++){
    	for(j=0;j<n;j++){
    		scanf("%d",(*(mt+i)+j));
		}
	}
}

void output(int **mt, int m, int n){
    //# Print all elements of the matrix
    
    int i,j;
    for(i=0;i<m;i++){
    	for(j=0;j<n;j++){
    		printf("mt[%d][%d] = ",i,j);
		}
	}
	for(i=0;i<m;i++){
    	for(j=0;j<n;j++){
    		printf("%d ",*(*(mt+i)+j));
		}
		printf("\n");
	}
   
}

int process(int **mt, int m, int n){
    int tong = 0;
    //# Calculate the sum of all even elements in the matrix
    
    int i,j;
    for(i=0;i<m;i++){
    	for(j=0;j<n;j++){
    		if(*(*(mt+i)+j)%2==0){
    			tong= tong + *(*(mt+i)+j);
			}
		}
	}
    return tong;
}

void free_mem(int **mt, int m, int n){
   delete(*mt);
   delete(mt);
}

int main(){
	printf("Ho Va Ten: Tran Van Tuyen\n"); 
   	printf("MSSV: 20184012\n\n");
    int m, n, **mt;
    printf("Enter m, n = ");
    scanf("%d%d", &m, &n);
    allocate_mem(&mt, m, n);
    input(mt, m, n);
    output(mt, m, n);
    printf("The sum of all even elements is %d", process(mt, m, n));
    free_mem(mt, m, n);
    return 1;
}
