#include <bits/stdc++.h>
using namespace std;

vector<int> solve(vector<int> sticks) {
    vector<int> ans;
    sort(sticks.begin(), sticks.end(), greater<int>());
    int s=sticks.size();
    for(int i=0; i<s-2; ++i) {
        if(sticks[i] < sticks[i+1] + sticks[i+2]) {
            ans.resize(3);
            for(int k=0; k<3; k++)
                ans[k]=sticks[i+2-k];
            return ans;
        }
    }
    ans.push_back(-1);
    return ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin>>n;

    vector<int> a(n);
    for(int i=0; i<n; ++i)
        cin>>a[i];

    vector<int> ans=solve(a);
    for(int e: ans)
        cout<<e<<" ";
    cout<<"\n";
    return 0;
}
