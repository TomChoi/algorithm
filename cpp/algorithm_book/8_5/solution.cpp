#include <iostream>
#include <vector>

using namespace std;

void lis(vector<int>& A, vector<int>& B, int start) {
    B.push_back(A[start]);
    for(int i=start+1; i<A.size(); ++i) {
        if(A[start] < A[i]) {
            lis(A, B, start+1);
        }
    }
    return;     
}

int solution(vector<int>& A, vector<int>& B) {
    // 각각 lis를 구한다. 중복 없이
    // 중복을 제거한 두 lis의 합의 길이를 구한다.
    int ret = 0;
    for(int i=0; i<A.size(); ++i) {
        vector<int> A1;
        lis(A, A1, i);
        for(int j=0; j<B.size(); ++j) {
            vector<int> B1;
            lis(B, B1, j);
            int sum = A1.size() + B1.size();
            cout<<sum<<endl;
            for(int ai=0; ai<A1.size(); ++ai) {
                for(int bi=0; bi<B1.size(); ++bi) {
                    if(A1[ai] == B1[bi])
                        sum--;
                }
            }
            ret = max(ret, sum);
        }
    }
    return ret;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int q;
    cin>>q;

    while(q--) {
        int n, m;
        cin>>n>>m;

        vector<int> A(n);
        vector<int> B(m);

        for(int i=0; i<n; ++i) {
            cin>>A[i];
        }

        for(int i=0; i<m; ++i) {
            cin>>B[i];
        }

        cout<<solution(A,B)<<"\n";
    }

    return 0;
}
