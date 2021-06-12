#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class AB {
public:
    string createString(int N, int K) {
        string ans="";
        for(int i=0; i<N; ++i) {
            string arr(N, 'B');
            for(int j=0; j<i; ++j) {
                arr[j]='A';
            }
            do {
                int count=0;
                for(int j=0; j<N; ++j) {
                    if(arr[j] == 'A') {
                        for(int k=j+1; k<N; ++k) {
                            if(arr[k] == 'B') count++;
                        }
                    }
                }
                if (count == K) {
                    ans=arr;
                }
            } while(next_permutation(arr.begin(), arr.end()));
        }
            
        return ans;
    }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    AB ab;

    int N,K;
    cin>>N>>K;

    string ans = ab.createString(N, K);

    cout<<ans<<"\n";

    return 0;
}
