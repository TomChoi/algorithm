#include <iostream>
#include <queue>
#include <set>
#include <map>
#include <bits/stdc++.h>

using namespace std;

struct cmp {
    bool operator()(vector<int> a, vector<int> b) {
        return a[0]>b[0];
    }
};

int main() {
    vector<vector<int>> v = {{1,2}, {0,8}, {5,3}};
    priority_queue<vector<int>, vector<vector<int>>, cmp> q(v.begin(), v.end());
    set<vector<int>, cmp> s(v.begin(), v.end());

    cout<<"Priority Queue"<<endl;
    while(!q.empty()) {
        cout<<q.top()[0]<<" "<<q.top()[1]<<endl;
        q.pop();
    }

    cout<<endl<<"Set"<<endl;
    for(auto it=s.begin(); it != s.end(); ++it)
        cout<<(*it)[0]<<" "<<(*it)[1]<<endl;

    return 0;
}
