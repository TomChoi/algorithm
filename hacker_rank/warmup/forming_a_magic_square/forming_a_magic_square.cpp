#include <bits/stdc++.h>
using namespace std;

const int N=3;
const int mxN=INT_MAX;

int solve(vector<vector<int>> s) {
    int ans=mxN;
    const vector<vector<vector<int>>> pre= {
        {{8, 1, 6}, {3, 5, 7}, {4, 9, 2}},
        {{6, 1, 8}, {7, 5, 3}, {2, 9, 4}},
        {{4, 9, 2}, {3, 5, 7}, {8, 1, 6}},
        {{2, 9, 4}, {7, 5, 3}, {6, 1, 8}},
        {{8, 3, 4}, {1, 5, 9}, {6, 7, 2}},
        {{4, 3, 8}, {9, 5, 1}, {2, 7, 6}},
        {{6, 7, 2}, {1, 5, 9}, {8, 3, 4}},
        {{2, 7, 6}, {9, 5, 1}, {4, 3, 8}},
    };

    for(auto m: pre) {
        int sum=0;
        for(int i=0; i<N; ++i) {
            for(int j=0; j<N; ++j) {
                sum+=abs(s[i][j] - m[i][j]);
            }
        }
        if (ans > sum) {
            ans = sum;
        }
    }

    return ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    vector<vector<int>> ar(N);
    for(int i=0; i<N; ++i) {
        ar[i].resize(N);
        for(int j=0; j<N; ++j) {
            int e;
            cin>>e;
            ar[i][j]=e;
        }
    }
    int ans=solve(ar);
    cout<<ans<<"\n";

    return 0;
}
