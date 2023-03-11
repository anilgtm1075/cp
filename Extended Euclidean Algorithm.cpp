#include<bits/stdc++.h>
using namespace std;
//simple extended euclid algorithm
int gcd(int a, int b, int &x, int &y){
    if(b==0){
        x = 1, y = 0;
        return a;
    }
    int x1, y1;
    int g = gcd(b, a%b, x1, y1);
    x = y1;
    y = x1 - floor(a/b)*y1;
    return g;
}
//finding base solution
bool find_any_solution(int a, int b, int c, int &x, int &y, int &g){
    g = gcd(abs(a), abs(b), x, y);
    if(c%g) return 0;
    x*=c/g;
    y*=c/g;
    if(a<0) x = -x;
    if(b<0) y = -y;
    return true;
}
//shift the solution
void shift_solution(int & x, int & y, int a, int b, int cnt) {
    x += cnt * b;
    y -= cnt * a;
}
//find x range and given number solution (basically its based on k range , x = x + kb/g and y = y - ka/g)
int find_all_solutions(int a, int b, int c, int minx, int maxx, int miny, int maxy) {
    int x, y, g;
    if (!find_any_solution(a, b, c, x, y, g))
        return 0;
    a /= g;
    b /= g;

    int sign_a = a > 0 ? +1 : -1;
    int sign_b = b > 0 ? +1 : -1;

    shift_solution(x, y, a, b, (minx - x) / b);
    if (x < minx)
        shift_solution(x, y, a, b, sign_b);
    if (x > maxx)
        return 0;
    int lx1 = x;

    shift_solution(x, y, a, b, (maxx - x) / b);
    if (x > maxx)
        shift_solution(x, y, a, b, -sign_b);
    int rx1 = x;

    shift_solution(x, y, a, b, -(miny - y) / a);
    if (y < miny)
        shift_solution(x, y, a, b, -sign_a);
    if (y > maxy)
        return 0;
    int lx2 = x;

    shift_solution(x, y, a, b, -(maxy - y) / a);
    if (y > maxy)
        shift_solution(x, y, a, b, sign_a);
    int rx2 = x;

    if (lx2 > rx2)
        swap(lx2, rx2);
    int lx = max(lx1, lx2);
    int rx = min(rx1, rx2);

    if (lx > rx)
        return 0;
    return (rx - lx) / abs(b) + 1;
}
int main(){
    int a,b,c;
    cin>>a>>b>>c;
    // int x,y;
    if(find_all_solutions(a,b,c, 0, 100000, 0, 100000)){
        cout<<"Yes"<<endl;
    }
    else{
        cout<<"No"<<endl;
    }
    return 0;
}
