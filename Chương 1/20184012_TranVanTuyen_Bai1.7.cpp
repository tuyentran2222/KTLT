#include <stdio.h>


int main(){
	printf("Ho Va Ten: Tran Van Tuyen\n"); 
   	printf("MSSV: 20184012\n\n");
	int *a;
    int n, tmp;
    int i;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    a=new int[n];
    for(i = 0; i < n; i++)
        scanf("%d", a + i); 
    
    printf("The input array is: \n");
    for(i = 0; i < n; i++)
        printf("%d ", *(a + i));
    printf("\n");
    
    //#Sort array
     int indexMin,k,j;
    for (k=0;k<(n-1);k++){
    	indexMin=k;
    	int min=*(a+k);
    	for (j=k+1;j<n;j++){
    		if (*(a+j)<min){
    			indexMin=j;
    			min=*(a+j);
			}
			
		}
		if (indexMin!= k){
				int temp;
				temp=*(a+k);
				*(a+k)=*(a+indexMin);
				*(a+indexMin)=temp;
			}
	}
    
    printf("The sorted array is: \n");
    for(int i = 0; i < n; i++)
        printf("%d ", *(a + i));
    printf("\n");
    
    delete [] a;
   
    return 0;
}
