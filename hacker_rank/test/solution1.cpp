#include <bits/stdc++.h>

using namespace std;

long solve(vector<int> files, int numCores, int limit) {
    long ans=0;
    
    sort(files.begin(), files.end(), greater<int>());
    long sz=files.size();
    for(long i=0; i<sz; ++i) {
        if(limit>0) {
            if(files[i]%numCores==0) {
                ans+=files[i]/numCores;
                limit--;
            } else {
                ans+=files[i];
            }
        } else {
            ans+=files[i];
        }
    }
    return ans;
}

int main() {
    int n;
    cin>>n;
    vector<int> f(n);

    for(int i=0; i<n; ++i)
        cin>>f[i];

    long nc, l;
    cin>>nc>>l;

    long ans=solve(f, nc, l);
    cout<<ans<<endl;

    return 0;
}

