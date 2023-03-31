#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
// iterative way to compute (a^n)%mod
//idea based on that n can be written as power of two
int modPow(int a, int n){
    int x = a;
    int res = 1;
    while(n>0){
        if(n&1)
            res = (res*1LL*x)%mod;
        x = (x *1LL* x)%mod;
        n = n>>1;
    }
    return res;
}
int main() {
	int a, n;
	cin>>a>>n;
	cout<<modPow(a,n);
	return 0;
}
