#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int N,M;
vector<int> d;
vector<vector<int>> v;

void solution() {
    vector<int> res;
    priority_queue<int> q;
    for (int i=1; i<=N; ++i) {
        if (d[i] == 0) {
            q.push(-i);
        }
    }
    
    for (int i=1; i<=N; ++i) {
        if (q.empty()) {
            cout << "Encounter Cycle" << endl;
            return;
        }
        
        int p = -q.top();
        q.pop();
        res.push_back(p);
        
        for (int t : v[p]) {
            d[t]--;
            if (d[t] == 0) q.push(-t);
        }
    }
    
    for(int n : res) {
        cout << n << " ";
    }
}

int main(int argc, char* argv[]) {
    ios::sync_with_stdio();
    cin.tie(0);
    
    cin>>N>>M;
    d.resize(N+1);
    v.resize(N+1);
    for (int i=0; i<M; ++i) {
        int a,b;
        cin>>a>>b;
        v[a].push_back(b);
        d[b]++;
    }
    
    solution();
    
    return 0;
}

