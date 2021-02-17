#include <bits/stdc++.h>
using namespace std;

vector<int> solve(vector<int> grades) {
    int s=grades.size();
    vector<int> ans(s);

    for(int i=0; i<s; ++i) {
        if(grades[i]>=38 && grades[i]%5 >= 3) 
            ans[i]=grades[i] + (5-grades[i]%5);
        else
            ans[i]=grades[i];
    }

    return ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin>>n;

    vector<int> arr(n);
    for(int i=0; i<n; ++i)
        cin>>arr[i];

    vector<int> ans=solve(arr);
    for(int i=0; i<n; ++i)
        cout<<ans[i]<<"\n";

    return 0;
}
