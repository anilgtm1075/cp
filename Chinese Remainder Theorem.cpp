#include <bits/stdc++.h>
using namespace std;
//modulo inverse for a number
// inv(i) = -floor(m/i)*inv(m%i)%m
int inv(int i) {
    //here m>i otherwise make i less than m in one step i = (i + m)%m;
    return i <= 1 ? i : m - (long long)(m/i) * inv(m % i) % m;
}
//chinese remainder therem
int getX(vector<int> &a, vector<int> &m){
    int n = a.size();
    int p = 1;
    for(int i = 0;i<n;i++)
        p*=m[i];
    
    int res = 0;
    for(int i=0;i<n;i++){
        int pi = p/m[i];
        int invr = inv(pi%m[i], m[i]); // here m[i] > p[i]
        res=(res + pi * invr * a[i])%p;
    }
    return res%p;
}
int main() {
	int n;
	cin>>n;
	vector<int> a(n), m(n);
	for(int i=0;i<n;i++){
	    cin>>a[i];
	}
	for(int i=0;i<n;i++){
	    cin>>m[i];
	}
	cout<<getX(a,m);
	return 0;
}
