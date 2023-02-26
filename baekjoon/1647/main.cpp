#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> edge;
vector<int> parent;

int N,M;

int find(int a) {
    if (parent[a] == a) return a;
    else return parent[a] = find(parent[a]);
}

void merge(int a, int b) {
    a = find(a);
    b = find(b);
    
    if (b < a) parent[a] = b;
    else parent[b] = a;
}

int solution() {
    int res=0;
    
    int maxValue=0;
    for (vector<int> e : edge) {
        if (find(e[1]) != find(e[2])) {
            maxValue = max(maxValue, e[0]);
            res += e[0];
            merge(e[1], e[2]);
        }
    }
    
    return res - maxValue;
}

int main(int argc, char* argv[]) {
    ios::sync_with_stdio();
    cin.tie(0);
    
    cin>>N>>M;
    for (int i=0; i<M; ++i) {
        int a,b,c;
        cin>>a>>b>>c;
        edge.push_back({c,a,b});
    }
    
    sort(edge.begin(), edge.end());
    
    parent.resize(N+1);
    for (int i=1; i<N+1; ++i) {
        parent[i] = i;
    }
    
    cout << solution() << endl;
    
    return 0;
}

