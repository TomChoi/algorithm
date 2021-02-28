#include <iostream>
#include <vector>
#include <string>
#include <stack>

using namespace std;

int solve(string s) {
    int ans=0;
    
    stack<char> st;
    int sz=s.length();
    st.push(s[0]);
    for(int i=1; i<sz; ++i) {
        if(!st.empty() && st.top() == s[i]) {
            st.pop();
        } else {
            st.push(s[i]);
        }
    }
    if(st.empty())
        ans=1;

    return ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s;
    cin>>s;
    int ans=solve(s);
    cout<<ans<<"\n";

    return 0;
}
