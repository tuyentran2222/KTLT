#include <iostream>
using namespace std;
int n,k1,k2;int x[100];
	void print_sol(){
	for (int i=1;i<n+1;i++){
		cout<<x[i];
	}
	cout<<endl;
}
void TRY(int i, int j, int old_L){
    x[i] = j;
	int L = old_L;
    if (i == n){
    	
    	if((x[n]==0 &&old_L>=k1&&old_L<=k2)){
    		print_sol(); return;
		}
		if((x[n]==1 &&old_L>=k1-1&&old_L<=k2-1)){
    		print_sol(); return;
		}
		else return;
	}
		
    if(x[i]==0){
    	TRY(i+1, 1, 0);
	}
    
    if (x[i]==1) {
    	if (L<k1-1) TRY(i+1,1,L+1);
    	if(L>=k1-1 &&L<k2-1) {
    		TRY(i+1,0,L+1);
    		TRY(i+1,1,L+1);
		}
		if(L>=k2-1) {
			TRY(i+1,0,L+1);		
		}
	}
}

int main(){
	
	cout<<"Ho va ten:Tran Van Tuyen"<<endl;
	cout<<"MSSV:20184012";cin>>n;
	cin>>k1>>k2;
	TRY(1,0,0);
	TRY(1,1,0);
	return 1;
}
