#include <iostream>
#include <vector>
#include <string>

using namespace std;

typedef struct Point {
    int dy;
    int dx;
} Point;

const Point first[4]  = {{0,1},{0,1}, {1,0}, {1,0}};
const Point second[4] = {{1,0}, {1,1}, {1,1}, {1,-1}}; 

int solution(int row, int col, vector<string>& board) {
    int ans=0;

    bool success = true;
    int targetR, targetC;
    for(int r=0; r<row; ++r) {
        for(int c=0; c<col; ++c) {
            if(board[r][c] == '.') {
                targetR=r; targetC=c;
                success = false;
                break;
            }
        }
        if(!success)
            break;
    }
    
    if(success) {
        return 1;
    }

    int r=targetR, c=targetC;
    for(int i=0; i<4; ++i) {
        int firstR = r+first[i].dy;
        int firstC = c+first[i].dx;
        int secondR = r+second[i].dy;
        int secondC = c+second[i].dx;
        if((firstR >= 0 && firstR < row && firstC >=0 && firstC < col && board[firstR][firstC] == '.')
                && (secondR >= 0 && secondR < row && secondC >= 0 && secondC < col && board[secondR][secondC] ==
                    '.')) {
            board[r][c] = '#'; board[firstR][firstC] = '#'; board[secondR][secondC] = '#';
            ans += solution(row, col, board);
            board[r][c] = '.'; board[firstR][firstC] = '.'; board[secondR][secondC] = '.';
        }
    }

    return ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int q;
    cin>>q;

    while(q--) {
        int r,c;
        cin>>r>>c;

        vector<string> board(r);
        for(int row=0; row<r; ++row) {
            cin>>board[row];
        }
        
        int ans = solution(r, c, board);
        cout<<ans<<endl;
    }

    return 0;
}
