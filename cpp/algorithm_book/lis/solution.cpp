#include <iostream>
#include <vector>
#include <stdlib.h>

using namespace std;

int cache[30];
int choices[30];

int lis(vector<int>& arr, int start) {
    int& ret = cache[start];
    if(ret != -1) return ret;
    
    // because start always is selected
    int bestNext = -1;
    ret = 1;
    for(int i=start+1; i<arr.size(); ++i) {
        if(arr[start] < arr[i]) {
            int cand = lis(arr, i) + 1;
            if(ret < cand) {
                bestNext = i;
                ret = cand;
            }
        }
    }
    choices[start+1] = bestNext;
    return ret;
}

int lis3(vector<int>& arr, int start) {
    int& ret = cache[start+1];
    if(ret != -1) return ret;

    ret = 1;
    for(int i=start+1; i<arr.size(); ++i) {
        if(start == -1 || arr[start] < arr[i]) {
            ret = max(ret, lis3(arr, i) + 1);
        }
    }
    return ret;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin>>n;

    memset(cache, -1, sizeof(cache));
    vector<int> arr(n);
    for(int i=0; i<n; ++i) {
        cin>>arr[i];
    }

    // call lis function
    int ret=0; 
    for(int i=0; i<n; ++i) {
        ret = max(ret, lis(arr,i));
    }
    cout<<"answer of lis1: "<<ret<<endl;

    memset(cache, -1, sizeof(cache));
    // call lis3 function
    ret = lis3(arr, -1) - 1;
    cout<<"answer of lis3: "<<ret<<endl;

    return 0;
}

