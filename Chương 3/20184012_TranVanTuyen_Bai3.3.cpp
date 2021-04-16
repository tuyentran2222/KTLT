#include <bits/stdc++.h>
using namespace std;
#define MAX 100  
int finish=0;
int n, c[MAX][MAX]; //# so th�nh pho v� ma tran chi ph�
int cmin = INT_MAX; //# chi ph� di lai nho nhat giua hai th�nh pho kh�c nhau
int best = INT_MAX; //# tong chi ph� nho nhat can t�m, ban dau dat bang gi� tri v� c�ng l?n INT_MAX = 2^31-1
int curr; //# tong chi ph� toi thoi diem hien tai
int mark[MAX]; //# d�nh dau nhung th�nh pho d� di
int x[MAX]; //# luu giu c�c th�nh pho d� di

//# doc dl dau vao
void input(){
    cin >> n;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j){
            cin >> c[i][j];
            if (c[i][j] > 0) cmin = min(cmin, c[i][j]);
        
        }
}

//# Thuat to�n quay lui
void TRY(int k){
    for(int i = 2; i <= n; i++){
        if((mark[i]==0) ){
        	mark[i]=1;
        	x[k]=i;
        	curr=curr+c[x[k-1]][i];	
        	if (k==n) {
        		if ((curr+c[x[k]][1])<best) best=curr+c[x[k]][1];
			}
        	else{
        		if((curr+(n-k+1)*cmin)<best)
        			TRY(k+1);
				} 
				curr=curr-c[x[k-1]][x[k]];
				mark[x[k]]=0;
			}
		}
	
    }


int main() {
	cout<<"Ho va ten:Tran Van Tuyen"<<endl;
	cout<<"MSSV:20184012";
    input();
    x[1] = 1;
    TRY(2);
    cout << best;
    return 0;
}
