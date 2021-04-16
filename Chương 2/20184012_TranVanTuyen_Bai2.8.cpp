#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int main() {
    int val1, val2;
    cin >> val1 >> val2;
    vector< vector<int> > a = {
        {1, 3, 7},
        {2, 3, 4, val1},
        {9, 8, 15},
        {10, val2},
    };
    
    auto func=[] (vector<int> m){
        int sum=0;
        for(int i=0;i<m.size();i++){
            sum=sum+m[i];}
        return sum;
    };
   
    for (int k=a.size()-1;k>=0;k--){
       for (int j=1;j<=k;j++){
           
           if (func(a[j-1])<func(a[j])) a[j-1].swap(a[j]);
       }
    }
           
    for (const auto &v : a) {
        for (int it : v) {
            cout << it << ' ';
        }
        cout << endl;
    }
    return 0;
}
