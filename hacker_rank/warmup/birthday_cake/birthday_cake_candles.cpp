#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> candles) {
    int s=candles.size();
    int max=0, ans=0;
    for (int i=0; i<s; ++i) {
        if(candles[i] > max) {
            max=candles[i];
            ans=1;
        } else if (candles[i] == max) {
            ans++;
        }
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin>>n;

    vector<int> ar(n);

    for(int i=0; i<n; ++i) {
        int e;
        cin>>e;
        ar[i] = e;
    }

    int ans = solve(ar);
    cout<<ans<<"\n";
    return 0;
}
