#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
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

//if answer fit in long long
int C(int n, int k) {
    double res = 1;
    for (int i = 1; i <= k; ++i)
        res = res * (n - k + i) / i;
    return (int)(res + 0.01);
}

//if answer not fit than nCr%mod
int C(int n, int r){
    if(r>n) return 0;
    int res = 1;
    for(int i=1;i<=r;i++){
        res = (res * 1LL * (n-r+i))%mod;
        res = (res * 1LL * modPow(i,mod-2))%mod;
    }
    return res;
}

//Recursive approach
int nCr(int n, int r){
    int C[n + 1][r + 1]; //we can optimize the space by using prev and current two vector
    C[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        C[i][0] = C[i][i] = 1;
        for (int k = 1; k < i; ++k)
            C[i][k] = C[i - 1][k - 1] + C[i - 1][k];
    }
    return C[n][r];
}


//For Multiple Queries
bool flag = true;
const int maxn = 1e5;
int fact[maxn+1], inv[maxn+1];
void precompute(){
    fact[0] = fact[1] = 1;
    inv[0] = inv[1] = 1;
    for(int i=1;i<=maxn; i++){
        fact[i] = (fact[i-1]*1LL*i)%mod;
        inv[i] = modPow(fact[i], mod-2);
    }
}
int query(int n, int r){
    //nCr = (fact[n] * inv[fact[r]] * inv[fact[n-r]]) %mod
    if(flag){
        precompute(); // it takes O(MAXN * log(Mod))
        flag = false;
    }
    return (((fact[n] *1LL* inv[r])%mod *1LL* inv[n-r]))%mod;
}
int main() {
	int t;
	cin>>t;
// 	precompute();
	while(t--){
	    int n, r;
	    cin>>n>>r;
	   // cout<<query(n,r)<<endl;
	   cout<<C(n,r)<<endl;
	}
	return 0;
}
