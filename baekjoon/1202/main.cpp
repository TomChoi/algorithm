#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int N,K;
vector<pair<int,int>> jam;
vector<int> bag;
priority_queue<int> q;

long long solution() {
    long long res=0;
    
    int idx=0;
    for (int i=0; i<K; ++i) {
        while (idx < N && bag[i] >= jam[idx].first) {
            q.push(jam[idx].second);
            idx++;
        }
        if (!q.empty()) {
            res += q.top();
            q.pop();
        }
    }
    
    return res;
}

int main(int argc, char* argv[]) {
    ios::sync_with_stdio();
    cin.tie(0);
    
    cin>>N>>K;
    for (int i=0; i<N; ++i) {
        int m,v;
        cin>>m>>v;
        jam.push_back({m,v});
    }
    
    for (int i=0; i<K; ++i) {
        int c;
        cin>>c;
        bag.push_back(c);
    }
    
    sort(jam.begin(), jam.end());
    sort(bag.begin(), bag.end());
    
    cout << solution() <<endl;
    
    return 0;
}

