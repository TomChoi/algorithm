#include <iostream>
#include <vector>

using namespace std;

int solution(vector<int>& arr) {
    int ans=0;
    int sz = arr.size(); 
    for(int i=0; i<pow(2,sz); ++i) {
        for(int j=0; j<=sz; ++j) {
            if(j < sz) cout<<arr[j]<<" ";
            if(j == sz || (i >> j) & 1) {
                cout
        }
        cout<<endl;
    }
    cout<<endl;

    return ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin>>n;

    vector<int> arr(n);
    for(int i=0; i<n; ++i) {
        cin>>arr[i];
    }

    int ans = solution(arr);

    cout<<ans<<"\n";

    return 0;
}
        
