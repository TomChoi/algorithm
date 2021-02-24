#include <iostream>
#include <vector>

using namespace std;

int solve(int n, int p) {
    int k=p/2;
    int l=n/2 -k;
    return k > l ? l : k;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,p;
    cin>>n>>p;
    int ans=solve(n,p);
    cout<<ans<<"\n";

    return 0;
}
