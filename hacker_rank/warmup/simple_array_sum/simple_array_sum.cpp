#include <bits/stdc++.h>

using namespace std;

int solve(vector<int> ar) {
    int ans=0;

    int s=ar.size();

    for(int i=0; i<s; ++i) {
        ans+=ar[i];
    }

    return ans;
}

int main() {

    int n;
    vector<int> ar;

    cin>>n;
    for(int i=0; i<n; i++) {
        int c;
        cin>>c;
        ar.push_back(c);
    }

    cout << solve(ar) << "\n";
    return 0;
}
