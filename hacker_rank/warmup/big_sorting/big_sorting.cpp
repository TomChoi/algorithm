#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

bool comp(string e1, string e2){
    int s1=e1.length();
    int s2=e2.length();

    if(s1==s2)
        return e1<e2;

    return s1<s2;
}


vector<string> solve(vector<string> unsorted) {
    sort(unsorted.begin(), unsorted.end(), comp);
    return unsorted;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin>>n;

    vector<string> st(n);
    for(int i=0; i<n; ++i) {
        cin>>st[i];
    }

    vector<string> ans=solve(st);
    for(int i=0; i<ans.size(); ++i) {
        cout<<ans[i]<<"\n";
    }

    return 0;
}
