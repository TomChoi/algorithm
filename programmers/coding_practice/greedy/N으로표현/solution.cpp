#include <string>
#include <vector>
#include <limits.h>
#include <stack>
#include <cmath>
#include <iostream>

int solve(int N, int number, std::stack<int> s, int c) {
    int ans=INT_MAX; 
   	if(c>8)
        return -1;
    
    // calculate sum 
    std::stack<int> t(s);
    int sum=0;
    while(!t.empty()) {
        std::cout<<t.top()<<" ";
        t.pop();
    }
    std::cout<<std::endl<<std::endl;
    if(sum==number)
        return c;
    
    for(int i=0; i<5; ++i) {
        std::stack<int> st(s);
       	if(i==0) {
            int n=st.top(); st.pop();
            st.push(n*10+N);
        } else if(i==1) {
            st.push('+');
            st.push(N);
        } else if(i==2) {
            st.push('-');
            st.push(N);
        } else if(i==3) {
            int n=st.top(); st.pop();
            st.push(n/N);
            //std::cout<<n/N<<std::endl;
        } else {
            int n=st.top(); st.pop();
            st.push(n*N);
            //std::cout<<n*N<<std::endl;
        }
        int res=solve(N,number,st,c+1);
        if(res != -1) {
            ans=std::min(ans, res);
        }
    }
    if(ans==INT_MAX)
        return -1;
    return ans;
}

int solution(int N, int number) {
    int answer = 0;
    std::stack<int> s;
    s.push(N);
   	answer=solve(N,number,s,1);
    return answer;
}

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    int ans=solution(2, 11);
    std::cout<<ans<<std::endl;
    return 0;
}
