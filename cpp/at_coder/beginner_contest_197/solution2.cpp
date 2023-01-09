#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int H, W, X, Y;
    cin>>H>>W>>X>>Y;

    vector<string> S(H);
    for(int i=0; i<H; ++i) {
        cin>>S[i];
    }

    int count = 0;
    X--; Y--;
    if(S[X][Y] == '.') count++;
    
    int dx = X - 1, dy = Y;
    while(dx>=0) {
        if(S[dx][dy] == '#')
            break;
        count++;
        dx--; 
    }

    dx = X + 1, dy = Y;
    while(dx<H) {
        if(S[dx][dy] == '#')
            break;
        count++;
        dx++;
    }

    dy = Y - 1, dx = X;
    while(dy>=0) {
        if(S[dx][dy] == '#')
            break;
        count++;
        dy--;
    }

    dy = Y +1, dx = X;
    while(dy<W) {
        if(S[dx][dy] == '#')
            break;
        count++;
        dy++;
    }

    cout<<count<<"\n";

    return 0;
}
