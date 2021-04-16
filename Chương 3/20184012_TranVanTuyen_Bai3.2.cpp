#include <iostream>
using namespace std;

int n;
int finish=0;
int X[100], Y[100]; //# Luu toa do c�c buoc di chuyen c?a qu�n m�
int mark[100][100]; //# ��nh dau vi tr� c�c � m� qu�n m� d� di chuyen qua

//# Mang hx, hy m� ta 8 vi tr� qu�n m� c� the di chuyen ke tu vi tri hien tai
const int hx[] = {1, 1, 2, 2, -1, -1, -2, -2}; 
const int hy[] = {2, -2, 1, -1, 2, -2, 1, -1};

//# In ra d�y c�c di chuyen t�m duoc
void print_sol(){
    for (int j = 1; j <= n * n; ++j)
        printf("(%d %d)\n", X[j], Y[j]);
    exit(0);
}
//# Thuat to�n quay lui
void TRY(int k){
    for(int i = 0; i < 8; i++){
        int xx = X[k-1] + hx[i];
        int yy = Y[k-1] + hy[i];
        if( (xx>0 )&& (xx<(n+1))&&(yy>0)&&(yy<(n+1))&&(mark[xx][yy]==0)){	
        	X[k]=xx;
        	Y[k]=yy;
        	mark[xx][yy]=1;
        	if(k==n*n) {finish=1 ;break;}
        	else{
        			TRY(k+1);
        			if (!finish){
        				mark[xx][yy]=0;
					}				
			}
		}	
    }
}

int main(){
	cout<<"Ho va ten:Tran Van Tuyen"<<endl;
	cout<<"MSSV:20184012";
	cin >> n;
    mark[1][1] = 1;
    X[1] = Y[1] = 1;
    TRY(2);
    print_sol();
	return 0;
}
