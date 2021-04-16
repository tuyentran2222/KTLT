#include <bits/stdc++.h>
using namespace std;

struct state{
    int i, old_L;string j;
    //# constructor
    state(int _i = 0, string _j = "0", int _L = 0):
        i(_i), j(_j), old_L(_L){}
};
void inDay(int n,int k){
	string x[n+1];
    stack<state> s;
    
    int L = 0;
    s.push(state(1, "0"));
    while (!s.empty()){
        state &top = s.top();
       
        if (top.i > n){
        	if(top.old_L==k){
        		string c="";
        		for (int i = 1; i <= n; ++i){
        			c.append(x[i]);
				}
				cout << c<<endl;
                
			}

            s.pop();
            continue;
        }

        L = top.old_L;
        x[top.i] = top.j;
        s.pop(); 

        if (top.j == "0") {
            if (L < k) {
                s.push(state(top.i, "1", L+1));
            }
            
            s.push(state(top.i+1, "0",L));
        } else {
            s.push(state(top.i+1, "0", L));
        }
    }
}



int main() {
	cout<<"Ho va ten:Tran Van Tuyen"<<endl;
	cout<<"MSSV:20184012";
	int a;
	cin>>a;
	int n, k;
	int m[a];
	int h[a];
	for(int i=0;i<a;i++){
		cin >> m[i] >> h[i];
    	
	}
	for(int i=0;i<a;i++){
		
    	inDay(m[i],h[i]);
    	cout<<endl;
    	
	}
	string c="";
    return 0;
}
