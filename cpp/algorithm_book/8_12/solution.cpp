#include <iostream>
#include <vector>
#include <stdlib.h>

using namespace std;

int cache[101];
const int MOD = 1000000007;

int solution(int n) {
    int& ret = cache[n];
    if(ret != -1) return ret;

    if(n <= 1) return 1;

    return ret = (solution(n-1) + solution(n-2)) % MOD;
}

int asymmetric(int width) {
    if(width % 2 == 1)
        return (solution(width) - solution(width/2) + MOD) % MOD;
    int ret = solution(width);
    ret = (ret - solution(width/2) + MOD) % MOD;
    ret = (ret - solution(width/2-1) + MOD) % MOD;
    return ret;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int q;
    cin>>q;

    memset(cache, -1, sizeof(cache));
    while(q--) {
        int n;
        cin>>n;
        cout<<asymmetric(n)<<endl;
    }

    return 0;
}

