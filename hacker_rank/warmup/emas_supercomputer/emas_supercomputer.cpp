#include <bits/stdc++.h>
using namespace std;



int solve(vector<string> grid) {
    int ans=0;
    int s=grid.size()>grid[0].size()?grid[0].size():grid.size();
    int n=s%2?s:s-1;
    vector<int> v;

    for(int i=n-1; i>=0; i-=2) {
        for(int r=i; r<grid.size(); ++r) {
            for(int c=i; c<grid[0].size(); ++c) {
                bool check=true;
                for(int k=0; k<=i; ++k) {
                    if(grid[r-(i/2)][c-k] == 'B'){
                        check=false;
                        break;
                    }
                }
                if (check) {
                    for(int k=0; k<=i; ++k) {
                        if(grid[r-k][c-(i/2)] == 'B'){
                            check=false;
                            break;
                        }
                    }
                }
                if (check) {
                    v.push_back(i*2+1);
                    if(v.size() == 2) {
                        ans=v[0]*v[1];
                        return ans;
                    }

                    for(int k=0; k<=i; ++k) {
                        grid[r-(i/2)][c-k] = 'B';
                        grid[r-(i/2)+1][c-k] = 'B';
                        grid[r-(i/2)-1][c-k] = 'B';
                    }

                    for(int k=0; k<=i; ++k) {
                        grid[r-k][c-(i/2)] = 'B';
                        grid[r-k][c-(i/2)+1] = 'B';
                        grid[r-k][c-(i/2)-1] = 'B';
                    }

                    if (c-i>0) {
                        grid[r-(i/2)][c-i-1] = 'B';
                    }

                    if (r-i>0) {
                        grid[r-i-1][c-(i/2)] = 'B';
                    }

                    if (r+1<grid.size()) {
                        grid[r+1][c-(i/2)] = 'B';
                    }

                    if (c+1<grid[0].size()) {
                        grid[r-(i/2)][c+1] = 'B';
                    }
                    c+=i+1;
                }
            }
        }
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int r,c;
    cin>>r>>c;
    cin.ignore();

    vector<string> g(r);
    for(int i=0; i<r; ++i) {
        getline(cin, g[i]);
    }
    int ans=solve(g);
    cout<<ans<<"\n";

    return 0;
}
