#include<bits/stdc++.h>
using namespace std;
//phi(n) = count the number of coprime number with n from 1,2....n
long long phi(long long n){
  long long res = n;
        for(int x=2;x*x<=n;x++){
            if(n%x==0){
                while(n%x==0){
                    n/=x;
                }
                res = res - res/x;
            }
        }
        if(n>1) res = res - res/n;
        return res;
}
void phi_1_to_n(int n) {
    vector<int> phi(n + 1);
    for (int i = 0; i <= n; i++)
        phi[i] = i;

    for (int i = 2; i <= n; i++) {
        if (phi[i] == i) {
            for (int j = i; j <= n; j += i)
                phi[j] -= phi[j] / i;
        }
    }
}
int main(){
  long long n;
  cin>>n;
  cout<<phi(n)<<endl;
  phi_1_to_n(n);
  return 0;
}
