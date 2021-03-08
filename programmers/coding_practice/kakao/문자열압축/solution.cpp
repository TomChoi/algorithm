#include <string>
#include <vector>
#include <limits.h>
#include <iostream>

using namespace std;

int solution(string s) {
    int answer = INT_MAX;
    int sz=s.length();
    int half=sz/2;
    for(int i=1; i<=half; ++i) {
        int res=sz, c=1;
        for(int j=0; j<=sz-i*2;) {
        	string p=s.substr(j,i);
            int k=0;
            for(k=j+i; k<sz; k+=i) {
                if(p==s.substr(k,i)) c++;
                else
                    break;
                p=s.substr(k,i);
            }
            if(c>1) {
                res = res-(i*c)+i+1;
                j=k;
            } else {
                j++;
            }
            c=1;
        }
        answer=std::min(answer, res);
    }
    return answer;
}
