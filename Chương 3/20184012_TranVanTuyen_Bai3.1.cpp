#include<stdio.h>
#include<conio.h>
#include<iostream>
using namespace std;
int lucas(int n) {
    if (n==0) return 2;
    else if (n==1) return 1;
    else if (n>=2) return lucas(n-2)+lucas(n-1);
}

int main(){
	cout<<"Ho va ten:Tran Van Tuyen"<<endl;
	cout<<"MSSV:20184012";
	int n;
   	scanf("%d",&n);
   	int result=lucas(n);
   	printf("%d",result);
   	return 1;
}
