#include <bits/stdc++.h>
using namespace std;

//optimized code
vector<bool> segmentedSieve(long long L, long long R){
    long long lim = sqrt(R);
    vector<bool> mark(lim + 1, false);
    //only need those prime number which is in the range 1 to sqrt(R)
    vector<long long> primes;
    for (long long i = 2; i <= lim; ++i) {
        if (!mark[i]) {
            primes.emplace_back(i);
            for (long long j = i * i; j <= lim; j += i)
                mark[j] = true;
        }
    }
    
    //shift the index, as 0 to L
    vector<bool> isPrime(R - L + 1, true);
    for (long long i : primes){
        long long t = max(i * i, (L + i - 1) / i * i);
        //or the value of t is given
        //     long long  t = (l/p)*p;
        //     if(t<l)
        //         t+=p;
        //     t = max(2*p, t);
        for (long long j = t; j <= R; j += i)
            isPrime[j - L] = false;
    }
    if (L == 1)
        isPrime[0] = false;
    return isPrime;
}
int main() {
	long long l, r;
	cin>>l>>r;
	vector<bool> isPrime = segmentedSieve(l,r);
	for(int i=0;i<(r-l+1); i++){
	    if(isPrime[i]){
	        cout<<i+l<<" ";
	    }
	}
	return 0;
}
