#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    vector<int> a;
    
    cin >> n;
    for (int i=0; i<n; i++) {
        int c;
        cin >> c;
        a.push_back(c);
    }
    
    int sum=0, mxS=0;
    for (int i=0; i<n; i++) {
        sum+=a[i];
        sum=max(0, sum);

        if (mxS<sum)
            mxS=sum;
    }

    cout<<"max sum is "<<mxS<<"\n";

    return 0;
}
