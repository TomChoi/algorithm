#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define maxN 987654321

long long N, S;
vector<int> v;

int solution() {
    int res = maxN;
    long long sum = 0;
    
    int st=0, en=0;
    while(st <= en) {
        if (sum >= S) {
            res = min(res,en-st);
            sum -= v[st];
            st++;
        } else if (en >= N) {
            break;
        } else {
            sum += v[en];
            en++;
        }
    }
    
    if (res == maxN) return 0;
    else return res;
}

int main(int argc, char* argv[]) {
    ios::sync_with_stdio();
    cin.tie(0);
    
    cin >> N >> S;
    
    v.resize(N);
    for (int i=0; i<N; ++i) {
        cin>>v[i];
    }
    
    cout << solution() << endl;
    
    return 0;
}

