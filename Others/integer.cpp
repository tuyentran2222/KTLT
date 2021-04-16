

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define EL printf("\n")
#define pb push_back
#define FOR(i,l,r) for (int i=l;i<=r;i++)
#define FORD(i,r,l) for (int i=r;i>=l;i--)

const int base = 1e9;
typedef vector<int> BigInt;
typedef struct{
	char dau;
	BigInt a;
}Big;

void Set(Big &a) {
    while (a.a.size() > 1 && a.a.back() == 0) a.a.pop_back();
}

void Print(Big a) {
	cout<<a.dau;
    Set(a);
    printf("%d", (a.a.size() == 0) ? 0 : a.a.back());
    FORD(i,a.a.size()-2,0) printf("%09d", a.a[i]); EL;
}

Big Integer(string s) {
    Big ans;
    
    if (s[0] == '0') {
    	ans.dau='0';
	}
	else ans.dau='1';
    if (s.size() == 0) {ans.a.pb(0); return ans;}
    while ((s.size()-1)%9!= 0) s = '0'+s;
    for (int i=1;i<s.size();i+=9) {
        int v = 0;
        for (int j=i;j<i+9;j++) v = v*10+(s[j]-'0');
        ans.a.insert(ans.a.begin(),v);
    }
    Set(ans);
    return ans;
}

Big Integer(char c[]) {
    string s = "";
    FOR(i,0,strlen(c)-1) s = s + c[i];
    return Integer(s);
}

Big Integer(ll x) {
    string s = "";
    while (x > 0) s = char(x%10+'0') + s, x /= 10;
    return Integer(s);
}

Big Integer(int x) {
    return Integer((ll) x);
}

void operator >> (istream &in, Big &a) {
    string s;
    getline(cin, s);
    a = Integer(s);
}

void operator << (ostream &out, Big a) {
    Print(a);
}

bool operator >= (Big. a, BigInt b) {
    return (b < a || b == a);
}
Big operator + (Big a, Big b) {
    Set(a);
    Set(b);
    Big ans;
    int carry = 0;
    FOR(i,0,max(a.a.size(), b.a.size())-1) {
        if (i < a.size()) carry += a[i];
        if (i < b.size()) carry += b[i];
        ans.pb(carry%base);
        carry /= base;
    }
    if (carry) ans.pb(carry);
    Set(ans);
    return ans;
}

BigInt operator + (BigInt a, int b) {
    return a + Integer(b);
}



BigInt operator * (BigInt a, BigInt b) {
    Set(a);
    Set(b);
    cout<<a[0]<<endl;
    BigInt ans;
    ans.assign(a.size()+b.size(), 0);
    FOR(i,0,a.size()-1) {
        ll carry = 0ll;
        for (int j=0;j<b.size() || carry > 0;j++) {
            ll s = ans[i+j] + carry + (ll)a[i]*(j<b.size()?(ll)b[j]:0ll);
            ans[i+j] = s%base;
            carry = s/base;
        }
    }
    Set(ans);
    return ans;
}

BigInt operator * (BigInt a, int b) {
    return a * Integer(b);
}

void operator *= (BigInt &a, BigInt b) {
    a = a * b;
}

void operator *= (BigInt &a, int b) {
    a = a * b;
}



int main()
{
	BigInt D ;cin>>D;
    BigInt B;  cin >> B;
	cout<<D*B+D*(-3)+B*4;
	cout<<D*(-3);
    return 0;
}
