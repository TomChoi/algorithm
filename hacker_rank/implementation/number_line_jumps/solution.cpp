#include <bits/stdc++.h>
using namespace std;

string solve(int x1, int v1, int x2, int v2) {
    if (v1 == v2)
        if (x1 == x2) return "YES";
        else return "NO";

    int sx, sv, fx, fv;
    if (v1 > v2){
        sv = v2; sx = x2;
        fv = v1; fx = x1;
    } else {
        sv = v1; sx = v1;
        fv = v2; fx = v2;
    }

    if (fx>=sx) return "NO";
    else {
        while(sx>fx){
            sx += sv;
            fx += fv;
        }
        if (sx == fx)
            return "YES";
        else 
            return "NO";
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int x1, x2, v1, v2;
    cin>>x1>>v1>>x2>>v2;
    
    string ans=solve(x1, v1, x2, v2);
    cout<<ans<<"\n";
    return 0;
}

