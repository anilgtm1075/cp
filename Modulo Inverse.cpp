#include <bits/stdc++.h>
using namespace std;
const int m = 1e9 + 7;
//modulo inverse for a number
// inv(i) = -floor(m/i)*inv(m%i)%m
int invr(int i) {
  return i <= 1 ? i : m - (long long)(m/i) * invr(m % i) % m;
}

//modulo inverse in range from [1, m-1]
void inv_1_to_m(int m){
    vector<int> inv(m);
    inv[1]=1;
    for(int i = 2; i<m; i++){
        inv[i] = m - (long long)(m/i) * inv[m%i] % m;
    }
}
int main() {
	int n;
	cin>>n;
    inv_1_to_m(n);
	return 0;
}
