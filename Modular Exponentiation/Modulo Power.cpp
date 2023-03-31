#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
int modPow(int a, int n){
    if(n==1){
        return a;
    }
    long long u = modPow(a, n/2);
    u = (u*u)%mod;
    if(n&1){
        u = (u*a)%mod;
    }
    return u;
}
int main() {
	int a, n;
	cin>>a>>n;
	cout<<modPow(a,n);
	return 0;
}
