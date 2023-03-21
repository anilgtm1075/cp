#include<bits/stdc++.h>
int sumOfDivisor(int n){
        int res = 1;
        for(int x = 2; x*x<=n; x++){
            if(n%x==0){
                int sum = 1;
                int val = 1;
                while(n%x==0){
                    val*=x;
                    sum+=val;
                    n/=x;
                }
                res*=sum;
            }
        }
        if(n>1) res*=(n+1);
        return res;
}
using namespace std;
int main(){
  int n;
  cin>>n;
  cout<<sumOfDivisor(n)<<endl;
  return 0;
}
