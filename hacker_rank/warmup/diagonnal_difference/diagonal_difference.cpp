#include <bits/stdc++.h>
using namespace std;

int solve(vector<vector<int>> arr) {
    int ans = 0;

    int n = arr.size();
    int n1=0, n2=0;
    for(int i=0; i<n; ++i) {
        n1 += arr[i][i];
    }

    for(int i=0; i<n; ++i) {
        n2 += arr[i][(n-1)-i];
    }

    ans = n1 - n2;
    return abs(ans);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin>>n;

    vector<vector<int>> arr(n);
    for(int i=0; i<n; ++i) {
        arr[i].resize(n);
        for(int j=0; j<n; ++j) {
            int e;
            cin>>e;
            arr[i][j] = e;
        }
    }
    int ans = solve(arr);
    cout<<ans<<"\n";
    return 0;
}
