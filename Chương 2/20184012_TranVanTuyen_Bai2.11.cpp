#include<stdio.h>
#include<iostream>
using namespace std;


void nhap(int n,int *a){
	for (int i=0;i<n;i++){
	    cin>>(*(a+i));
	}
}
void tich(int m,int *a,int n,int *b,int *c){
	for (int i=0;i<m;i++){
		int e=0;
		if ((*(a+i))==0) continue;
		else 
			for (int j=0;j<n;j++){
			    if ((*(b+j))==0) continue;
				int e=0;int d=0;
				e=((*(a+i)) ) * ((*(b+j)));
				d=i+j;
				(*(c+d))=(*(c+d))+e;
			}
	}
	
}

int xordathuc(int m,int *c){
	int a=0;
	for (int i=0;i<m;i++){
		a=a^ ((*(c+i)));
	}
    return a;
}
int main(){
	printf("Ho Va Ten: Tran Van Tuyen\n"); 
   	printf("MSSV: 20184012\n\n");
	int m,n;
	cin>>m;
	int * a=new int[m+1];
	nhap(m+1,a);
	cin>>n;
	int* b=new int[n+1];
	nhap(n+1,b);
	int* c=new int[m+n+1];
	for (int i=0;i<=n+m;i++){
		(*(c+i))=0;
	}
	tich(m+1,a,n+1,b,c);
	printf("%d",xordathuc(m+n+1,c));
	
	return 1;
}
