int i,j,temp;
#include<iostream>
using namespace std;
void sort1(int a[],int size){
	for (int i=0;i<size-1;i++)
		for (int j=0;j<size-i;j++){
			temp=a[j];
			a[j]=a[j+1];
			a[j+1]=temp;
		}
}
int main(){
	int arr[]={6,4,8,3,2,1,0},n=7;
	for (int i=0;i<n+2;i++){
		cout<<arr[i]<<" ";
	}
	sort1(arr,n);
	cout<<n<<endl;
	for (int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
	
}
