#include <iostream>
#include <vector>
#include <unordered_set>
#include <queue>

using namespace std;

long solve(int n, vector<vector<int>> astronaut) {
    long ans=0;
    vector<int> list(n);
    vector<long> size(n);

    for(int i=0; i<n; ++i){
        list[i]=i;
        size[i]=1;
    }
    
    function<int(int)> find = [&list] (int a) -> int{
        while(a != list[a]) a=list[a];
        return a;
    };

    function<bool(int,int)> same = [find] (int a, int b) -> bool {
        return find(a) == find(b);
    };

    function<int(int,int)> unite = [&list, &size, find] (int a, int b) {
        a=find(a);
        b=find(b);
        if(size[a]<size[b]) swap(a,b);
        list[b]=a;
        size[a]+=size[b];
        size[b]=0;
        return 0;
    };

    for(auto e: astronaut) {
        if(same(e[0],e[1])) continue;
        unite(e[0], e[1]);
    }
    
    long sum=0;
    for(int i=0; i<n; ++i) {
        ans += size[i]*sum;
        sum += size[i];
    }

    return ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,m;
    cin>>n>>m;

    vector<vector<int>> p(m);
    for(int i=0; i<m; ++i){
        p[i].resize(2);
        cin>>p[i][0]>>p[i][1];
    }
    long ans=solve(n, p);
    cout<<ans<<"\n";

    return 0;
}
