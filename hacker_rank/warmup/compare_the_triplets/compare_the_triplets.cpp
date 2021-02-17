#include <bits/stdc++.h>

using namespace std;

const int N=3;

vector<int> solve(vector<int> a, vector<int> b) {
    vector<int> ans(2);

    int s=a.size();
    for(int i=0; i<s; ++i) {
        if(a[i] > b[i]) {
            ans[0]++;
        } else if(a[i] < b[i]) {
            ans[1]++;
        }
    }

    return ans;
}

int main() {
    vector<int> a(N);
    vector<int> b(N);

    int n;
    for(int i=0; i<N; ++i) {
        cin>>n;
        a.push_back(n);
    }
    for(int i=0; i<N; ++i) {
        cin>>n;
        b.push_back(n);
    }

    vector<int> ans=solve(a, b);
    cout<<ans[0]<<" "<<ans[1]<<"\n";

    return 0;
}
