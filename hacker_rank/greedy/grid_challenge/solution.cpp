#include <bits/stdc++.h>
using namespace std;

string solve(vector<string> grid) {
    int s=grid.size();
    for(int i=0; i<s; ++i) {
        sort(grid[i].begin(), grid[i].end());
    }
    for(int i=0; i<s-1; ++i) {
        for(int j=0; j<grid[0].length(); ++j) {
            if(grid[i][j] > grid[i+1][j])
                return "NO";
        }
    }
    return "YES";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin>>t;
    
    for(int i=0; i<t; ++i) {
        int n;
        cin>>n;
        vector<string> s(n); 
        cin.ignore();
        for(int j=0; j<n; ++j) {
            getline(cin, s[i]);
        }
        string ans=solve(s);
        cout<<ans<<"\n";
    }
    return 0;
}
