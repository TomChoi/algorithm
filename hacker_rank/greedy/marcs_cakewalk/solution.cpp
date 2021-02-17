#include <bits/stdc++.h>
using namespace std;

long solve(vector<int> calorie) {
    long ans=0;
    sort(calorie.begin(), calorie.end(), greater<int>());
    int s=calorie.size();
    for(int i=0; i<s; ++i){
        ans += (long)calorie[i] * pow(2,i);
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0; i<n; ++i)
        cin>>a[i];
    int ans=solve(a);
    cout<<ans<<"\n";
    return 0;
}

