#include <bits/stdc++.h>
using namespace std;

void solve(int n) {
    string ans="";

    while(n>=3 && n != 4) {
        int r=n%3;
        if(r) {
            n -= 5;
            ans += "33333";
        } else {
            int k=n/3;
            for(int i=0; i<k; ++i) {
                ans.insert(0,"555");
            }
            cout<<ans<<"\n";
            return;
        }
    }
    if (n)
        cout<<"-1"<<"\n";
    else 
        cout<<ans<<"\n";
    return;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0; i<n; ++i){
        cin>>a[i];
        solve(a[i]);
    }

    return 0;
}
