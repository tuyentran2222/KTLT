#include <bits/stdc++.h>

using namespace std;


typedef long long ll;

#define EL printf("\n")
#define pb push_back
#define FOR(i,l,r) for (int i=l;i<=r;i++)
#define FORD(i,r,l) for (int i=r;i>=l;i--)

const int base = 1e9;
typedef vector<int> BigInt;
typedef struct {
	char dau;
	BigInt so;
}Big;

void Set(BigInt &a) {
    while (a.size() > 1 && a.back() == 0) a.pop_back();
}

void Print(BigInt a) {
    Set(a);
    printf("%d", (a.size() == 0) ? 0 : a.back());
    FORD(i,a.size()-2,0) printf("%09d", a[i]); EL;
}
BigInt Integer(string s) {
    BigInt ans;
    
    if (s.size() == 0) {ans.pb(0); return ans;}
    while (s.size()%9 != 0) s = '0'+s;
    for (int i=0;i<s.size();i+=9) {
        int v = 0;
        for (int j=i;j<i+9;j++) v = v*10+(s[j]-'0');
        ans.insert(ans.begin(),v);
    }
    Set(ans);
    return ans;
}

BigInt Integer(char c[]) {
    string s = "";
    FOR(i,0,strlen(c)-1) s = s + c[i];
    return Integer(s);
}

BigInt Integer(ll x) {
    string s = "";
    while (x > 0) s = char(x%10+'0') + s, x /= 10;
    return Integer(s);
}

BigInt Integer(int x) {
    return Integer((ll) x);
}

void operator >> (istream &cin, Big &a) {
	string s;
	cin>>a.dau;
	cin>>s;
    a.so= Integer(s);
}
void operator << (ostream &out, BigInt a) {
    Print(a);
}
bool operator < (BigInt a, BigInt b) {
    Set(a);
    Set(b);
    if (a.size() != b.size()) return (a.size() < b.size());
    FORD(i,a.size()-1,0)
        if (a[i] != b[i]) return (a[i] < b[i]);
    return false;
}
bool operator >= (BigInt a, BigInt b) {
    return (b < a || b == a);
}

Big operator + (Big a, Big b);
Big operator - (Big a, Big b);
Big operator + (Big a, Big b) {
    Set(a.so);
    Set(b.so);
    Big ans;
    if (a.dau==b.dau) ans.dau=a.dau;
    else{
    	if (a.so>=b.so) {
    		b.dau=a.dau;
    		ans=a-b;
    		return ans;
		}
		else{
			a.dau=b.dau;
			ans=b-a;
			return ans;
		}
	}
    int carry = 0;
    FOR(i,0,max(a.so.size(), b.so.size())-1) {
        if (i < a.so.size()) carry += (a.so)[i];
        if (i < b.so.size()) carry += (b.so)[i];
        ans.so.pb(carry%base);
        carry /= base;
    }
    if (carry) ans.so.pb(carry);
    Set(ans.so);
    return ans;
}



Big operator - (Big a, Big b) {
    Set(a.so);
    Set(b.so);
    Big ans;
    if (a.dau!=b.dau){
    	b.dau=a.dau;
    	ans=a+b;
    	return ans;
	}
	if (a.so>=b.so){
		ans.dau=a.dau;
	}
    if(a.so<b.so){
	 (a.so).swap(b.so);
	if ((a.dau=='0' )&&(b.dau=='0')) ans.dau='1';
	 else ans.dau='0';
	}

    int carry = 0;
    FOR(i,0,a.so.size()-1) {
        carry += (a.so)[i] - (i < (b.so).size() ? (b.so)[i] : 0);
        if (carry < 0) ans.so.pb(carry+base), carry = -1;
        else ans.so.pb(carry), carry = 0;
    }
    Set(ans.so);
    return ans;
}



Big operator * (Big a, Big b) {
    Set(a.so);
    Set(b.so);
    Big ans;
    if ((a.dau=='1'&&b.dau=='1')||(a.dau=='0'&&b.dau=='0')) ans.dau='1';
    else ans.dau='0';
    ans.so.assign(a.so.size()+b.so.size(), 0);
    FOR(i,0,a.so.size()-1) {
        ll carry = 0ll;
        for (int j=0;j<b.so.size() || carry > 0;j++) {
            ll s = (ans.so)[i+j] + carry + (ll)(a.so)[i]*(j<(b.so).size()?(ll)(b.so)[j]:0ll);
            (ans.so)[i+j] = s%base;
            carry = s/base;
        }
    }
    Set(ans.so);
    return ans;
}

Big operator * (Big a, int b) {
	Big ans1;
	ans1.dau='1';
	ans1.so =Integer(b);
    return ans1*a;
}

int main()
{	printf("Ho Va Ten: Tran Van Tuyen\n"); 
   	printf("MSSV: 20184012\n\n");	
	Big A; cin>> A;
    Big B;  cin >> B;
    
    cout<<(A*B+(B*4)-(A*3)).dau;
    cout<<(A*B+(B*4)-(A*3)).so;
    
    return 0;
}
