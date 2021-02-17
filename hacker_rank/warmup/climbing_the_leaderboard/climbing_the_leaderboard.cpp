#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int mxN=INT_MAX;

vector<int> solve(vector<int> ranked, vector<int> player) {
    map<int, int> m;
    vector<int> ans(player.size());
    int s=ranked.size();
    int c=1;
    for(int i=0; i<s; ++i) {
        if(m.find(ranked[i]) == m.end()) {
            m[ranked[i]] = c;
            c++;
        }
    }
    s=player.size();
    for(int i=0; i<s; ++i) {
        auto it=m.lower_bound(player[i]);
        if (it->first == player[i]) {
            ans[i] = it->second;
        } else if (it == m.end()) {
            ans[i] = 1;
        } else {
            ans[i] = it->second + 1;
        }
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int nr, np;
    cin>>nr;
    vector<int> ar(nr);
    for(int i=0; i<nr; ++i) {
        int e;
        cin>>e;
        ar[i]=e;
    }

    cin>>np;
    vector<int> ap(np);
    for(int i=0; i<np; ++i) {
        int e;
        cin>>e;
        ap[i]=e;
    }

    vector<int> ans=solve(ar, ap);
    for(int e: ans) {
        cout<<e<<"\n";
    }

    return 0;
}
