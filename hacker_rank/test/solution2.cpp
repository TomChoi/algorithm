#include <bits/stdc++.h>

using namespace std;

vector<long> solve(vector<int> numbers, vector<vector<int>> queries) {
    int qs=queries.size();
    vector<long> ans(qs,0);
    int sz=numbers.size();
    vector<long> nn(sz+1);
    vector<int> zn(sz+1);
    
    long sum=0,zc=0;
    for(int i=0; i<sz; ++i) {
        sum+=numbers[i];
        nn[i+1]=sum;
        if(numbers[i]==0) {
            zc++;
        }
        zn[i+1]=zc;
    }

    for(int j=0; j<qs; ++j) {
        vector<int>& q=queries[j];
        ans[j]+=nn[q[1]]-nn[q[0]-1];
        ans[j]+=(zn[q[1]]-zn[q[0]-1])*q[2];
    }

    return ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin>>n;
    vector<int> nums(n);
    for(int i=0; i<n; ++i)
        cin>>nums[i];

    int q, qn;
    cin>>q>>qn;
    vector<vector<int>> qs(q);
    for(int i=0; i<q; ++i) {
        qs[i].resize(qn);
        for(int j=0; j<qn; ++j) {
            cin>>qs[i][j];
        }
    }

    vector<long> ans=solve(nums, qs);
    for(long e: ans)
        cout<<e<<endl;

    return 0;
}


