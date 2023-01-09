#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

int cache[10002];

int checkLevel(string s) {
    char prev = s[0];
    bool check = true;
    for(int i=1; i<s.length(); ++i) {
        if(prev != s[i]) {
            check = false;
            break;
        }
    }
    if(check)
        return 1;
    
    check = true;
    char diff = s[1] - s[0];
    for(int i=2; i<s.length(); ++i) {
        if(s[i] - s[i-1] != diff) {
            check=false;
            break;
        }
    }
    if(check) {
        if(diff == 1) return 2;
        else return 5;
    }

    check = true;
    char even = s[0], odd = s[1];
    for(int i=2; i<s.length(); ++i) {
        if(i%2 == 0) {
            if(s[i] != even) {
               check = false;
               break;
            }
        }
        else {
            if(s[i] != odd) {
                check = false;
                break;
            }
        }
    }

    if(check) return 4;

    return 10;
}
#define INF 987654321

int solution(string& s, int start) {

    int& ret = cache[start];
    if(ret != -1) return ret;

    if(s.length() == start) return 0;

    ret = INF;
    for(int i=3; i<=5; ++i) {
        if(start + i <= s.length())
            ret = min(ret, checkLevel(s.substr(start, i)) + solution(s, start + i));
    }
    return ret;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int q;
    cin>>q;

    memset(cache, -1, sizeof(cache));

    while(q--) {
        string s;
        cin>>s;
        cout<<solution(s, 0)<<"\n";
    }
    return 0;
}
