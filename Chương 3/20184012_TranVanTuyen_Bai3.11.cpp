#include <bits/stdc++.h>
#include <cstring>
using namespace std;
#define MAX 100  
int n, c[MAX][MAX]; //# so th�nh pho v� ma tran chi ph�
int cmin = INT_MAX; //# chi ph� di lai nho nhat giua hai th�nh pho kh�c nhau
int best = INT_MAX; //# tong chi ph� nho nhat can t�m, ban dau dat bang gi� tri v� c�ng l?n INT_MAX = 2^31-1
int curr; //# tong chi ph� toi thoi diem hien tai
int mark[MAX]; //# d�nh dau nhung th�nh pho d� di
int x[MAX]; //# luu giu c�c th�nh pho d� di
int a[5000];
int r,j,m;
int f[MAX];

void input(){
	string l;
	string segment;
    cin >> n>> r;
	getline(cin,l);
    for (int i=1;i<=n;i++){
    	m=1;
    	getline(cin, l);
		stringstream test(l);
		while(getline(test, segment, ' '))
		{
		   int x=atoi(segment.c_str());
		   c[i][m]= x;
		   m++; 
		}
	}
}
void cmin1(){
	for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j){
            if (c[i][j] > 0 &&mark[i]==0 &&mark[j]==0) cmin = min(cmin, c[i][j]);
        }
}

void TRY(int k,int z,int m){

    for(int i = 1; i <= z; i++){
        if((mark[a[m+i]]==0)){
        	mark[a[m+i]]=1;
        	x[k]=a[m+i];
        	
        	if (c[x[k-1]][x[k]]!=0){
        		curr=curr+c[x[k-1]][x[k]];	
			}
			else {continue;mark[x[k]]=0;}
        	if (k==z-1) {
        		//cout<<"x3="<<x[3];
        		//cout<<"kc="<<c[x[k]][x[3]];
        		if ((curr+c[x[k]][x[z]])<best&&c[x[k]][x[z]]) best=curr+c[x[k]][x[z]];
			}
        	else{
        		if((curr+(n-k+1)*cmin)<best)
        			TRY(k+1,z,m);
				}
				curr=curr-c[x[k-1]][x[k]];
				mark[x[k]]=0;
			}
		}
    }

int main() {
	
    input();
    cmin1();
	string l;
	string segment;
  
   	int k1,k2=0;
    for (int i=0;i<r;i++){
		j=0;
    	getline(cin, l);
		stringstream test(l);
		while(getline(test, segment, ' '))
		{
		   int x=atoi(segment.c_str());
		   a[k2]= x;
		   k2++;
		   j++;
		}
	    f[i]=j;
	}
	
	for (int i=0;i<r;i++){
		for (int i1=1;i1<n+1;i1++){
			mark[i1]=1;
		}
		for(int i1=1;i1<=f[i]-2;i1++){
			mark[a[k1+i1]]=0;	
		}
		best=INT_MAX;
    	curr=0;	
		x[1]=a[k1];
		k1=k1+f[i];
		x[f[i]]=a[k1-1];	
		if(f[i]==1) cout<<0<<endl;
		if (f[i]==2) cout<<c[x[1]][x[2]]<<endl;
	    if (f[i]>2) TRY(2,f[i],k1-f[i]);
	    if (best==INT_MAX) cout<<0<<endl;
	    else  cout << best<<endl;
}
    return 0;
}
