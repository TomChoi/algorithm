#include <iostream>
#include <vector>
#include <stdlib.h>

using namespace std;

const int MAX = 2000000000 + 1;

int cache[501];
int selected[501];
int cacheCnt[501];

int lis(vector<int>& arr, int s) {
    int& ret = cache[s+1];
    if(ret != -1) return ret;
    
    if(s == arr.size()) return 0;

    ret = 1;
    for(int next=s+1; next<arr.size(); ++next) {
        if(s == -1 || arr[s] < arr[next]) {
            ret = max(ret, lis(arr, next) + 1);
        }
    }
    return ret; 
}

int count(vector<int>& arr, int s) {
    if(lis(arr, s) == 1) {
        if(s != -1)
            cacheCnt[s+1] = 1;
        return 1;
    }    
    int& ret = cacheCnt[s+1];
    if(ret != -1) return ret;

    ret = 0;
    for(int next = s+1; next < arr.size(); ++next) {
        if((s == -1 || arr[s] < arr[next]) && lis(arr, s) == lis(arr, next) + 1)
            ret = min<long long>(MAX, (long long)ret + count(arr, next));
    }
    return ret;
}

void reconstruct(vector<int>& arr, 

vector<int> solution(vector<int>& arr, int k) {
    vector<int> ret;
    int lisSize = lis(arr, -1) - 1;
    for(int i=0; i<9; ++i) {
        cout<<cache[i]<<" ";
    }
    cout<<endl;
    count(arr, -1);
    for(int i=0; i<9; ++i) {
        cout<<cacheCnt[i]<<" ";
    }
    cout<<endl;

    return ret;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int q;
    cin>>q;

    while(q--) {
        int n,k;
        cin>>n>>k;
        memset(cache, -1, sizeof(cache)); 
        memset(selected, -1, sizeof(selected));
        memset(cacheCnt, -1, sizeof(cacheCnt));
        vector<int> arr(n);
        for(int i=0; i<n; ++i) {
            cin>>arr[i];
        }
        vector<int> ret = solution(arr, k);
        for(int e: ret) {
            cout<<e<<" ";
        }
        cout<<"\n";
    }

    return 0;
}
