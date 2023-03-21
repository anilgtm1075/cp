#include<bits/stdc++.h>
using namespace std;
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
int countFactors(int n){
        //code here
        int cnt = 1;
        for(int x = 2; x*x<=n; x++){
            int temp = 0;
            while(n%x==0){
                temp++;
                n/=x;
            }
            cnt*=(temp+1);
        }
        if(n>1) cnt*=2;
        return cnt;
 }
int main(){
  int n;
  cin>>n;
  cout<<countFactors(n)<<endl;
  cout<<sumOfDivisor(n)<<endl;
  return 0;
}
