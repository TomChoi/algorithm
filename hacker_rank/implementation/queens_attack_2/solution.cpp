#include <iostream>
#include <vector>
#include <map>
#include <set>

using namespace std;

int solve(int n, int k, int r_q, int c_q, vector<vector<int>> obstacles) {
    int ans=0;

    map<int, set<int>> m;
    for(auto e: obstacles)
        m[e[0]].insert(e[1]);

    auto it=m.upper_bound(r_q);
    auto itu=it, itd=it;
    int t=n,rt=n,lt=n;
    cout<<"it:"<<it->first<<" "<<*it->second.begin()<<endl;
    while(itu != m.end()) {
        if(!t && itu->second.find(c_q) != itu->second.end())
            t=itu->first;
        if(!rt && itu->second.find(itu->first - r_q + c_q) != itu->second.end())
            rt=itu->first;
        if(!lt && itu->second.find(c_q - itu->first + r_q) != itu->second.end())
            c=itu->first;
        if(t && rt && lt)
            break;
        itu++;
    }
    itd--;
    int l=0, r=0;
    if (itd->first == r_q){
        auto i=itd->second.upper_bound(c_q);
        if(i != itd->second.end()) r=*i;
        if(i != itd->second.begin()){
            i--;
            l=*i;
        }
    }
    cout<<"left: "<<l<<"\t right: "<<r<<endl;
    int b=0, rb=0, lb=0;
    while(itd != m.begin()) {
        itd--;
        cout<<"row: "<<itd->first<<"\t"<<*itd->second.begin()<<endl;
        if(!b && itd->second.find(c_q) != itd->second.end())
            b=itd->first;
        if(!rb && itd->second.find(c_q - r_q + itd->first) != itd->second.end())
            rb=itd->first;
        if(!lb && itd->second.find(c_q + r_q - itd->first) != itd->second.end())
            lb=itd->first;
        if(b && rb && lb)
            break;
    }

    ans += (t-b-1) + (r-l-1);
    int s=c_q > r_q ? r_q : c_q;
    ans += s-lb-1;
    s= n-c_q > r_q-1 ? r_q-1: n-c_q;
    ans += rb-s;

    return ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,k, rq, cq;
    cin>>n>>k>>rq>>cq;
    vector<vector<int>> o(k);
    for(int i=0; i<k; ++i) {
        o[i].resize(2);
        cin>>o[i][0]>>o[i][1];
    }

    int ans=solve(n, k, rq, cq, o);
    cout<<ans<<"\n";
    return 0;
}
