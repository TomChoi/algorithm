#include <bits/stdc++.h>
using namespace std;

#define N 2
int solve(vector<int> A, vector<int> B) {
    int s=A.size();
    int ans=0;

    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    int bi=0;
    for(int i=0; i<s; ++i){
        for(int j=bi; j<s; ++j){
            if(A[i] < B[j])
                break;
            else if(A[i] == B[j]){
                ans++;
                bi++;
                break;
            }
            bi++;
        }
    }
    if (ans < s) return ++ans;
    return --ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin>>n;
    vector<vector<int>> a(N);

    for(int i=0; i<N; ++i){
        a[i].resize(n);
        for(int j=0; j<n; ++j)
            cin>>a[i][j];
    }
    int ans=solve(a[0], a[1]);
    cout<<ans<<"\n";

    return 0;
}

