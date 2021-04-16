#include<stdio.h>

double* maximum(double *a,int size){
	double *max=a;
	if (a==NULL) return NULL;
	int i;
	for (i=0;i<size;i++){
		if (*max< *(a+i)){
			max= a+i;
		}
	}
	return max;
}
int main(){
		//dau vao lay mot manh co san
		double a[]= {13, -355, 235, 47, 6805, 94, 1222};
		printf("Ho Va Ten: Tran Van Tuyen\n"); 
   		printf("MSSV: 20184012\n\n");
		double *max1= maximum(a,7);
		printf("%lf",*max1);
}
