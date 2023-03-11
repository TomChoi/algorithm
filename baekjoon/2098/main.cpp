#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define maxN 16
#define INF 987654321

int N, END;
int adj[maxN][maxN];
int dp[maxN][1<<maxN];

int solution(int s, int visit) {
    if (visit == END) {
        if (adj[s][0] > 0) {
            return adj[s][0];
        }
        return INF;
    }
    
    if (dp[s][visit] != 0) return dp[s][visit];
    
    dp[s][visit] = INF;
    
    for (int i=0; i<N; ++i) {
        if (adj[s][i] <= 0 || (visit & (1<<i))) continue;
        
        int value = solution(i, visit | 1 << i) + adj[s][i];
        dp[s][visit] = min(value, dp[s][visit]);
    }
    
    return dp[s][visit];
}

int main(int argc, char* argv[]) {
    ios::sync_with_stdio();
    cin.tie(0);
    
    cin>>N;
    END = (1<<N)-1;
    
    for (int i=0; i<N; ++i) {
        for (int j=0; j<N; ++j) {
            cin>>adj[i][j];
        }
    }
    
    cout << solution(0, 1) <<endl;
    
    return 0;
}

