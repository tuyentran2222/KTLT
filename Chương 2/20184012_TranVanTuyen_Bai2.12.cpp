#include<stdio.h>
#include<iostream>
#include<string>
#include <bits/stdc++.h>  


using namespace std;

struct ds{
	int key;
	int value;
};

void merge(ds *a,int l ,int m,int r){
	int i,j,k=l;
	int n1=m-l+1;
	int n2=r-m;
	ds L1[n1],L2[n2];
	
	for (i=0;i<n1;i++){
		L1[i].key=a[l+i].key;
		L1[i].value=a[l+i].value;
	
	}
	for (j=0;j<n2;j++){
		L2[j].key=a[m+1+j].key;
		L2[j].value=a[m+1+j].value;
	}
	i=0;
	j=0;
	k=l;
	while ((i<n1)&&(j<n2)){
	
		if (L1[i].value<L2[j].value){
			a[k].value=L2[j].value;
			a[k].key=L2[j].key;
			k++;j++;
		}
		else if (L1[i].value==L2[j].value){
			if (L1[i].key>L2[j].key){
				a[k].value=L1[i].value;
				a[k].key=L1[i].key;
				k++;
				i++;
			}
			else {
				a[k].value=L2[j].value;
				a[k].key=L2[j].key;
				k++;
				j++;
			}
		
		}
		else {
			a[k].value=L1[i].value;
			a[k].key=L1[i].key;
			k++;i++;
		}
		
	}

	while (i < n1)
    {	
    	a[k].key=L1[i].key;
		a[k].value=L1[i].value;
		k++;
        i++;
    }
	while (j < n2)
    {
    	a[k].key=L2[j].key;
		a[k].value=L2[j].value;
		
		k++;
        j++;
    }
	    
	
}
void mergeSort(ds *a,int l,int r){
	if(l<r){
		int mid=(l+r)/2;
		mergeSort(a,l,mid);
		mergeSort(a,mid+1,r);
		merge(a,l,mid,r);
	}
	
}
void print(ds *a,int n){
	for (int i=0;i<n;i++){
		cout<< a[i].key<<" "<<a[i].value<<endl;
	}
}

int main(){
	
	ds *a=new ds[1000];
	int i=0;
	while (cin>>a[i].key >>a[i].value)
	{
	i++;
	}
	
	mergeSort(a,0,i-1);
	print(a,i);
	return 1;
}
