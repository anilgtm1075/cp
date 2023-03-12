#include <bits/stdc++.h>
using namespace std;

//is a number is prime or not
bool isPrime(int n){
  if (n <= 1)
        return false;
    // Check if n=2 or n=3
    if (n == 2 || n == 3)
        return true;
    // Check whether n is divisible by 2 or 3
    if (n % 2 == 0 || n % 3 == 0)
        return false;
    // Check from 5 to square root of n
    // Iterate i by (i+6)
    for (int i = 5; i <= sqrt(n); i = i + 6)
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
 
    return true;
}
//optimized code
void seive_of_eratosthenes(int n){
    vector<bool> is_prime(n+1, true);
    is_prime[0] = is_prime[1] = false;
    for(int x = 2; x*x<=n; x++){
        if(is_prime[x]){
            for(int u = x*x; u<=n; u+=x){
                is_prime[u] = false;
            }
        }
    }
}
int main() {
	int n;
	cin>>n;
	seive_of_eratosthenes(n);
	return 0;
}
