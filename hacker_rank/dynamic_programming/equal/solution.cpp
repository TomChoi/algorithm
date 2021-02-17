#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> arr) {
    vector<int> c = {5, 2, 1};
    int ans = INT_MAX;
    int min = *min_element(arr.begin(), arr.end());
    for (int j=0; j<5; ++j) {
        int cnt=0;
        for(int i=0; i<arr.size(); ++i) {
            int n=arr[i] - min + j;
            if (n) {
                for (int j=0; j<c.size(); ++j) {
                    cnt+= n/c[j];
                    n %= c[j];
                }
            }
        }
        ans = std::min(ans, cnt);
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin>>t;

    int n;
    cin>>n;

    vector<int> a(n);
    for(int i=0; i<n; ++i)
        cin>>a[i];

    int ans=solve(a);
    cout<<ans<<"\n";

    return 0;
}
