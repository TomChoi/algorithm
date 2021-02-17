#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N=5;
const ll mxN=LLONG_MAX;

void solve(vector<int> arr) {
    ll min=mxN, max=0;
    for(int i=0; i<N; ++i) {
        ll n=0;
        for (int j=0; j<N; ++j) {
            if (i!=j) {
                n += arr[j];
            }
        }
        if (min>n) {
            min=n;
        }
        if (max<n) {
            max=n;
        }
    }
    cout<<min<<" "<<max<<"\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    vector<int> arr(N);
    for(int i=0; i<N; ++i) {
        int e;
        cin>>e;
        arr[i]=e;
    }

    solve(arr);

    return 0;
}
