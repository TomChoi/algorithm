#include <iostream>
#include <vector>
#include <string>

using namespace std;

int cache[1001][101];

int pack(int item, int capacity, vector<int>& weight, vector<int>& need) {
    int& ret = cache[capacity][item];
    if(ret != -1) return ret;

    if(item == weight.size()) return 0;

    ret = pack(item+1, capacity, weight, need);

    if(capacity >= weight[item]) {
        ret = max(ret, pack(item+1, capacity-weight[item], weight, need) + need[item]);
    }

    return ret;
}

vector<string> picked;
void reconstruct(int item, int capacity, vector<string>& name, vector<int>& weight, vector<int>& need) {
    if(item == name.size()) return;
    if(pack(item, capacity, weight, need) == pack(item+1, capacity, weight, need)) {
        reconstruct(item+1, capacity, name, weight, need);
    } else {
        picked.push_back(name[item]);
        reconstruct(item+1, capacity - weight[item], name, weight, need);
    }
    return;
}

void solution(int n, int capacity, vector<string>& name, vector<int>& weight, vector<int>& need) {
    int ret = pack(0, capacity, weight, need);
    reconstruct(0, capacity, name, weight, need);
    cout<<ret<<" "<<picked.size()<<endl;
    for(string s: picked) {
        cout<<s<<endl;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int q; // 0~50
    cin>>q;

    while(q--) {
        memset(cache, -1, sizeof(cache));
        int n,w; // n: 1~100, w: 1~1000
        cin>>n>>w;
         
        vector<string> name(n);
        vector<int> weight(n);
        vector<int> need(n);

        for(int i=0; i<n; ++i) {
            cin>>name[i]>>weight[i]>>need[i];
        }

        solution(n, w, name, weight, need);
    }

    return 0;
}
