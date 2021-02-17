#include <bits/stdc++.h>
using namespace std;

void solve(int n) {
    vector<int> a;
    a.push_back(1);
    for(int i=2; i<=n; ++i) {
        for (int j=0; j<a.size(); ++j)
            a[j] *= i;

        for (int j=0; j<a.size(); ++j) {
            if (a[j] >= 10){
                if (j == a.size()-1)
                    a.push_back(0);

                a[j+1] += a[j] / 10;
                a[j] %= 10;
            }
        }
    }
    for(auto i=a.rbegin(); i != a.rend(); ++i)
        cout<<*i;
    cout<<"\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin>>n;
    solve(n);
   

    return 0;
}
