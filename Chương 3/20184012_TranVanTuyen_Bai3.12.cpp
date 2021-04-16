#include <bits/stdc++.h>
using namespace std;
 
int a[31][31]; 
 
int n, m, Free[31], u, v, s;
int count;
int t=0;
int k;
int DFS(int u,int count)
{	
    for (int v = 1; v <= n; v++){
    	if (a[u][v] == 1 && Free[v]){
				Free[u] = false;
        		count++;
        		if (count==k||count==n) t++;
        		DFS(v,count);		
        		count--;
				Free[u]=true;
		}
	}
	return t;	         
}
 
int main()
{	cout<<"Ho va ten:Tran Van Tuyen"<<endl;
	cout<<"MSSV:20184012";
	int sum=0;
    cin >> n >> k >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            a[i][j] = 0;
 
    for (int i = 1; i <= m; i++)
    {
        cin >> u >> v;
        a[u][v] = 1;
        a[v][u] = 1;
    }

    for (int i = 1; i <= n; i++)
        Free[i] = 1;
    
    for (int i = 1; i <= n; i++){
    	sum+=DFS(i,0);
    	t=0;
    	
	}
	cout<<sum/2;
    return 0;
}
