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
        string p=s.substr(0,i);
        int c=1, res=sz;
        for(int j=i; j<=sz-i; j+=i) {
           	if(p==s.substr(j,i)) c++;
            else {
                if(c>1) {
                	res = res-(i*c)+i+1;
                }
            	p=s.substr(j,i);
            	c=1;
            }
        }
        if(c>1)
        	res = res-(i*c)+i+1;
        answer=std::min(answer, res);
    }
    return answer;
}
