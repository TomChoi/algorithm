#include <bits/stdc++.h>
using namespace std;

string solve(long long n) {
    string ans="";
    
    if (n==1) {
        return "Richard";
    }
    int cnt=0;
    while (n>1) {

        if(__builtin_popcount(n)>1) {
            long long l=1;
            n -= (l<<((sizeof(n)*8-1)-__builtin_clzll(n)));
        } else {
            n /= 2;
        }
        cnt++;
    }

    if (cnt%2 == 0)
        ans="Richard";
    else 
        ans="Louise";

    return ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    long long t,n;
    cin>>t;
    for(int i=0; i<t; ++i) {
        cin>>n;
        string ans=solve(n);
        cout<<ans<<"\n";
    }

    return 0;
}
