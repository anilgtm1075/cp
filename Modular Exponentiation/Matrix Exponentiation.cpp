#include <bits/stdc++.h>
using namespace std;
void multi(vector<vector<int> >& a, vector<vector<int>>& b) {
        // Code here
        int n = a.size();
        vector<vector<int>> prod(n, vector<int>(n));
        for(int i=0;i<n;i++){
            for(int j = 0; j<n; j++){
                int sum = 0;
                for(int k = 0; k<n; k++){
                    sum+=a[i][k]*b[k][j];
                }
                prod[i][j] = sum;
            }
        }
        a = prod;
}
vector<vector<int>> matrixExponentiation(vector<vector<int>>& a, int n){
    if(n==1){
        return a;
    }
    vector<vector<int>> u = matrixExponentiation(a, n/2);
    multi(u, u);
    if(n&1) 
    multi(u, a);
    return u;
}
int main() {
    int n, x;
    cin>>n>>x;
	vector<vector<int>> a(n, vector<int>(n));
	for(int i=0;i<n; i++){
	    for(int j=0; j<n; j++){
	        cin>>a[i][j];
	    }
	}
    vector<vector<int>> res = matrixExponentiation(a, x);
    for(int i=0; i<n; i++){
	    for(int j=0; j<n; j++){
	        cout<<res[i][j]<<" ";
	    }
	    cout<<endl;
	}
	return 0;
}
