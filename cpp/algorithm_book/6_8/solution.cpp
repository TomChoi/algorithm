#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

#define INF 999999

const int SIZE=10;
const vector<vector<int>> switchTable = {{0,1,2}, {3,7,9,11}, {4,10,14,15}, {0,4,5,6,7}, 
{6,7,8,10,12}, {0,2,14,15}, {3,14,15}, {4,5,7,14,15}, {1,2,3,4,5}, {3,4,5,9,13}};

bool checkSuccess(vector<int>& clocks) {
    for(int i=0; i<clocks.size(); ++i) {
        if(clocks[i] != 12)
            return false;
    }
    return true;
}

void push(int idx, vector<int>& clocks) {
    for(int i: switchTable[idx]) {
        clocks[i] += 3;
        if(clocks[i] > 12) {
            clocks[i] %= 12;
        }
    }
}

int solution(vector<int>& clocks, int sw) {
    int ans = INF;

    if(sw == SIZE)
        return checkSuccess(clocks) ? 0 : INF;

    for (int i=0; i<4; ++i) {
        ans = min(ans, i+solution(clocks, sw+1));
        push(sw, clocks);
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int q;
    cin>>q;

    while(q--) {
        vector<int> clocks(16);
        for(int i=0; i<16; ++i) {
            cin>>clocks[i];
        }
        int ans = solution(clocks, 0);
        cout<<ans<<endl;
    }

    return 0;
}

