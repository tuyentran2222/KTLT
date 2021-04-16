#include <bits/stdc++.h>
using namespace std;
int a[1000], n;
int mem[1000]; //# mang ghi nho loi giai các bài toán con dã duoc giai
static int min=0;

void init(){
    memset(mem, -1, sizeof(mem));
}

//# Quy hoach dong
//# Hàm lis(i) tra ve do dài dãy con tang dài nhat ket thuc boi a[i]
int lis(int i) {
	if (i==0) return 1;
	int max=1;
	for (int j=0;j<=i-1;j++){
		if (a[j]<a[i]&&(max<lis(j)+1))	{
			max= lis(j)+1;
		};
	}
	return max;

}
//# Truy vet loi giai
void trace(int i){
    for(int j = 0; j < i; j++){
        if (a[j] < a[i] && mem[i] == 1 + mem[j]){
            trace(j);
            break;
        }
    }
    cout << a[i] << " ";
}
int main(){

    init();
    cout<<"Ho va ten:Tran Van Tuyen"<<endl;
	cout<<"MSSV:20184012";
    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];
	for(int i = 0; i < n; i++) mem[i]=lis(i); 
    int res = 1, pos = 0;
    for(int i = 1; i < n; i++){
        if (res < lis(i)){
            res = lis(i);
            pos = i;
        }
    }
    cout << res << endl;
    trace(pos);
    return 0;
}
