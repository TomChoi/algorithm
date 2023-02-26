#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int V,E;
vector<vector<int>> edge;
vector<int> parent;

int find(int a) {
    if (parent[a] == a) return a;
    else return parent[a] = find(parent[a]);
}

void merge(int a, int b) {
    a = find(a);
    b = find(b);
    
    if (a < b) parent[b] = a;
    else parent[a] = b;
}

int solution() {
    int res=0;
    
    for (vector<int> e : edge) {
        if (find(e[1]) != find(e[2])) {
            res += e[0];
            merge(e[1], e[2]);
        }
    }
    
    return res;
}

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    
    cin>>V>>E;
    for (int i=0; i<E; ++i) {
        int a,b,c;
        cin>>a>>b>>c;
        edge.push_back({c,a,b});
    }
    sort(edge.begin(), edge.end());
    
    parent.resize(E+1);
    for (int i=1; i<E+1; ++i) {
        parent[i] = i;
    }
    
    cout<<solution()<<endl;
    
    return 0;
}

