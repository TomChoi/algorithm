#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int>& A, int min, int max,  int s) {
    int ans=0;
    
    if(s == A.size()) {
        if(B.size() == 0) return 0;
    }

     
    ans += solution(A, B, s+1);
    ans += solution(A, B, s+1);

    return ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin>>n;

    vector<int> A(n);
    for(int i=0; i<n; ++i) {
        cin>>A[i];
    }
    sort(A.begin(), A.end());
    int ans = solution(A,A[0],A[0],0);
    cout<<ans<<"\n";

    return 0;
}
