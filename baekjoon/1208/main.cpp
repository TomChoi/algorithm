#include <iostream>
#include <vector>
#include <map>

using namespace std;

#define maxN 40

int N, S;
int v[maxN];
long long ans;
map<int, int> mp;

void left(int i, int sum) {
    if (i == N/2) {
        mp[sum]++;
        return;
    }
    left(i+1, sum);
    left(i+1, sum+v[i]);
}

void right(int i, int sum) {
    if (i == N) {
        ans += mp[S-sum];
        return;
    }
    right(i+1, sum);
    right(i+1, sum+v[i]);
}

long long solution() {
          
    left(0,0);
    right(N/2, 0);
    if (S == 0) ans--;
    return ans;
}

int main(int argc, char* argv[]) {
    ios::sync_with_stdio();
    cin.tie(0);
    
    cin >> N >> S;
    for (int i=0; i<N; ++i) {
        cin>>v[i];
    }
    
    cout << solution() << endl;
    
    return 0;
}

