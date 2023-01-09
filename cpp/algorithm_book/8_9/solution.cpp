#include <iostream>
#include <vector>
#include <algorithm>
#include <stdlib.h>

using namespace std;

#define INF 987654321

int cache[11][101];

int calculateError(vector<int>& arr, int start, int end) {
    int ret = 0;
    int sum = 0;
    for(int i=start; i<end; ++i) {
        sum += arr[i];
    }
    int level = round((float)sum/(end-start));
    for(int i=start; i<end; ++i) {
        ret += pow(level - arr[i], 2);
    }
    return ret;
}

int solution(vector<int>& arr,  int s, int start) {
    int& ret = cache[s][start];
    if(ret != -1) return ret;

    if(s == 1) {
        return calculateError(arr, start, arr.size());
    }

    ret = INF;
    for(int i=start+1; i<arr.size(); ++i) {
        ret = min(ret, calculateError(arr, start, i) + solution(arr, s-1, i));
    }

    return ret;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int q;
    cin>>q;
    while(q--) {
        int n, s;
        cin>>n>>s;
        vector<int> arr(n);
        memset(cache, -1, sizeof(cache));
        for(int i=0; i<n; ++i) {
            cin>>arr[i];
        }
        sort(arr.begin(), arr.end());
        cout<<endl<<solution(arr, s, 0)<<"\n";
    }
    return 0;
}
