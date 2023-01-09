#include <iostream>
#include <vector>

using namespace std;

vector<double> solution(int n, int d, int p, vector<vector<int>>& path, vector<int>& v) {
    vector<double> ret;

    for(int depature: v) {
        search(
    return ret;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int q;
    cin>>q;

    while(q--) {
        int n, d, p;
        cin>>n>>d>>p;
        vector<vector<int>> path(n);
        percentage.resize(n,1);
        for(int i=0; i<n; ++i) {
            path[i].resize(n);
            for(int j=0; j<n; ++j) {
                cin>>path[i][j];
            }
        }

        int t;
        cin>>t;
        vector<int> v(t);
        for(int i=0; i<t; ++i) {
            cin>>v[i];
        }

        vector<double> ans = solution(n, d, p, path, v);
        for(double e: ans) 
            cout<<e<<" ";
        cout<<"\n";
    }

    return 0;
}
