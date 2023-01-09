#include <iostream>
#include <vector>

using namespace std;

int solution(vector<int>& h) {
    int ans = 0;
    vector<int> acc(h.size(), 0);

    for(int i=0; i<h.size(); ++i) {
        acc[i] = h[i];
        int left = i-1, right = i+1;
        while(left >= 0 && h[i] <= h[left]) {
            left--;
            acc[i] += h[i];
        }
        while(right < h.size() && h[i] <= h[right]) {
            right++;
            acc[i] += h[i];
        }
    }

    ans = *max_element(acc.begin(), acc.end());
    
    return ans;
}

int solution2(vector<int>& h, int l, int r) {
    int ans=0;

    if(l>=r) {
        return l;
    }

    int m = (l+r)/2;
    ans = max(solution2(h, l, m), solution2(h, m+1, r));
    
    int left = m, right = m+1;
    int height = min(h[left], h[right]);
    ans = max(ans, 2*height);

    while(left > l || right < r) {
        if(right < r && (left == l || h[left-1] < h[right+1])) {
            right++;
            height = min(height, h[right]);
        } else {
            left--;
            height = min(height, h[left]);
        }
        ans = max(ans, height * (right - left + 1));
    }

    return ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int q;
    cin>>q;

    while(q--) {
        int n;
        cin>>n;
        vector<int> h(n);
        for(int i=0; i<n; ++i) 
            cin>>h[i];

        cout<<"sol1: "<<solution(h)<<"\n";
        cout<<"sol2: "<<solution2(h, 0, n-1)<<"\n";
    }

    return 0;
}
